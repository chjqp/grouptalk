/********************************************************************************
** Form generated from reading UI file 'recvbox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECVBOX_H
#define UI_RECVBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecvBox
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *label_2;
    QLabel *namelb;
    QLabel *titlelb;

    void setupUi(QWidget *RecvBox)
    {
        if (RecvBox->objectName().isEmpty())
            RecvBox->setObjectName("RecvBox");
        RecvBox->resize(553, 203);
        widget = new QWidget(RecvBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 111, 203));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(9);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(40, 40));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        namelb = new QLabel(widget);
        namelb->setObjectName("namelb");

        gridLayout->addWidget(namelb, 1, 0, 1, 1);

        titlelb = new QLabel(widget);
        titlelb->setObjectName("titlelb");

        gridLayout->addWidget(titlelb, 2, 0, 1, 1);


        retranslateUi(RecvBox);

        QMetaObject::connectSlotsByName(RecvBox);
    } // setupUi

    void retranslateUi(QWidget *RecvBox)
    {
        RecvBox->setWindowTitle(QCoreApplication::translate("RecvBox", "Form", nullptr));
        label->setText(QCoreApplication::translate("RecvBox", "img", nullptr));
        label_2->setText(QCoreApplication::translate("RecvBox", "recvmsg", nullptr));
        namelb->setText(QCoreApplication::translate("RecvBox", "\345\274\240\344\270\211", nullptr));
        titlelb->setText(QCoreApplication::translate("RecvBox", "\347\273\217\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecvBox: public Ui_RecvBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECVBOX_H
