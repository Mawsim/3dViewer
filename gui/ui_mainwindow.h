/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "mywidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QWidget *verticalLayoutWidget_2;
  QVBoxLayout *verticalLayout_2;
  QVBoxLayout *verticalLayout;
  QLabel *fileNameLabel;
  QLabel *numVerticesLabel;
  QLabel *numEdgesLabel;
  QHBoxLayout *horizontalLayout;
  QGroupBox *projectionGroupBox;
  QRadioButton *projectionCentralRadioButton;
  QRadioButton *projectionParallelRadioButton;
  QGroupBox *groupBox_5;
  QDoubleSpinBox *scaleSpinBox;
  QPushButton *scaleMinusButton;
  QPushButton *scalePlusButton;
  QHBoxLayout *horizontalLayout_2;
  QGroupBox *groupBox_4;
  QPushButton *moveBackwardButton;
  QPushButton *moveLeftButton;
  QPushButton *moveRightButton;
  QPushButton *moveForwardButton;
  QPushButton *moveDownButton;
  QDoubleSpinBox *moveSpinBox;
  QPushButton *moveUpButton;
  QGroupBox *groupBox_3;
  QPushButton *rotateClockwiseButton;
  QPushButton *rotateLeftButton;
  QPushButton *rotateUpButton;
  QPushButton *rotateRightButton;
  QPushButton *rotateCounterclockwiseButton;
  QSpinBox *rotateSpinBox;
  QPushButton *rotateDownButton;
  QGroupBox *groupBox;
  QSpinBox *verticesSpinBox;
  QGroupBox *verticesGroupBox;
  QRadioButton *verticesSquareRadioButton;
  QRadioButton *verticesNoneRadioButton;
  QRadioButton *verticesCircleRadioButton;
  QPushButton *verticesColorButton;
  QLabel *label_8;
  QGroupBox *groupBox_2;
  QSpinBox *edgesSpinBox;
  QPushButton *edgesColorButton;
  QGroupBox *edgesGroupBox;
  QRadioButton *edgesSolidRadioButton;
  QRadioButton *edgesDashedRadioButton;
  QLabel *label_9;
  QGridLayout *gridLayout;
  QPushButton *backgroundColorButton;
  QPushButton *resetButton;
  QPushButton *screenshotButton;
  QPushButton *recordButton;
  QPushButton *openButton;
  MyWidget *widget;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1381, 815);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
    MainWindow->setSizePolicy(sizePolicy);
    MainWindow->setMinimumSize(QSize(1381, 815));
    MainWindow->setMaximumSize(QSize(1381, 815));
#if QT_CONFIG(statustip)
    MainWindow->setStatusTip(QString::fromUtf8(""));
