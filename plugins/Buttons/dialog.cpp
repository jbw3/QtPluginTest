#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(button1Slot()));
    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(button2Slot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::button1Slot()
{
    static uint counter = 0;
    ++counter;

    ui->pushButton1->setText("Count: " + QString::number(counter));
}

void Dialog::button2Slot()
{
}
