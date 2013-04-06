#ifndef chromium_app_h
#define chromium_app_h

#include "include/cef_app.h"

#include "chromium_resource_bundle_handler.h"
#include "chromium_browser_process_handler.h"
#include "chromium_render_process_handler.h"

class ChromiumApp : public CefApp {
public:

  ChromiumApp();

  // CEF Interface
  // =============
  void OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line);
  void OnRegisterCustomSchemes(CefRefPtr<CefSchemeRegistrar> registrar);

  CefRefPtr<CefResourceBundleHandler> GetResourceBundleHandler();
  CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler();
  CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler();

private:

  CefRefPtr<ChromiumResourceBundleHandler> resourceBundleHandler;
  CefRefPtr<ChromiumBrowserProcessHandler> browserProcessHandler;
  CefRefPtr<ChromiumRenderProcessHandler>  renderProcessHandler;

  IMPLEMENT_REFCOUNTING(ChromiumApp);
};

#endif
