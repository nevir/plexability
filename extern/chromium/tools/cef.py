import os
import sys
import traceback

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src', 'cef'))


def desired_chromium_svn_url():
    build_compat_path = os.path.join(ROOT, "CHROMIUM_BUILD_COMPATIBILITY.txt")

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

    if not type(info) == dict or not "chromium_url" in info or not "chromium_revision" in info:
        print("Expected %s define a dictionary with 'chromium_url' and 'chromium_revision' defined.  Got %r" %
              (build_compat_path, info))
        sys.exit(127)

    return "%s@%s" % (info["chromium_url"], info["chromium_revision"])
