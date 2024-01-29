#include "dialog.h"
#include "ui_dialog.h"
#include "IconizedLineEdit.h"
#include <QVBoxLayout>
#include <QtCore/qregularexpression.h>
#include "QRegularExpressionValidator"
Dialog::Dialog(QWidget *parent)
        : QDialog(parent) {
    createUi();
}

void Dialog::createUi() {
    QVBoxLayout *lMainLayout = new QVBoxLayout;
    setLayout(lMainLayout);
    IconizedLineEdit_1 = new IconizedLineEdit;
    IconizedLineEdit_1->setPlaceholderText(" Enter your login ");
    IconizedLineEdit_1->setIconPixmap(QPixmap(":/Images/login.png"));
    IconizedLineEdit_1->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(IconizedLineEdit_1);
    IconizedLineEdit_2 = new IconizedLineEdit;
    IconizedLineEdit_2->setPlaceholderText(" Enter password ");
    IconizedLineEdit_2->setIconPixmap(QPixmap(":/Images/password.png"));
    IconizedLineEdit_2->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(IconizedLineEdit_2);
    IconizedLineEdit_2->setEchoMode(QLineEdit::Password);
    IconizedLineEdit_1->setValidator( new QRegularExpressionValidator( QRegularExpression( "[A-Z][a-z]{1,9}" ) ) );
}

Dialog::~Dialog() {
    delete ui;
}
