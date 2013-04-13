# GClient Environment
# ===================
from os import environ, path
import sys

if not 'PLEXABILITY_ROOT' in environ:
    print("Please run python -m tools.sync from the plexability project root, or set the PLEXABILITY_ROOT envionment variable.")
    sys.exit(127)

sys.path.insert(0, path.join(environ['PLEXABILITY_ROOT']))
from tools import config, util

sys.path.insert(0, config.DEPOT_TOOLS_REPO['dest_path'])
import gclient


gclient_root = path.join(config.EXTERN_PATH, 'chromium')
chromium_url = util.svn_repo_url(config.CHROMIUM_REPO)
chromium_deps_file = path.join(config.CHROMIUM_REPO['dest_path'], 'DEPS')

# To avoid infinite recursion, we stub out a gclient
client_opts = type('StubbedOptions', (object,), {'deps_os': None})()
client = gclient.GClient(gclient_root, client_opts)
# parent, name, url, safesync_url, managed, custom_deps, custom_vars, deps_file, should_process
root_deps = gclient.Dependency(client, 'src', chromium_url, None, True, None, None, chromium_deps_file, False)
root_deps.ParseDepsFile()


# Dependency Filtering
# ====================
# prefixes
DEPS_BLACKLIST = (
    'src/breakpad/',
    'src/chrome/',
    'src/content/test/',
    'src/third_party/WebKit/LayoutTests',
    'src/third_party/WebKit/Tools/',
    'src/tools/deps2git',  # We don't support git checkouts for now.
    'src/tools/swarm_client',  # Not running against Swarm.
)

# There are plenty of gclient depdendencies that we do not require for a build
# of CEF.  Cut them out for a faster checkout.
deps_to_skip = {}
for dep in root_deps.dependencies:
    for prefix in DEPS_BLACKLIST:
        if dep.name.startswith(prefix):
            deps_to_skip[dep.name] = None
            break


# Actual Gclient Solution
# =======================
solutions = [
    {
        'name': 'src',
        'url': chromium_url,
        'custom_deps': deps_to_skip,
    }
]
