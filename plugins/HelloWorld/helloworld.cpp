// Qt includes
#include <QDebug>
#include <QLabel>
#include <QString>

// Project includes
#include "helloworld.h"

HelloWorld::HelloWorld()
{
    // the label will be deleted by the main program
    label = new QLabel;
    label->setText("Hello World!");
}

HelloWorld::~HelloWorld()
{
    qDebug() << __FUNCTION__;
}

QString HelloWorld::GetTitle() const
{
    return QString("Hello World!");
}

QString HelloWorld::GetToolTip() const
{
    return "Hello World Plug-in";
}

QWidget* HelloWorld::GetWidget()
{
    return label;
}
