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
    void setupUi ();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
