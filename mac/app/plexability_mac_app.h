#ifndef plexability_mac_app_h
#define plexability_mac_app_h

#include "plexability_app.h"
#import <Cocoa/Cocoa.h>

class PlexabilityMacApp : public PlexabilityApp {
public:

  // Lifecycle
  // =========
  PlexabilityMacApp(int argc, char* argv[]);

private:
  void initializeNativeApp();
  void initializeMainWindow();


  // State
  // =====

  NSWindow* window;
};

#endif
