// Qt includes
#include <QDebug>

// Project includes
#include "buttons.h"

Buttons::Buttons()
{
    dialog = new Dialog;
}

Buttons::~Buttons()
{
    qDebug() << __FUNCTION__;
}

QString Buttons::GetTitle() const
{
    return "Buttons";
}

QWidget* Buttons::GetWidget()
{
    return dialog;
}
