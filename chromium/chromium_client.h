#ifndef chromium_client_h
#define chromium_client_h

#include "include/cef_client.h"

class ChromiumClient : public CefClient {
public:

  ChromiumClient();

  // CEF Interface
  // =============
  // Return the handler for context menus. If no handler is provided the default
  // implementation will be used.
  CefRefPtr<CefContextMenuHandler> GetContextMenuHandler();

  // Return the handler for dialogs. If no handler is provided the default
  // implementation will be used.
  CefRefPtr<CefDialogHandler> GetDialogHandler();

  // Return the handler for browser display state events.
  CefRefPtr<CefDisplayHandler> GetDisplayHandler();

  // Return the handler for download events. If no handler is returned downloads
  // will not be allowed.
  CefRefPtr<CefDownloadHandler> GetDownloadHandler();

  // Return the handler for focus events.
  CefRefPtr<CefFocusHandler> GetFocusHandler();

  // Return the handler for geolocation permissions requests. If no handler is
  // provided geolocation access will be denied by default.
  CefRefPtr<CefGeolocationHandler> GetGeolocationHandler();

  // Return the handler for JavaScript dialogs. If no handler is provided the
  // default implementation will be used.
  CefRefPtr<CefJSDialogHandler> GetJSDialogHandler();

  // Return the handler for keyboard events.
  CefRefPtr<CefKeyboardHandler> GetKeyboardHandler();

  // Return the handler for browser life span events.
  CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler();

  // Return the handler for browser load status events.
  CefRefPtr<CefLoadHandler> GetLoadHandler();

  // Return the handler for off-screen rendering events.
  CefRefPtr<CefRenderHandler> GetRenderHandler();

  // Return the handler for browser request events.
  CefRefPtr<CefRequestHandler> GetRequestHandler();

  // Called when a new message is received from a different process. Return true
  // if the message was handled or false otherwise. Do not keep a reference to
  // or attempt to access the message outside of this callback.
  bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message);

private:
  IMPLEMENT_REFCOUNTING(ChromiumClient);
};

#endif
