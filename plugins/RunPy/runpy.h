#ifndef RUNPY_H
#define RUNPY_H

// Qt includes
#include <QObject>

// Project includes
#include "plugininterface.h"
#include "runpy_global.h"

// forward declarations
class Dialog;

class RUNPYSHARED_EXPORT RunPy : public QObject, public Plugin::v2::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "RunPyPlugin")
    Q_INTERFACES(Plugin::v2::PluginInterface)

public:
    RunPy();

    virtual ~RunPy();

    virtual QString GetTitle() const;

    virtual QString GetToolTip() const;

    virtual QWidget* GetWidget();

protected:
    Dialog* dialog;
};

#endif // RUNPY_H
