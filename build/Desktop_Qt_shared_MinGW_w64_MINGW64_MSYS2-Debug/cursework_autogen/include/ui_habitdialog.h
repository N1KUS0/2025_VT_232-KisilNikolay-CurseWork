/********************************************************************************
** Form generated from reading UI file 'habitdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HABITDIALOG_H
#define UI_HABITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HabitDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QTextEdit *descriptionEdit;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *day1CheckBox;
    QCheckBox *day2CheckBox;
    QCheckBox *day3CheckBox;
    QCheckBox *day4CheckBox;
    QCheckBox *day5CheckBox;
    QCheckBox *day6CheckBox;
    QCheckBox *day7CheckBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *HabitDialog)
    {
        if (HabitDialog->objectName().isEmpty())
            HabitDialog->setObjectName("HabitDialog");
        HabitDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(HabitDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(HabitDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        nameEdit = new QLineEdit(HabitDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_2 = new QLabel(HabitDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        descriptionEdit = new QTextEdit(HabitDialog);
        descriptionEdit->setObjectName("descriptionEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, descriptionEdit);

        label_3 = new QLabel(HabitDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        day1CheckBox = new QCheckBox(HabitDialog);
        day1CheckBox->setObjectName("day1CheckBox");

        horizontalLayout->addWidget(day1CheckBox);

        day2CheckBox = new QCheckBox(HabitDialog);
        day2CheckBox->setObjectName("day2CheckBox");

        horizontalLayout->addWidget(day2CheckBox);

        day3CheckBox = new QCheckBox(HabitDialog);
        day3CheckBox->setObjectName("day3CheckBox");

        horizontalLayout->addWidget(day3CheckBox);

        day4CheckBox = new QCheckBox(HabitDialog);
        day4CheckBox->setObjectName("day4CheckBox");

        horizontalLayout->addWidget(day4CheckBox);

        day5CheckBox = new QCheckBox(HabitDialog);
        day5CheckBox->setObjectName("day5CheckBox");

        horizontalLayout->addWidget(day5CheckBox);

        day6CheckBox = new QCheckBox(HabitDialog);
        day6CheckBox->setObjectName("day6CheckBox");

        horizontalLayout->addWidget(day6CheckBox);

        day7CheckBox = new QCheckBox(HabitDialog);
        day7CheckBox->setObjectName("day7CheckBox");

        horizontalLayout->addWidget(day7CheckBox);


        formLayout->setLayout(2, QFormLayout::ItemRole::FieldRole, horizontalLayout);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(HabitDialog);
        okButton->setObjectName("okButton");

        horizontalLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(HabitDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(HabitDialog);
        QObject::connect(okButton, &QPushButton::clicked, HabitDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, HabitDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HabitDialog);
    } // setupUi

    void retranslateUi(QDialog *HabitDialog)
    {
        HabitDialog->setWindowTitle(QCoreApplication::translate("HabitDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\270\320\262\321\213\321\207\320\272\321\203", nullptr));
        label->setText(QCoreApplication::translate("HabitDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_2->setText(QCoreApplication::translate("HabitDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        label_3->setText(QCoreApplication::translate("HabitDialog", "\320\224\320\275\320\270 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", nullptr));
        day1CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\237\320\275", nullptr));
        day2CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\222\321\202", nullptr));
        day3CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\241\321\200", nullptr));
        day4CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\247\321\202", nullptr));
        day5CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\237\321\202", nullptr));
        day6CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\241\320\261", nullptr));
        day7CheckBox->setText(QCoreApplication::translate("HabitDialog", "\320\222\321\201", nullptr));
        okButton->setText(QCoreApplication::translate("HabitDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("HabitDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HabitDialog: public Ui_HabitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HABITDIALOG_H
