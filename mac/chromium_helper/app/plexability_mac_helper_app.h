#ifndef plexability_mac_app_h
#define plexability_mac_app_h

#include "plexability_app.h"

class PlexabilityMacHelperApp : public PlexabilityApp {
public:

  // Lifecycle
  // =========
  PlexabilityMacHelperApp(int argc, char* argv[]);

private:
  void initializeNativeApp();
};

#endif
