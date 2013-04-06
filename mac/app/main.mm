#import <Cocoa/Cocoa.h>

#include "plexability_mac_app.h"

int main(int argc, char* argv[])
{
  @autoreleasepool {
    PlexabilityMacApp app(argc, argv);

    return app.run();
  }
}
