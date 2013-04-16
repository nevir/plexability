# GClient Envrionment
# ===================

# We can rely on `gclient_utils` always being on the load path because we are
# `exec`'d from within `gclient`.
import gclient_utils
# So we use that to find our own `tools` and get them on the load path.
import sys
import os
sys.path.insert(0, gclient_utils.FindGclientRoot(os.getcwd()))
from tools import cef


# Actual Gclient Solution
# =======================
solutions = [
    {
        'name': 'src',
        'url': cef.desired_chromium_svn_url(),
        'custom_deps': {
            # Things we don't need.  Faster download!
            'src/chrome/installer/mac/third_party/xz/xz': None,
            'src/chrome/test/data/extensions/api_test/permissions/nacl_enabled/bin': None,
            'src/chrome/test/data/perf/canvas_bench': None,
            'src/chrome/test/data/perf/frame_rate/content': None,
            'src/chrome/test/data/perf/third_party/octane': None,
            'src/chrome/tools/test/reference_build/chrome_win': None,
            'src/chrome/tools/test/reference_build/chrome_mac': None,
            'src/chrome/tools/test/reference_build/chrome_linux': None,
            'src/chrome_frame/tools/test/reference_build/chrome_win': None,
            'src/third_party/WebKit/LayoutTests': None,
        },
    }
]
