#pragma once

#include <qglobal.h>

#if defined(QtPropertyBrowser_LIBRARY)
#  define QtPropertyBrowser_EXPORT Q_DECL_EXPORT
#elif defined(QtPropertyBrowser_STATIC_LIBRARY) // Abuse single files for manual tests
#  define QtPropertyBrowser_EXPORT
#else
#  define QtPropertyBrowser_EXPORT Q_DECL_IMPORT
#endif
