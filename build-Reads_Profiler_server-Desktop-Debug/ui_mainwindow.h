/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "connectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *insertRowAction;
    QAction *deleteRowAction;
    QAction *fieldStrategyAction;
    QAction *rowStrategyAction;
    QAction *manualStrategyAction;
    QAction *submitAction;
    QAction *revertAction;
    QAction *selectAction;
    QVBoxLayout *vboxLayout;
    QSplitter *splitter_2;
    ConnectionWidget *connectionWidget;
    QTableView *table;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QTextEdit *sqlEdit;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *clearButton;
    QPushButton *submitButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(765, 515);
        insertRowAction = new QAction(MainWindow);
        insertRowAction->setObjectName(QStringLiteral("insertRowAction"));
        insertRowAction->setEnabled(false);
        deleteRowAction = new QAction(MainWindow);
        deleteRowAction->setObjectName(QStringLiteral("deleteRowAction"));
        deleteRowAction->setEnabled(false);
        fieldStrategyAction = new QAction(MainWindow);
        fieldStrategyAction->setObjectName(QStringLiteral("fieldStrategyAction"));
        fieldStrategyAction->setCheckable(true);
        rowStrategyAction = new QAction(MainWindow);
        rowStrategyAction->setObjectName(QStringLiteral("rowStrategyAction"));
        rowStrategyAction->setCheckable(true);
        manualStrategyAction = new QAction(MainWindow);
        manualStrategyAction->setObjectName(QStringLiteral("manualStrategyAction"));
        manualStrategyAction->setCheckable(true);
        submitAction = new QAction(MainWindow);
        submitAction->setObjectName(QStringLiteral("submitAction"));
        revertAction = new QAction(MainWindow);
        revertAction->setObjectName(QStringLiteral("revertAction"));
        selectAction = new QAction(MainWindow);
        selectAction->setObjectName(QStringLiteral("selectAction"));
        vboxLayout = new QVBoxLayout(MainWindow);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(8, 8, 8, 8);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        splitter_2 = new QSplitter(MainWindow);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy);
        splitter_2->setOrientation(Qt::Horizontal);
        connectionWidget = new ConnectionWidget(splitter_2);
        connectionWidget->setObjectName(QStringLiteral("connectionWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectionWidget->sizePolicy().hasHeightForWidth());
        connectionWidget->setSizePolicy(sizePolicy1);
        splitter_2->addWidget(connectionWidget);
        table = new QTableView(splitter_2);
        table->setObjectName(QStringLiteral("table"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy2);
        table->setContextMenuPolicy(Qt::ActionsContextMenu);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter_2->addWidget(table);

        vboxLayout->addWidget(splitter_2);

        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMaximumSize(QSize(16777215, 180));
        vboxLayout1 = new QVBoxLayout(groupBox);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        sqlEdit = new QTextEdit(groupBox);
        sqlEdit->setObjectName(QStringLiteral("sqlEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sqlEdit->sizePolicy().hasHeightForWidth());
        sqlEdit->setSizePolicy(sizePolicy4);
        sqlEdit->setMinimumSize(QSize(0, 18));
        sqlEdit->setBaseSize(QSize(0, 120));

        vboxLayout1->addWidget(sqlEdit);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        hboxLayout->addWidget(clearButton);

        submitButton = new QPushButton(groupBox);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        hboxLayout->addWidget(submitButton);


        vboxLayout1->addLayout(hboxLayout);


        vboxLayout->addWidget(groupBox);

        QWidget::setTabOrder(sqlEdit, clearButton);
        QWidget::setTabOrder(clearButton, submitButton);
        QWidget::setTabOrder(submitButton, connectionWidget);
        QWidget::setTabOrder(connectionWidget, table);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt SQL MainWindow", 0));
        insertRowAction->setText(QApplication::translate("MainWindow", "&Insert Row", 0));
#ifndef QT_NO_STATUSTIP
        insertRowAction->setStatusTip(QApplication::translate("MainWindow", "Inserts a new Row", 0));
#endif // QT_NO_STATUSTIP
        deleteRowAction->setText(QApplication::translate("MainWindow", "&Delete Row", 0));
#ifndef QT_NO_STATUSTIP
        deleteRowAction->setStatusTip(QApplication::translate("MainWindow", "Deletes the current Row", 0));
#endif // QT_NO_STATUSTIP
        fieldStrategyAction->setText(QApplication::translate("MainWindow", "Submit on &Field Change", 0));
#ifndef QT_NO_TOOLTIP
        fieldStrategyAction->setToolTip(QApplication::translate("MainWindow", "Commit on Field Change", 0));
#endif // QT_NO_TOOLTIP
        rowStrategyAction->setText(QApplication::translate("MainWindow", "Submit on &Row Change", 0));
#ifndef QT_NO_TOOLTIP
        rowStrategyAction->setToolTip(QApplication::translate("MainWindow", "Commit on Row Change", 0));
#endif // QT_NO_TOOLTIP
        manualStrategyAction->setText(QApplication::translate("MainWindow", "Submit &Manually", 0));
#ifndef QT_NO_TOOLTIP
        manualStrategyAction->setToolTip(QApplication::translate("MainWindow", "Commit Manually", 0));
#endif // QT_NO_TOOLTIP
        submitAction->setText(QApplication::translate("MainWindow", "&Submit All", 0));
#ifndef QT_NO_TOOLTIP
        submitAction->setToolTip(QApplication::translate("MainWindow", "Submit Changes", 0));
#endif // QT_NO_TOOLTIP
        revertAction->setText(QApplication::translate("MainWindow", "&Revert All", 0));
#ifndef QT_NO_TOOLTIP
        revertAction->setToolTip(QApplication::translate("MainWindow", "Revert", 0));
#endif // QT_NO_TOOLTIP
        selectAction->setText(QApplication::translate("MainWindow", "S&elect", 0));
#ifndef QT_NO_TOOLTIP
        selectAction->setToolTip(QApplication::translate("MainWindow", "Refresh Data from Database", 0));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "SQL Query", 0));
        clearButton->setText(QApplication::translate("MainWindow", "&Clear", 0));
        submitButton->setText(QApplication::translate("MainWindow", "&Submit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
