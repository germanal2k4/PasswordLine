//
// Created by German Albershteyn on 25.01.2024.
//

#include "IconizedLineEdit.h"
#include <QDebug>
#include <QLabel>
#include <QStyle>

IconizedLineEdit::IconizedLineEdit(QWidget *parent)
    : QLineEdit(parent), mIconVisibilItyMode(IconAlwaysVisible) {
  mIconLabel =
      new QLabel(this); // Создаём метку для того, чтобы показать пиктограмму
  connect(this, SIGNAL(textChanged(QString)), this,
          SLOT(slotTextChanged(QString)), Qt::UniqueConnection);
}

// Возвращает true, если пиктограмма видима
bool IconizedLineEdit::isIconVisible() const { return mIconLabel->isVisible(); }

// Устанавливает пиктограмму
void IconizedLineEdit::setIconPixmap(const QPixmap &pPixmap) {
  // Устанавливаем пиктограмму для метки
  mIconLabel->setPixmap(pPixmap);
  // Обновляем позицию и размеры
}

// Устанавливаем подсказку для пиктограммы
void IconizedLineEdit::setIconTooltip(const QString &pToolTip) {
  // Подсказка будет видимой после наведения курсора на метку с пиктограммой
  mIconLabel->setToolTip(pToolTip);
}

void IconizedLineEdit::paintEvent(QPaintEvent *event) {
  QLineEdit::paintEvent(event);
  updateIconPositionAndsize();
}


void IconizedLineEdit::updateIconPositionAndsize() {
  // Обновить размер пиктограммы
  mIconLabel->setScaledContents(true);
  mIconLabel->setFixedSize(height(), height());
  // Обновить размещение пиктограммы
  QSize lsize = mIconLabel->size();
  mIconLabel->move(rect().right() - lsize.width(),
                  (rect().bottom() + 1 - lsize.height())/ 2);
  // Изменить отступы текста внутри поля ввода в зависимости от видимости
     if (mIconLabel->isVisible()) {
  // Добавить отступ справа чтобы текст не накладывался на пиктограмму
         QMargins lMargins = textMargins();
         lMargins.setRight(mIconLabel->size().width() + 1);
         setTextMargins(lMargins);
     } else {
  // Убрать отступы
         setTextMargins(QMargins(0, 0, 0, 0));
     }
}

void IconizedLineEdit::setIconVisibility(
    IconVisibilItyMode pIconVisibilItyMode) {
  mIconVisibilItyMode = pIconVisibilItyMode;
  switch (pIconVisibilItyMode) {
  case IconAlwaysVisible:
    setIconVisible(true);
    break;
  case IconVisibleOnEmptyText:
  case IconVisibleOnTextPresence:
    slotTextChanged(text());
    break;
  default:
    setIconVisible(false);
    break;
  }
}

void IconizedLineEdit::slotTextChanged(const QString &pText) {
  if (IconVisibleOnEmptyText == mIconVisibilItyMode) {
    setIconVisible(pText.isEmpty());
  } else if (IconVisibleOnTextPresence == mIconVisibilItyMode) {
    setIconVisible(!pText.isEmpty());
  }
}

void IconizedLineEdit::setIconVisible(bool pisVisible) {
  mIconLabel->setVisible(pisVisible);
}