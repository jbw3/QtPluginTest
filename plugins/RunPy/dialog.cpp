// Qt includes
#include <QDebug>
#include <QProcess>

// Python includes
#include <Python.h>

// Project includes
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //ui->scriptTextEdit->setText("Hello <b>World</b>!");

    connect(ui->runButton, SIGNAL(clicked()), this, SLOT(runScript1()));
}

Dialog::~Dialog()
{
    for (auto iter = processes.begin(); iter != processes.end(); ++iter)
    {
        (*iter)->waitForFinished(-1);
        delete *iter;
        qDebug() << __FUNCTION__ << "deleted process";
    }

    delete ui;
}

void Dialog::runScript1()
{
    QString script = ui->scriptTextEdit->toPlainText();

    QString progNameStr = qApp->applicationFilePath();
    int len = progNameStr.length() + 1;
    char* progName = new char[len];
    strcpy(progName, progNameStr.toLocal8Bit().data());

    Py_SetProgramName(progName);
    Py_Initialize();

#define RUN_FILE 1
#if RUN_FILE
    const char scriptName[] = "/Users/jonathan2/MyPrograms/Python/DOE/main.py";
    FILE* scriptFile = fopen(scriptName, "r");
    if (scriptFile != NULL)
    {
        int rv = PyRun_SimpleFile(scriptFile, scriptName);
        qDebug() << "rv =" << rv;

        fclose(scriptFile);
    }
    else
    {
        qDebug() << "Could not open file" << scriptName;
    }
#else
    int rv = PyRun_SimpleString(script.toLocal8Bit().data());
    //int rv = PyRun_SimpleString("import pyDOE");
    qDebug() << "rv =" << rv;
#endif

    Py_Finalize();

    delete [] progName;
}

void Dialog::runScript2()
{
    QString script = "/Users/jonathan2/MyPrograms/Python/DOE/main.py";
    QStringList params;
    params << script;
    //params << "-V";

    QProcess* p = new QProcess;
    processes.append(p);

    connect(p, SIGNAL(finished(int)), this, SLOT(processFinished()));

    QProcessEnvironment env;
    env = QProcessEnvironment::systemEnvironment();
#ifdef Q_OS_DARWIN
    env.insert("PYTHONPATH", "/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/pyDOE-0.3.7-py2.7.egg:/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages");
#endif
    p->setProcessEnvironment(env);

    p->start("python", params);

    //qDebug() << p.processEnvironment().toStringList();

    //qDebug() << p->readAllStandardOutput();
    //qDebug() << p->readAllStandardError();
}

void Dialog::processFinished()
{
    // we don't know which process is finished, so we have to loop through the list to see
    for (auto iter = processes.begin(); iter != processes.end(); ++iter)
    {
        QProcess* proc = *iter;
        if (proc->state() == QProcess::NotRunning)
        {
            qDebug() << "------------------------------------------";
            qDebug() << proc->readAllStandardOutput();
            qDebug() << proc->readAllStandardError();
            qDebug() << "------------------------------------------";

            proc->deleteLater();
            processes.erase(iter);

            break;
        }
    }
}
