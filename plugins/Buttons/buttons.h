#ifndef BUTTONS_H
#define BUTTONS_H

// Qt includes
#include <QObject>

// Project includes
#include "buttons_global.h"
#include "dialog.h"
#include "plugininterface.h"

class BUTTONSSHARED_EXPORT Buttons : public QObject, public Plugin::v1::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ButtonPlugin")
    Q_INTERFACES(Plugin::v1::PluginInterface)

public:
    Buttons();

    virtual ~Buttons();

    virtual QString GetTitle() const;

    virtual QWidget* GetWidget();

private:
    Dialog* dialog;
};

#endif // BUTTONS_H
