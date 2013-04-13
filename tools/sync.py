from os import chdir, environ, path
from sys import exit
import re

from . import config, util


def sync_repos():
    util.sync_svn_repo(config.DEPOT_TOOLS_REPO)
    util.sync_svn_repo(config.CEF_REPO)
    util.sync_svn_repo(config.CHROMIUM_REPO)
    sync_chromium_gclient()


def sync_chromium_gclient():
    gclient_path = path.join(config.DEPOT_TOOLS_REPO['dest_path'], 'gclient')

    environ['PLEXABILITY_ROOT'] = config.PROJECT_PATH
    chdir(config.GCLIENT_ROOT)
    util.run_command([gclient_path, 'sync'])


def assert_svn_version(version):
    svn_version = util.check_svn_version()
    if svn_version:
        short_match = re.match("^\d+\.\d+", svn_version)

    if not svn_version or not short_match:
        print("You do not appear to have svn installed.  Please install svn 1.6+")
        exit(127)

    if float(short_match.group(0)) < version:
        print("svn 1.6+ is required, you have %s installed." % svn_version)
        exit(127)


if __name__ == "__main__":
    assert_svn_version(1.6)

    sync_repos()
