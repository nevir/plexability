#ifndef plexability_log_h
#define plexability_log_h

#include <stdio.h>

// If you don't like crazy verbosity, tough!
//
// General flow is to TRACE() at the start of a function, followed by a bunch of log statements.

#define TRACE() printf("\n%120s\n------------------------------------------------------------------------------------------------------------------------\n", __PRETTY_FUNCTION__)

#define LOG(format, args...) printf(format "\n", ## args)

#endif
