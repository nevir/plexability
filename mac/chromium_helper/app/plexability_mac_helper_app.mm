#import "plexability_mac_helper_app.h"


#pragma mark - Lifecyce

PlexabilityMacHelperApp::PlexabilityMacHelperApp(int argc, char* argv[]) : PlexabilityApp(argc, argv)
{
  TRACE();
}

void PlexabilityMacHelperApp::initializeNativeApp()
{
  TRACE();

  throw "Helper app tried to start as a full browser instance.  Bailing out!";
}
