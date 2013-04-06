#ifndef plexability_app_h
#define plexability_app_h

#include "chromium_app.h"
#include "chromium_client.h"

class PlexabilityApp {
public:

  // Lifecycle
  // =========
  PlexabilityApp(int argc, char* argv[]);

  // Blocks until the app has completed, and returns the exit code.
  //
  // **NOTE:** This sets up and manages the main run loop.  Don't set up a
  // platform specific run loop!  I got this.
  int run();


  // Browser Management
  // ==================

  // Builds a new browser instance for the given window.
  //
  // Returns the client abstraction associated with that browser, or NULL on failure.
  CefRefPtr<ChromiumClient> createBrowserAsync(const CefWindowInfo& windowInfo, const CefString& url, const CefBrowserSettings& settings);


  // Abstract Interface
  // ==================
private:
  // Called prior to running the (main) application process.  Set up your GUI and all its friends
  // here.
  virtual void initializeNativeApp() = 0;


  // State
  // =====
  CefMainArgs args;
  CefSettings chromiumSettings;
  CefRefPtr<ChromiumApp> chromiumApp;
};

#endif
