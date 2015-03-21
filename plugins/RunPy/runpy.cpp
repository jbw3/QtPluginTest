// Qt includes
#include <QLabel>

// Project includes
#include "dialog.h"
#include "runpy.h"

RunPy::RunPy()
{
    dialog = new Dialog;
}

RunPy::~RunPy()
{
}

QString RunPy::GetTitle() const
{
    return QString("RunPy");
}

QString RunPy::GetToolTip() const
{
    return QString("Plug-in to run Python scripts");
}

QWidget* RunPy::GetWidget()
{
    return dialog;
}
