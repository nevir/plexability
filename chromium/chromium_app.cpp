#include "chromium_app.h"

ChromiumApp::ChromiumApp()
{
  TRACE();

  this->resourceBundleHandler = new ChromiumResourceBundleHandler;
  this->browserProcessHandler = new ChromiumBrowserProcessHandler;
  this->renderProcessHandler  = new ChromiumRenderProcessHandler;
}

// CEF Interface
// =============

// Provides an opportunity to view and/or modify command-line arguments before
// processing by CEF and Chromium. The |process_type| value will be empty for
// the browser process. Do not keep a reference to the CefCommandLine object
// passed to this method. The CefSettings.command_line_args_disabled value
// can be used to start with an empty command-line object. Any values
// specified in CefSettings that equate to command-line arguments will be set
// before this method is called. Be cautious when using this method to modify
// command-line arguments for non-browser processes as this may result in
// undefined behavior including crashes.
void ChromiumApp::OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
  TRACE();
}

// Provides an opportunity to register custom schemes. Do not keep a reference
// to the |registrar| object. This method is called on the main thread for
// each process and the registered schemes should be the same across all
// processes.
void ChromiumApp::OnRegisterCustomSchemes(CefRefPtr<CefSchemeRegistrar> registrar)
{
  TRACE();
}

// Return the handler for resource bundle events. If
// CefSettings.pack_loading_disabled is true a handler must be returned. If no
// handler is returned resources will be loaded from pack files. This method
// is called by the browser and render processes on multiple threads.
CefRefPtr<CefResourceBundleHandler> ChromiumApp::GetResourceBundleHandler()
{
  return (CefRefPtr<CefResourceBundleHandler>)this->resourceBundleHandler;
}

// Return the handler for functionality specific to the browser process. This
// method is called on multiple threads in the browser process.
CefRefPtr<CefBrowserProcessHandler> ChromiumApp::GetBrowserProcessHandler()
{
  return (CefRefPtr<CefBrowserProcessHandler>)this->browserProcessHandler;
}

// Return the handler for functionality specific to the render process. This
// method is called on the render process main thread.
CefRefPtr<CefRenderProcessHandler> ChromiumApp::GetRenderProcessHandler()
{
  return (CefRefPtr<CefRenderProcessHandler>)this->renderProcessHandler;
}
