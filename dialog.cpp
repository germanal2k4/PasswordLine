#include "dialog.h"
#include "QRegularExpressionValidator"
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QtCore/qregularexpression.h>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
  setupUi();
}

void Dialog::setupUi() {
  ui->IconizedLineEdit_1->setPlaceholderText(" Enter your login ");
  ui->IconizedLineEdit_1->setIconPixmap(QPixmap(":/Images/login.png"));
  ui->IconizedLineEdit_1->setIconVisibility(
      IconizedLineEdit::IconAlwaysVisible);

  ui->IconizedLineEdit_2->setPlaceholderText(" Enter password ");
  ui->IconizedLineEdit_2->setIconPixmap(QPixmap(":/Images/password.png"));
  ui->IconizedLineEdit_2->setIconVisibility(
      IconizedLineEdit::IconAlwaysVisible);

  ui->IconizedLineEdit_2->setEchoMode(QLineEdit::Password);
  ui->IconizedLineEdit_1->setValidator(
      new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9_.-]*")));
}

Dialog::~Dialog() { delete ui; }
