#include "chromium_browser_process_handler.h"

ChromiumBrowserProcessHandler::ChromiumBrowserProcessHandler()
{
  TRACE();
}

// CEF Interface
// =============
// Called on the browser process UI thread immediately after the CEF context
// has been initialized.
void ChromiumBrowserProcessHandler::OnContextInitialized()
{
  TRACE();
}

// Called before a child process is launched. Will be called on the browser
// process UI thread when launching a render process and on the browser
// process IO thread when launching a GPU or plugin process. Provides an
// opportunity to modify the child process command line. Do not keep a
// reference to |command_line| outside of this method.
void ChromiumBrowserProcessHandler::OnBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> command_line)
{
  TRACE();
}

// Called on the browser process IO thread after the main thread has been
// created for a new render process. Provides an opportunity to specify extra
// information that will be passed to
// CefRenderProcessHandler::OnRenderThreadCreated() in the render process. Do
// not keep a reference to |extra_info| outside of this method.
void ChromiumBrowserProcessHandler::OnRenderProcessThreadCreated(CefRefPtr<CefListValue> extra_info)
{
  TRACE();
}
