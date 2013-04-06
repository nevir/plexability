#include "chromium_resource_bundle_handler.h"

ChromiumResourceBundleHandler::ChromiumResourceBundleHandler()
{
  TRACE();
}

// CEF Interface
// =============

// Called to retrieve a localized translation for the string specified by
// |message_id|. To provide the translation set |string| to the translation
// string and return true. To use the default translation return false.
// Supported message IDs are listed in cef_pack_strings.h.
bool ChromiumResourceBundleHandler::GetLocalizedString(int message_id, CefString& string)
{
  TRACE();

  return false;
}

// Called to retrieve data for the resource specified by |resource_id|. To
// provide the resource data set |data| and |data_size| to the data pointer
// and size respectively and return true. To use the default resource data
// return false. The resource data will not be copied and must remain resident
// in memory. Supported resource IDs are listed in cef_pack_resources.h.
bool ChromiumResourceBundleHandler::GetDataResource(int resource_id, void*& data, size_t& data_size)
{
  TRACE();

  return false;
}
