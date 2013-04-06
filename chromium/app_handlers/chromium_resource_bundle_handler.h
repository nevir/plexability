#ifndef chromium_resource_bundle_handler_h
#define chromium_resource_bundle_handler_h

#include "include/cef_resource_bundle_handler.h"

class ChromiumResourceBundleHandler : public CefResourceBundleHandler {
public:

  ChromiumResourceBundleHandler();

  // CEF Interface
  // =============
  bool GetLocalizedString(int message_id, CefString& string);
  bool GetDataResource(int resource_id, void*& data, size_t& data_size);

private:
  IMPLEMENT_REFCOUNTING(ChromiumResourceBundleHandler);
};

#endif
