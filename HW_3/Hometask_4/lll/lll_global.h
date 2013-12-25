#ifndef LLL_GLOBAL_H
#define LLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LLL_LIBRARY)
#  define LLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LLL_GLOBAL_H
