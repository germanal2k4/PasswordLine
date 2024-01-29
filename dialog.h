#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
class IconizedLineEdit;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    void createUi ();
private:
    IconizedLineEdit *IconizedLineEdit_1;
    IconizedLineEdit *IconizedLineEdit_2;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