#endif  // QT_CONFIG(statustip)
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayoutWidget_2 = new QWidget(centralwidget);
    verticalLayoutWidget_2->setObjectName(
        QString::fromUtf8("verticalLayoutWidget_2"));
    verticalLayoutWidget_2->setGeometry(QRect(1040, 0, 332, 771));
    verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
    fileNameLabel = new QLabel(verticalLayoutWidget_2);
    fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));
    sizePolicy.setHeightForWidth(
        fileNameLabel->sizePolicy().hasHeightForWidth());
    fileNameLabel->setSizePolicy(sizePolicy);
    fileNameLabel->setMinimumSize(QSize(327, 19));
    fileNameLabel->setMaximumSize(QSize(327, 19));
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    fileNameLabel->setFont(font);

    verticalLayout->addWidget(fileNameLabel);

    numVerticesLabel = new QLabel(verticalLayoutWidget_2);
    numVerticesLabel->setObjectName(QString::fromUtf8("numVerticesLabel"));
    sizePolicy.setHeightForWidth(
        numVerticesLabel->sizePolicy().hasHeightForWidth());
    numVerticesLabel->setSizePolicy(sizePolicy);
    numVerticesLabel->setMinimumSize(QSize(327, 19));
    numVerticesLabel->setMaximumSize(QSize(327, 19));
    numVerticesLabel->setFont(font);

    verticalLayout->addWidget(numVerticesLabel);

    numEdgesLabel = new QLabel(verticalLayoutWidget_2);
    numEdgesLabel->setObjectName(QString::fromUtf8("numEdgesLabel"));
    sizePolicy.setHeightForWidth(
        numEdgesLabel->sizePolicy().hasHeightForWidth());
    numEdgesLabel->setSizePolicy(sizePolicy);
    numEdgesLabel->setMinimumSize(QSize(327, 19));
    numEdgesLabel->setMaximumSize(QSize(327, 19));
    numEdgesLabel->setFont(font);

    verticalLayout->addWidget(numEdgesLabel);

    verticalLayout_2->addLayout(verticalLayout);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    projectionGroupBox = new QGroupBox(verticalLayoutWidget_2);
    projectionGroupBox->setObjectName(QString::fromUtf8("projectionGroupBox"));
    QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(
        projectionGroupBox->sizePolicy().hasHeightForWidth());
    projectionGroupBox->setSizePolicy(sizePolicy1);
    projectionGroupBox->setMinimumSize(QSize(160, 79));
    projectionGroupBox->setMaximumSize(QSize(160, 79));
    projectionCentralRadioButton = new QRadioButton(projectionGroupBox);
    projectionCentralRadioButton->setObjectName(
        QString::fromUtf8("projectionCentralRadioButton"));
    projectionCentralRadioButton->setGeometry(QRect(10, 30, 81, 23));
    projectionCentralRadioButton->setChecked(false);
    projectionParallelRadioButton = new QRadioButton(projectionGroupBox);
    projectionParallelRadioButton->setObjectName(
        QString::fromUtf8("projectionParallelRadioButton"));
    projectionParallelRadioButton->setGeometry(QRect(10, 50, 81, 23));
    projectionParallelRadioButton->setChecked(true);

    horizontalLayout->addWidget(projectionGroupBox);

    groupBox_5 = new QGroupBox(verticalLayoutWidget_2);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
    groupBox_5->setSizePolicy(sizePolicy1);
    groupBox_5->setMinimumSize(QSize(160, 79));
    groupBox_5->setMaximumSize(QSize(160, 79));
    scaleSpinBox = new QDoubleSpinBox(groupBox_5);
    scaleSpinBox->setObjectName(QString::fromUtf8("scaleSpinBox"));
    scaleSpinBox->setGeometry(QRect(50, 40, 65, 26));
    scaleSpinBox->setDecimals(1);
    scaleSpinBox->setMinimum(0.100000000000000);
    scaleSpinBox->setMaximum(10.000000000000000);
    scaleSpinBox->setSingleStep(0.100000000000000);
    scaleSpinBox->setValue(1.000000000000000);
    scaleMinusButton = new QPushButton(groupBox_5);
    scaleMinusButton->setObjectName(QString::fromUtf8("scaleMinusButton"));
    scaleMinusButton->setGeometry(QRect(10, 40, 31, 25));
    scalePlusButton = new QPushButton(groupBox_5);
    scalePlusButton->setObjectName(QString::fromUtf8("scalePlusButton"));
    scalePlusButton->setGeometry(QRect(120, 40, 31, 25));

    horizontalLayout->addWidget(groupBox_5);

    verticalLayout_2->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    groupBox_4 = new QGroupBox(verticalLayoutWidget_2);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
    groupBox_4->setSizePolicy(sizePolicy);
    groupBox_4->setMinimumSize(QSize(161, 149));
    groupBox_4->setMaximumSize(QSize(161, 149));
    moveBackwardButton = new QPushButton(groupBox_4);
    moveBackwardButton->setObjectName(QString::fromUtf8("moveBackwardButton"));
    moveBackwardButton->setGeometry(QRect(90, 30, 31, 25));
    moveLeftButton = new QPushButton(groupBox_4);
    moveLeftButton->setObjectName(QString::fromUtf8("moveLeftButton"));
    moveLeftButton->setGeometry(QRect(10, 70, 31, 25));
    moveRightButton = new QPushButton(groupBox_4);
    moveRightButton->setObjectName(QString::fromUtf8("moveRightButton"));
    moveRightButton->setGeometry(QRect(120, 70, 31, 25));
    moveForwardButton = new QPushButton(groupBox_4);
    moveForwardButton->setObjectName(QString::fromUtf8("moveForwardButton"));
    moveForwardButton->setGeometry(QRect(90, 110, 31, 25));
    moveDownButton = new QPushButton(groupBox_4);
    moveDownButton->setObjectName(QString::fromUtf8("moveDownButton"));
    moveDownButton->setGeometry(QRect(40, 110, 31, 25));
    moveSpinBox = new QDoubleSpinBox(groupBox_4);
    moveSpinBox->setObjectName(QString::fromUtf8("moveSpinBox"));
    moveSpinBox->setGeometry(QRect(50, 70, 65, 26));
    moveSpinBox->setDecimals(1);
    moveSpinBox->setSingleStep(0.100000000000000);
    moveSpinBox->setValue(0.100000000000000);
    moveUpButton = new QPushButton(groupBox_4);
    moveUpButton->setObjectName(QString::fromUtf8("moveUpButton"));
    moveUpButton->setGeometry(QRect(40, 30, 31, 25));

    horizontalLayout_2->addWidget(groupBox_4);

    groupBox_3 = new QGroupBox(verticalLayoutWidget_2);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
    groupBox_3->setSizePolicy(sizePolicy2);
    groupBox_3->setMinimumSize(QSize(161, 149));
    groupBox_3->setMaximumSize(QSize(161, 149));
    rotateClockwiseButton = new QPushButton(groupBox_3);
    rotateClockwiseButton->setObjectName(
        QString::fromUtf8("rotateClockwiseButton"));
    rotateClockwiseButton->setGeometry(QRect(90, 30, 31, 25));
    rotateLeftButton = new QPushButton(groupBox_3);
    rotateLeftButton->setObjectName(QString::fromUtf8("rotateLeftButton"));
    rotateLeftButton->setGeometry(QRect(10, 70, 31, 25));
    rotateUpButton = new QPushButton(groupBox_3);
    rotateUpButton->setObjectName(QString::fromUtf8("rotateUpButton"));
    rotateUpButton->setGeometry(QRect(40, 30, 31, 25));
    rotateRightButton = new QPushButton(groupBox_3);
    rotateRightButton->setObjectName(QString::fromUtf8("rotateRightButton"));
    rotateRightButton->setGeometry(QRect(120, 70, 31, 25));
    rotateCounterclockwiseButton = new QPushButton(groupBox_3);
    rotateCounterclockwiseButton->setObjectName(
        QString::fromUtf8("rotateCounterclockwiseButton"));
    rotateCounterclockwiseButton->setGeometry(QRect(90, 110, 31, 25));
    rotateSpinBox = new QSpinBox(groupBox_3);
    rotateSpinBox->setObjectName(QString::fromUtf8("rotateSpinBox"));
    rotateSpinBox->setGeometry(QRect(50, 70, 61, 26));
    rotateSpinBox->setMaximum(360);
    rotateSpinBox->setSingleStep(5);
    rotateSpinBox->setValue(5);
    rotateSpinBox->setDisplayIntegerBase(10);
    rotateDownButton = new QPushButton(groupBox_3);
    rotateDownButton->setObjectName(QString::fromUtf8("rotateDownButton"));
    rotateDownButton->setGeometry(QRect(40, 110, 31, 25));

    horizontalLayout_2->addWidget(groupBox_3);

    verticalLayout_2->addLayout(horizontalLayout_2);

    groupBox = new QGroupBox(verticalLayoutWidget_2);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
    groupBox->setSizePolicy(sizePolicy);
    groupBox->setMinimumSize(QSize(329, 151));
    groupBox->setMaximumSize(QSize(329, 151));
    verticesSpinBox = new QSpinBox(groupBox);
    verticesSpinBox->setObjectName(QString::fromUtf8("verticesSpinBox"));
    verticesSpinBox->setGeometry(QRect(220, 110, 71, 26));
    verticesSpinBox->setMinimum(1);
    verticesSpinBox->setMaximum(50);
    verticesSpinBox->setSingleStep(1);
    verticesSpinBox->setValue(5);
    verticesSpinBox->setDisplayIntegerBase(10);
    verticesGroupBox = new QGroupBox(groupBox);
    verticesGroupBox->setObjectName(QString::fromUtf8("verticesGroupBox"));
    verticesGroupBox->setGeometry(QRect(80, 30, 120, 111));
    verticesSquareRadioButton = new QRadioButton(verticesGroupBox);
    verticesSquareRadioButton->setObjectName(
        QString::fromUtf8("verticesSquareRadioButton"));
    verticesSquareRadioButton->setGeometry(QRect(10, 80, 71, 23));
    verticesNoneRadioButton = new QRadioButton(verticesGroupBox);
    verticesNoneRadioButton->setObjectName(
        QString::fromUtf8("verticesNoneRadioButton"));
    verticesNoneRadioButton->setGeometry(QRect(10, 30, 71, 23));
    verticesNoneRadioButton->setChecked(true);
    verticesCircleRadioButton = new QRadioButton(verticesGroupBox);
    verticesCircleRadioButton->setObjectName(
        QString::fromUtf8("verticesCircleRadioButton"));
    verticesCircleRadioButton->setGeometry(QRect(10, 50, 71, 31));
    verticesColorButton = new QPushButton(groupBox);
    verticesColorButton->setObjectName(
        QString::fromUtf8("verticesColorButton"));
    verticesColorButton->setGeometry(QRect(220, 60, 71, 25));
    label_8 = new QLabel(groupBox);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(220, 90, 71, 17));
    label_8->setLayoutDirection(Qt::LeftToRight);
    label_8->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(groupBox);

    groupBox_2 = new QGroupBox(verticalLayoutWidget_2);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
    groupBox_2->setSizePolicy(sizePolicy);
    groupBox_2->setMinimumSize(QSize(329, 121));
    groupBox_2->setMaximumSize(QSize(329, 121));
    edgesSpinBox = new QSpinBox(groupBox_2);
    edgesSpinBox->setObjectName(QString::fromUtf8("edgesSpinBox"));
    edgesSpinBox->setGeometry(QRect(220, 80, 71, 26));
    edgesSpinBox->setMinimum(1);
    edgesSpinBox->setMaximum(8);
    edgesSpinBox->setSingleStep(1);
    edgesSpinBox->setValue(1);
    edgesSpinBox->setDisplayIntegerBase(10);
    edgesColorButton = new QPushButton(groupBox_2);
    edgesColorButton->setObjectName(QString::fromUtf8("edgesColorButton"));
    edgesColorButton->setGeometry(QRect(220, 30, 71, 25));
    edgesGroupBox = new QGroupBox(groupBox_2);
    edgesGroupBox->setObjectName(QString::fromUtf8("edgesGroupBox"));
    edgesGroupBox->setGeometry(QRect(80, 30, 120, 80));
    edgesSolidRadioButton = new QRadioButton(edgesGroupBox);
    edgesSolidRadioButton->setObjectName(
        QString::fromUtf8("edgesSolidRadioButton"));
    edgesSolidRadioButton->setGeometry(QRect(10, 30, 71, 23));
    edgesSolidRadioButton->setChecked(true);
    edgesDashedRadioButton = new QRadioButton(edgesGroupBox);
    edgesDashedRadioButton->setObjectName(
        QString::fromUtf8("edgesDashedRadioButton"));
    edgesDashedRadioButton->setGeometry(QRect(10, 50, 71, 23));
    label_9 = new QLabel(groupBox_2);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(220, 60, 81, 17));
    label_9->setLayoutDirection(Qt::LeftToRight);
    label_9->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(groupBox_2);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    backgroundColorButton = new QPushButton(verticalLayoutWidget_2);
    backgroundColorButton->setObjectName(
        QString::fromUtf8("backgroundColorButton"));

    gridLayout->addWidget(backgroundColorButton, 0, 0, 1, 1);

    resetButton = new QPushButton(verticalLayoutWidget_2);
    resetButton->setObjectName(QString::fromUtf8("resetButton"));

    gridLayout->addWidget(resetButton, 0, 1, 1, 1);

    screenshotButton = new QPushButton(verticalLayoutWidget_2);
    screenshotButton->setObjectName(QString::fromUtf8("screenshotButton"));

    gridLayout->addWidget(screenshotButton, 1, 0, 1, 1);

    recordButton = new QPushButton(verticalLayoutWidget_2);
    recordButton->setObjectName(QString::fromUtf8("recordButton"));

    gridLayout->addWidget(recordButton, 1, 1, 1, 1);

    openButton = new QPushButton(verticalLayoutWidget_2);
    openButton->setObjectName(QString::fromUtf8("openButton"));

    gridLayout->addWidget(openButton, 2, 0, 1, 1);

    verticalLayout_2->addLayout(gridLayout);

    widget = new MyWidget(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(10, 0, 1024, 768));
    QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
    widget->setSizePolicy(sizePolicy3);
    widget->setMinimumSize(QSize(1024, 768));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1381, 22));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    QWidget::setTabOrder(scaleMinusButton, scaleSpinBox);
    QWidget::setTabOrder(scaleSpinBox, scalePlusButton);
    QWidget::setTabOrder(scalePlusButton, moveLeftButton);
    QWidget::setTabOrder(moveLeftButton, moveSpinBox);
    QWidget::setTabOrder(moveSpinBox, moveRightButton);
    QWidget::setTabOrder(moveRightButton, moveUpButton);
    QWidget::setTabOrder(moveUpButton, moveDownButton);
    QWidget::setTabOrder(moveDownButton, rotateLeftButton);
    QWidget::setTabOrder(rotateLeftButton, rotateSpinBox);
    QWidget::setTabOrder(rotateSpinBox, rotateRightButton);
    QWidget::setTabOrder(rotateRightButton, rotateClockwiseButton);
    QWidget::setTabOrder(rotateClockwiseButton, rotateCounterclockwiseButton);
    QWidget::setTabOrder(rotateCounterclockwiseButton, rotateUpButton);
    QWidget::setTabOrder(rotateUpButton, rotateDownButton);
    QWidget::setTabOrder(rotateDownButton, edgesColorButton);
    QWidget::setTabOrder(edgesColorButton, edgesSolidRadioButton);
    QWidget::setTabOrder(edgesSolidRadioButton, edgesDashedRadioButton);
    QWidget::setTabOrder(edgesDashedRadioButton, verticesNoneRadioButton);
    QWidget::setTabOrder(verticesNoneRadioButton, verticesCircleRadioButton);
    QWidget::setTabOrder(verticesCircleRadioButton, verticesSquareRadioButton);
    QWidget::setTabOrder(verticesSquareRadioButton, verticesColorButton);
    QWidget::setTabOrder(verticesColorButton, projectionCentralRadioButton);
    QWidget::setTabOrder(projectionCentralRadioButton,
                         projectionParallelRadioButton);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(QCoreApplication::translate(
        "MainWindow", "C8_3D_Viewer_v1.0", nullptr));
    fileNameLabel->setText(
        QCoreApplication::translate("MainWindow", "File:", nullptr));
    numVerticesLabel->setText(
        QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
    numEdgesLabel->setText(
        QCoreApplication::translate("MainWindow", "Edges:", nullptr));
    projectionGroupBox->setTitle(
        QCoreApplication::translate("MainWindow", "Projection:", nullptr));
    projectionCentralRadioButton->setText(
        QCoreApplication::translate("MainWindow", "Central", nullptr));
    projectionParallelRadioButton->setText(
        QCoreApplication::translate("MainWindow", "Parallel", nullptr));
    groupBox_5->setTitle(
        QCoreApplication::translate("MainWindow", "Scaling", nullptr));
    scaleMinusButton->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    scalePlusButton->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    groupBox_4->setTitle(
        QCoreApplication::translate("MainWindow", "Moving", nullptr));
    moveBackwardButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\227", nullptr));
    moveLeftButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
    moveRightButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
    moveForwardButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\231", nullptr));
    moveDownButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
    moveUpButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
    groupBox_3->setTitle(
        QCoreApplication::translate("MainWindow", "Rotating", nullptr));
    rotateClockwiseButton->setText(
        QCoreApplication::translate("MainWindow", "\342\237\263", nullptr));
    rotateLeftButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
    rotateUpButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
    rotateRightButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
    rotateCounterclockwiseButton->setText(
        QCoreApplication::translate("MainWindow", "\342\237\262", nullptr));
    rotateDownButton->setText(
        QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
    groupBox->setTitle(
        QCoreApplication::translate("MainWindow", "Vertices", nullptr));
    verticesGroupBox->setTitle(
        QCoreApplication::translate("MainWindow", "Display method:", nullptr));
    verticesSquareRadioButton->setText(
        QCoreApplication::translate("MainWindow", "Square", nullptr));
    verticesNoneRadioButton->setText(
        QCoreApplication::translate("MainWindow", "None", nullptr));
    verticesCircleRadioButton->setText(
        QCoreApplication::translate("MainWindow", "Circle", nullptr));
    verticesColorButton->setText(
        QCoreApplication::translate("MainWindow", "Color ...", nullptr));
    label_8->setText(
        QCoreApplication::translate("MainWindow", "Size:", nullptr));
    groupBox_2->setTitle(
        QCoreApplication::translate("MainWindow", "Edges", nullptr));
    edgesColorButton->setText(
        QCoreApplication::translate("MainWindow", "Color ...", nullptr));
    edgesGroupBox->setTitle(
        QCoreApplication::translate("MainWindow", "Type:", nullptr));
    edgesSolidRadioButton->setText(
        QCoreApplication::translate("MainWindow", "Solid", nullptr));
    edgesDashedRadioButton->setText(
        QCoreApplication::translate("MainWindow", "Dashed", nullptr));
    label_9->setText(
        QCoreApplication::translate("MainWindow", "Thickness:", nullptr));
    backgroundColorButton->setText(
        QCoreApplication::translate("MainWindow", "Background color", nullptr));
    resetButton->setText(
        QCoreApplication::translate("MainWindow", "Reset settings", nullptr));
    screenshotButton->setText(
        QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
    recordButton->setText(
        QCoreApplication::translate("MainWindow", "GIF create", nullptr));
    openButton->setText(
        QCoreApplication::translate("MainWindow", "Open ...", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
