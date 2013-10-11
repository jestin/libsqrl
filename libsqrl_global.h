#ifndef LIBSQRL_GLOBAL_H
#define LIBSQRL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBSQRL_LIBRARY)
#  define LIBSQRLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBSQRLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBSQRL_GLOBAL_H
