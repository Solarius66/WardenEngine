#ifndef WARDEN_LIB_GLOBAL_H
#define WARDEN_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WARDEN_LIB_LIBRARY)
#  define WARDEN_LIB_EXPORT Q_DECL_EXPORT
#else
#  define WARDEN_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // WARDEN_LIB_GLOBAL_H
