/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QLabel *avatarlb;
    QLabel *titlelb;
    QLabel *namelb;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName("UserWidget");
        UserWidget->resize(306, 85);
        avatarlb = new QLabel(UserWidget);
        avatarlb->setObjectName("avatarlb");
        avatarlb->setGeometry(QRect(10, 13, 56, 56));
        avatarlb->setStyleSheet(QString::fromUtf8("background-image: url(:/img/head1.png); \n"
"border-radius: 28px;"));
        titlelb = new QLabel(UserWidget);
        titlelb->setObjectName("titlelb");
        titlelb->setGeometry(QRect(76, 47, 69, 17));
        titlelb->setSizeIncrement(QSize(0, 20));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(204, 204, 204, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        titlelb->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        font.setBold(false);
        titlelb->setFont(font);
        namelb = new QLabel(UserWidget);
        namelb->setObjectName("namelb");
        namelb->setGeometry(QRect(76, 18, 121, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(10);
        font1.setBold(true);
        namelb->setFont(font1);

        retranslateUi(UserWidget);

        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QCoreApplication::translate("UserWidget", "Form", nullptr));
        avatarlb->setText(QString());
        titlelb->setText(QCoreApplication::translate("UserWidget", "\347\273\217\347\220\206", nullptr));
        namelb->setText(QCoreApplication::translate("UserWidget", "\351\231\210\345\277\227\344\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
