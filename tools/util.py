import os
import subprocess
import sys
import traceback

from . import config


def run_command(args):
    print("Running command: %s" % " ".join(args))
    subprocess.call(args)


def check_svn_version():
    command = ("svn", "--version", "--quiet")
    process = subprocess.Popen(command, stdout=subprocess.PIPE)
    output, error = process.communicate()
    if error:
        return None

    return output.strip()


def sync_svn_repo(repo_info):
    repo_url = svn_repo_url(repo_info)
    dest_path = repo_info["dest_path"]
    extra_options = repo_info.get("extra_options", [])

    args = ["svn", "checkout"]

    if extra_options:
        args.extend(extra_options)

    args.extend((repo_url, dest_path))
    run_command(args)


def svn_repo_url(repo_info):
    revision = repo_info.get("revision", None)

    # Crazy special case; whatever.
    if revision == '__derived_from_cef__':
        revision = derive_chromium_revision()

    if revision:
        return "%s@%s" % (repo_info["repo_url"], revision)
    else:
        return repo_info["repo_url"]


def derive_chromium_revision():
    build_compat_path = os.path.join(config.CEF_REPO["dest_path"], "CHROMIUM_BUILD_COMPATIBILITY.txt")

    try:
        content = open(build_compat_path).read()
    except IOError:
        print("Expected %s to exist (used to determine chromium revision)" % build_compat_path)
        sys.exit(127)

    try:
        info = eval(content)
    except:
        traceback.print_exc()
        print("Failed to parse %s for chromium revision info." % build_compat_path)
        sys.exit(127)

    if not type(info) == dict or not "chromium_revision" in info:
        print("Expected %s define a dictionary with 'chromium_revision' defined.  Got %r" % (build_compat_path, info))
        sys.exit(127)

    return eval(info["chromium_revision"])
