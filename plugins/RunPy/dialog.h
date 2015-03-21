#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

// forward declarations
class QProcess;
namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    Ui::Dialog *ui;
    QList<QProcess*> processes;

protected slots:
    void runScript1();
    void runScript2();

    void processFinished();
};

#endif // DIALOG_H
