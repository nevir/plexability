#ifndef chromium_render_process_handler_h
#define chromium_render_process_handler_h

#include "include/cef_render_process_handler.h"

class ChromiumRenderProcessHandler : public CefRenderProcessHandler {
public:

  ChromiumRenderProcessHandler();

  // CEF Interface
  // =============
  void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info);
  void OnWebKitInitialized();
  void OnBrowserCreated(CefRefPtr<CefBrowser> browser);
  void OnBrowserDestroyed(CefRefPtr<CefBrowser> browser);
  bool OnBeforeNavigation(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request, NavigationType navigation_type, bool is_redirect);
  void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context);
  void OnContextReleased(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context);
  void OnUncaughtException(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context, CefRefPtr<CefV8Exception> exception, CefRefPtr<CefV8StackTrace> stackTrace);
  void OnWorkerContextCreated(int worker_id, const CefString& url, CefRefPtr<CefV8Context> context);
  void OnWorkerContextReleased(int worker_id, const CefString& url, CefRefPtr<CefV8Context> context);
  void OnWorkerUncaughtException(int worker_id, const CefString& url, CefRefPtr<CefV8Context> context, CefRefPtr<CefV8Exception> exception, CefRefPtr<CefV8StackTrace> stackTrace);
  void OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefDOMNode> node);
  bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message);

private:
  IMPLEMENT_REFCOUNTING(ChromiumRenderProcessHandler);
};

#endif
