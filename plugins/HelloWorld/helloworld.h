#ifndef HELLOWORLD_H
#define HELLOWORLD_H

// Qt includes
#include <QObject>

// Project includes
#include "helloworld_global.h"
#include "plugininterface.h"

// forward declarations
class QLabel;

class HELLOWORLDSHARED_EXPORT HelloWorld : public QObject, public Plugin::v2::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "HelloWorldPlugin")
    Q_INTERFACES(Plugin::v2::PluginInterface)

public:
    HelloWorld();
    virtual ~HelloWorld();

    virtual QString GetTitle() const;

    virtual QString GetToolTip() const;

    virtual QWidget* GetWidget();

private:
    QLabel* label;
};

#endif // HELLOWORLD_H
