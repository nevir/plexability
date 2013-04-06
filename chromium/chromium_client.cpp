#include "chromium_client.h"

ChromiumClient::ChromiumClient()
{
  TRACE();
}

// CEF Interface
// =============
// Return the handler for context menus. If no handler is provided the default
// implementation will be used.
CefRefPtr<CefContextMenuHandler> ChromiumClient::GetContextMenuHandler()
{
  return NULL;
}

// Return the handler for dialogs. If no handler is provided the default
// implementation will be used.
CefRefPtr<CefDialogHandler> ChromiumClient::GetDialogHandler()
{
  return NULL;
}

// Return the handler for browser display state events.
CefRefPtr<CefDisplayHandler> ChromiumClient::GetDisplayHandler()
{
  return NULL;
}

// Return the handler for download events. If no handler is returned downloads
// will not be allowed.
CefRefPtr<CefDownloadHandler> ChromiumClient::GetDownloadHandler()
{
  return NULL;
}

// Return the handler for focus events.
CefRefPtr<CefFocusHandler> ChromiumClient::GetFocusHandler()
{
  return NULL;
}

// Return the handler for geolocation permissions requests. If no handler is
// provided geolocation access will be denied by default.
CefRefPtr<CefGeolocationHandler> ChromiumClient::GetGeolocationHandler()
{
  return NULL;
}

// Return the handler for JavaScript dialogs. If no handler is provided the
// default implementation will be used.
CefRefPtr<CefJSDialogHandler> ChromiumClient::GetJSDialogHandler()
{
  return NULL;
}

// Return the handler for keyboard events.
CefRefPtr<CefKeyboardHandler> ChromiumClient::GetKeyboardHandler()
{
  return NULL;
}

// Return the handler for browser life span events.
CefRefPtr<CefLifeSpanHandler> ChromiumClient::GetLifeSpanHandler()
{
  return NULL;
}

// Return the handler for browser load status events.
CefRefPtr<CefLoadHandler> ChromiumClient::GetLoadHandler()
{
  return NULL;
}

// Return the handler for off-screen rendering events.
CefRefPtr<CefRenderHandler> ChromiumClient::GetRenderHandler()
{
  return NULL;
}

// Return the handler for browser request events.
CefRefPtr<CefRequestHandler> ChromiumClient::GetRequestHandler()
{
  return NULL;
}

// Called when a new message is received from a different process. Return true
// if the message was handled or false otherwise. Do not keep a reference to
// or attempt to access the message outside of this callback.
bool  ChromiumClient::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
  TRACE();

  return false;
}
