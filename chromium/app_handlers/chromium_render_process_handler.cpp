#include "chromium_render_process_handler.h"

ChromiumRenderProcessHandler::ChromiumRenderProcessHandler()
{
  TRACE();
}

// CEF Interface
// =============
// Called after the render process main thread has been created. |extra_info|
// is a read-only value originating from
// CefBrowserProcessHandler::OnRenderProcessThreadCreated(). Do not keep a
// reference to |extra_info| outside of this method.
void ChromiumRenderProcessHandler::OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info)
{
  TRACE();
}

// Called after WebKit has been initialized.
void ChromiumRenderProcessHandler::OnWebKitInitialized()
{
  TRACE();
}

// Called after a browser has been created. When browsing cross-origin a new
// browser will be created before the old browser with the same identifier is
// destroyed.
void ChromiumRenderProcessHandler::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
{
  TRACE();
}

// Called before a browser is destroyed.
void ChromiumRenderProcessHandler::OnBrowserDestroyed(CefRefPtr<CefBrowser> browser)
{
  TRACE();
}

// Called before browser navigation. Return true to cancel the navigation or
// false to allow the navigation to proceed. The |request| object cannot be
// modified in this callback.
bool ChromiumRenderProcessHandler::OnBeforeNavigation(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request, NavigationType navigation_type, bool is_redirect)
{
  TRACE();

  return false;
}

// Called immediately after the V8 context for a frame has been created. To
// retrieve the JavaScript 'window' object use the CefV8Context::GetGlobal()
// method. V8 handles can only be accessed from the thread on which they are
// created. A task runner for posting tasks on the associated thread can be
// retrieved via the CefV8Context::GetTaskRunner() method.
void ChromiumRenderProcessHandler::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
  TRACE();
}

// Called immediately before the V8 context for a frame is released. No
// references to the context should be kept after this method is called.
void ChromiumRenderProcessHandler::OnContextReleased(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
  TRACE();
}

// Called for global uncaught exceptions in a frame. Execution of this
// callback is disabled by default. To enable set
// CefSettings.uncaught_exception_stack_size > 0.
void ChromiumRenderProcessHandler::OnUncaughtException(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context, CefRefPtr<CefV8Exception> exception, CefRefPtr<CefV8StackTrace> stackTrace)
{
  TRACE();
}

// Called on the WebWorker thread immediately after the V8 context for a new
// WebWorker has been created. To retrieve the JavaScript 'self' object use
// the CefV8Context::GetGlobal() method. V8 handles can only be accessed from
// the thread on which they are created. A task runner for posting tasks on
// the associated thread can be retrieved via the
// CefV8Context::GetTaskRunner() method.
void ChromiumRenderProcessHandler::OnWorkerContextCreated(int worker_id, const CefString& url, CefRefPtr<CefV8Context> context)
{
  TRACE();
}

// Called on the WebWorker thread immediately before the V8 context for a
// WebWorker is released. No references to the context should be kept after
// this method is called. Any tasks posted or pending on the WebWorker
// thread after this method is called may not be executed.
void ChromiumRenderProcessHandler::OnWorkerContextReleased(int worker_id, const CefString& url, CefRefPtr<CefV8Context> context)
{
  TRACE();
}

// Called on the WebWorker thread for global uncaught exceptions in a
// WebWorker. Execution of this callback is disabled by default. To enable set
// CefSettings.uncaught_exception_stack_size > 0.
void ChromiumRenderProcessHandler::OnWorkerUncaughtException(int worker_id, const CefString& url, CefRefPtr<CefV8Context> context, CefRefPtr<CefV8Exception> exception, CefRefPtr<CefV8StackTrace> stackTrace)
{
  TRACE();
}

// Called when a new node in the the browser gets focus. The |node| value may
// be empty if no specific node has gained focus. The node object passed to
// this method represents a snapshot of the DOM at the time this method is
// executed. DOM objects are only valid for the scope of this method. Do not
// keep references to or attempt to access any DOM objects outside the scope
// of this method.
void ChromiumRenderProcessHandler::OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefDOMNode> node)
{
  TRACE();
}

// Called when a new message is received from a different process. Return true
// if the message was handled or false otherwise. Do not keep a reference to
// or attempt to access the message outside of this callback.
bool ChromiumRenderProcessHandler::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
  TRACE();

  return false;
}
