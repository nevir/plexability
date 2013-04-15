import re
import subprocess
import sys
import xml.etree.ElementTree


def check_version():
    command = ("svn", "--version", "--quiet")
    process = subprocess.Popen(command, stdout=subprocess.PIPE)
    output, error = process.communicate()
    if error:
        return None
    return output.strip()


# We cheat and assume that we're dealing with versions that don't go to `#.10+`.
def assert_version(target_version):
    svn_version = check_version()
    if svn_version:
        short_match = re.match("^\d+\.\d+", svn_version)

    if not svn_version or not short_match:
        print("You do not appear to have svn installed.  Please install svn %s+" % target_version)
        sys.exit(127)

    if float(short_match.group(0)) < target_version:
        print("svn %s+ is required, you have %s installed." % (target_version, svn_version))
        sys.exit(127)


def local_repo_url(path):
    command = ("svn", "info", "--xml", path)
    process = subprocess.Popen(command, stdout=subprocess.PIPE)
    output, error = process.communicate()
    if error:
        return None

    root = xml.etree.ElementTree.fromstring(output)
    url = root.find("entry/url").text
    rev = root.find("entry[@revision]").attrib["revision"]

    return "%s@%s" % (url, rev)
