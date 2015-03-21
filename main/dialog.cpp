// Qt includes
#include <QDebug>
#include <QDir>
#include <QLabel>
#include <QPluginLoader>

// Project includes
#include "dialog.h"
#include "plugininterface.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    loadPlugins();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadPlugins()
{
    QDir dir(qApp->applicationDirPath());
#ifdef Q_OS_DARWIN
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
#endif
    dir.cd("plugins");

    QPluginLoader loader;
    int idx = 0;
    foreach (QString filename, dir.entryList(QDir::Files | QDir::NoSymLinks))
    {
        bool loaded = false;

        loader.setFileName(dir.absoluteFilePath(filename));

        // interface v1
        if (!loaded)
        {
            Plugin::v1::PluginInterface* pluginPtr = qobject_cast<Plugin::v1::PluginInterface*>(loader.instance());

            if (pluginPtr != NULL)
            {
                qDebug() << "Loaded v1 plugin" << pluginPtr->GetTitle();

                ui->tabWidget->addTab(pluginPtr->GetWidget(), pluginPtr->GetTitle());

                ++idx;
                loaded = true;
            }
        }

        // interface v2
        if (!loaded)
        {
            Plugin::v2::PluginInterface* pluginPtr = qobject_cast<Plugin::v2::PluginInterface*>(loader.instance());

            if (pluginPtr != NULL)
            {
                qDebug() << "Loaded v2 plugin" << pluginPtr->GetTitle();

                ui->tabWidget->addTab(pluginPtr->GetWidget(), pluginPtr->GetTitle());
                ui->tabWidget->setTabToolTip(idx, pluginPtr->GetToolTip());

                ++idx;
                loaded = true;
            }
        }

        if (!loaded)
        {
            qDebug() << "Error: " << loader.errorString();
        }
    }
}
