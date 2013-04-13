from os import path

PROJECT_PATH = path.abspath(path.join(path.dirname(__file__), ".."))
EXTERN_PATH = path.join(PROJECT_PATH, 'extern')
GCLIENT_ROOT = path.join(EXTERN_PATH, 'chromium')

DEPOT_TOOLS_REPO = {
    'repo_url': 'http://src.chromium.org/svn/trunk/tools/depot_tools',
    'dest_path': path.join(EXTERN_PATH, 'depot_tools'),
    # depot_tools should always be up to date.  It auto-updates its self, too.
    'revision': None,
}

CEF_REPO = {
    'repo_url': 'http://chromiumembedded.googlecode.com/svn/trunk/cef3',
    'dest_path': path.join(GCLIENT_ROOT, 'src', 'cef'),
    'revision': None,
}

CHROMIUM_REPO = {
    'repo_url': 'http://src.chromium.org/svn/trunk/src',
    'dest_path': path.join(GCLIENT_ROOT, 'src'),
    'revision': '__derived_from_cef__',
    'extra_options': [
        '--ignore-externals',
    ],
}
