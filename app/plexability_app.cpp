#include "plexability_app.h"

#pragma mark - Lifecycle

PlexabilityApp::PlexabilityApp(int argc, char* argv[]) : args(argc, argv)
{
  TRACE();

  for (int i = 0; i < argc; i++)
  {
    LOG("CLI Arg %i: %s", i, argv[i]);
  }

  this->chromiumApp = new ChromiumApp;
}

int PlexabilityApp::run() {
  TRACE();

  // First up; we see if we're running as a child process (in which case, CEF takes care of business
  // for us in a blocking manner).
  int exitCode = CefExecuteProcess(this->args, (CefRefPtr<CefApp>)this->chromiumApp);
  if (exitCode >= 0)
  {
    LOG("Ran as a child process.  Exited with: %d", exitCode);
    return exitCode;
  }

  // Nope; we're the master process.  Initialize CEF.
  if (!CefInitialize(this->args, this->chromiumSettings, (CefRefPtr<CefApp>)this->chromiumApp))
  {
    LOG("CEF failed to initialize!  Aborting.");
    return 127;
  }

  // Set up the platform-specific GUI and friends.
  this->initializeNativeApp();

  // And then kick off the run loop (this blocks until the app is ready to exit)
  CefRunMessageLoop();

  return 0;
}


#pragma mark - Browser Management

CefRefPtr<ChromiumClient> PlexabilityApp::createBrowserAsync(const CefWindowInfo& windowInfo, const CefString& url, const CefBrowserSettings& settings)
{
  TRACE();

  CefRefPtr<ChromiumClient> newClient = new ChromiumClient;

  CefBrowserHost::CreateBrowser(windowInfo, (CefRefPtr<CefClient>)newClient, url, settings);

  return newClient;
}