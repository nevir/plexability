#ifndef chromium_browser_process_handler_h
#define chromium_browser_process_handler_h

#include "include/cef_browser_process_handler.h"

class ChromiumBrowserProcessHandler : public CefBrowserProcessHandler {
public:

  ChromiumBrowserProcessHandler();

  // CEF Interface
  // =============
  void OnContextInitialized();
  void OnBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> command_line);
  void OnRenderProcessThreadCreated(CefRefPtr<CefListValue> extra_info);

private:
  IMPLEMENT_REFCOUNTING(ChromiumBrowserProcessHandler);
};

#endif
