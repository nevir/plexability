import os

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..'))

EXTERN_PATH = os.path.join(PROJECT_ROOT, 'extern')
CHROMIUM_ROOT = os.path.join(EXTERN_PATH, 'chromium')
DEPOT_TOOLS_PATH = os.path.join(EXTERN_PATH, 'depot_tools')
CEF_PATH = os.path.join(CHROMIUM_ROOT, 'src', 'cef')

GCLIENT_RUNNER = os.path.join(DEPOT_TOOLS_PATH, 'gclient.py')
