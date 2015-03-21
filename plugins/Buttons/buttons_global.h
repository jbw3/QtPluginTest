#ifndef BUTTONS_GLOBAL_H
#define BUTTONS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BUTTONS_LIBRARY)
#  define BUTTONSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BUTTONSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BUTTONS_GLOBAL_H
