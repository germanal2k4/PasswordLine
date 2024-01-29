//
// Created by German Albershteyn on 25.01.2024.
//

#ifndef PASSWORDLINE_ICONIZEDLINEEDIT_H
#define PASSWORDLINE_ICONIZEDLINEEDIT_H

#include <QLineEdit>

class QLabel;

class IconizedLineEdit : public QLineEdit {
Q_OBJECT;
public :
    //Режимы отображения пиктограммы, которые определяют её поведение
    enum IconVisibilItyMode {
        //Всегда отображать пиктограмму
        IconAlwaysVisible = 0,
        //Отображать пиктограмму после наведения курсора на поле ввода
        IconVisibleOnHover,
        //Отображать пиктограмму при присутствии текста
        IconVisibleOnTextPresence,
        //Отображать пиктограмму при отсутствии текста
        IconVisibleOnEmptyText,
        //Всегда прятать пиктограмму
        IconAlwaysHidden
    };
    void setIconVisibility ( IconVisibilItyMode pIconVisibilItyMode );
    explicit IconizedLineEdit(QWidget *parent = 0);

    bool isIconVisible() const;

    void setIconPixmap(const QPixmap &pPixmap);

    void setIconTooltip(const QString &pToolTip);
private slots :
    void slotTextChanged ( const QString &pText );
private :
    void updateIconPositionAndsize();
    void setIconVisible ( bool pisVisible );
private :
    IconVisibilItyMode mIconVisibilItyMode;
    QLabel *mIconLabel; //Указатель на метку, которая отображает пиктограмму
};


#endif //PASSWORDLINE_ICONIZEDLINEEDIT_H
