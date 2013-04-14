#!/usr/bin/env python

# CEF/Chromium Build
# ==================

# We have a slightly modified build of CEF/Chromium for a few things:
#
# * A GPL-compatible build of ffmpeg (for h.264/etc support)
#
# * The ability to place build artifacts in an organization that makes sense for
#   this project.
#
# As such, we need to layer a little bit of extra behavior on top of `gclient`.
import os
import subprocess
import sys

sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))
from tools import cef, layout, svn


# Getting The Code
# ----------------
def sync_chromium():
    # The Chromium source tree, and its depedencies are _not_ included in our repo
    # due to their sheer size.  To pull them down (or update your existing copy):
    #
    # python extern/chromium/sync.py
    #
    # This will pull down the chromium version targeted by CEF, and ensure that
    # it is ready to build.
    os.chdir(layout.CHROMIUM_ROOT + '/src')
    print("In dir: %s" % layout.CHROMIUM_ROOT)

    run_command('svn', 'checkout', '--ignore-externals', cef.desired_chromium_svn_url(), 'src')

    # Prefer a ninja build.
    os.environ['GYP_GENERATORS'] = 'ninja'
    run_command('python', layout.GCLIENT_RUNNER, 'sync')


def run_command(*args):
    print("Running command: %s" % " ".join(args))
    subprocess.call(args)


if __name__ == "__main__":
    svn.assert_version(1.5)

    sync_chromium()