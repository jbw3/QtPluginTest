// Qt includes
#include <QDebug>
#include <QString>
#include <QLayout>

// Project includes
#include "dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Plug-in Test");

    // create dialog
    setCentralWidget(new Dialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}
