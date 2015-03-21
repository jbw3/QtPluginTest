#ifndef RUNPY_GLOBAL_H
#define RUNPY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RUNPY_LIBRARY)
#  define RUNPYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RUNPYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RUNPY_GLOBAL_H
