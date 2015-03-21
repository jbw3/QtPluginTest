#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

// forward declarations
class QString;
class QWidget;

namespace Plugin
{

namespace v1
{

class PluginInterface
{
public:
    virtual ~PluginInterface() {}

    virtual QString GetTitle() const = 0;

    virtual QWidget* GetWidget() = 0;
};

} //  namespace v1

namespace v2
{

class PluginInterface
{
public:
    virtual ~PluginInterface() {}

    virtual QString GetTitle() const = 0;

    virtual QString GetToolTip() const = 0;

    virtual QWidget* GetWidget() = 0;
};

} //  namespace v2

} // namespace Plugin

Q_DECLARE_INTERFACE(Plugin::v1::PluginInterface, "PluginInterface_v1")
Q_DECLARE_INTERFACE(Plugin::v2::PluginInterface, "PluginInterface_v2")

#endif // PLUGININTERFACE_H
