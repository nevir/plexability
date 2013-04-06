#import "plexability_mac_app.h"
#import "app_delegate.h"

#import "include/cef_application_mac.h" // For UnderlayOpenGLHostingWindow


#pragma mark - Lifecyce

PlexabilityMacApp::PlexabilityMacApp(int argc, char* argv[]) : PlexabilityApp(argc, argv)
{
  TRACE();
}

void PlexabilityMacApp::initializeNativeApp()
{
  TRACE();

  dispatch_async(dispatch_get_main_queue(), ^{
    [NSApplication sharedApplication].delegate = [AppDelegate new];

    this->initializeMainWindow();
  });
}

void PlexabilityMacApp::initializeMainWindow()
{
  TRACE();

  NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
  NSRect contentRect = {50.0, 50.0, 500.0, 500.0};

  NSWindow* window = [[UnderlayOpenGLHostingWindow alloc] initWithContentRect:contentRect styleMask:styleMask backing:NSBackingStoreBuffered defer:NO];
  window.title = @"Plexability";

  [window display];
  [window makeKeyAndOrderFront:nil];

  CefWindowInfo windowInfo;
  CefBrowserSettings browserSettings;

  windowInfo.SetAsChild(window.contentView, 0, 0, 500.0, 500.0);

  this->createBrowserAsync(windowInfo, "http://html5test.com/", browserSettings);
}
