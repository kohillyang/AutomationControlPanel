# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'controlWidget.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(337, 650)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(Form.sizePolicy().hasHeightForWidth())
        Form.setSizePolicy(sizePolicy)
        Form.setMinimumSize(QtCore.QSize(240, 0))
        self.gridLayout_3 = QtWidgets.QGridLayout(Form)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.groupBox = QtWidgets.QGroupBox(Form)
        self.groupBox.setObjectName("groupBox")
        self.gridLayout_4 = QtWidgets.QGridLayout(self.groupBox)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.label_2 = QtWidgets.QLabel(self.groupBox)
        self.label_2.setObjectName("label_2")
        self.gridLayout_4.addWidget(self.label_2, 0, 0, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_4.addItem(spacerItem, 3, 0, 1, 1)
        self.plainTextEdit = QtWidgets.QPlainTextEdit(self.groupBox)
        self.plainTextEdit.setObjectName("plainTextEdit")
        self.gridLayout_4.addWidget(self.plainTextEdit, 1, 0, 1, 1)
        self.pushButton_2 = QtWidgets.QPushButton(self.groupBox)
        self.pushButton_2.setObjectName("pushButton_2")
        self.gridLayout_4.addWidget(self.pushButton_2, 2, 0, 1, 1)
        self.gridLayout_3.addWidget(self.groupBox, 2, 0, 1, 1)
        self.groupBox_2 = QtWidgets.QGroupBox(Form)
        self.groupBox_2.setObjectName("groupBox_2")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.groupBox_2)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.tabWidget = QtWidgets.QTabWidget(self.groupBox_2)
        self.tabWidget.setObjectName("tabWidget")
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.gridLayout_5 = QtWidgets.QGridLayout(self.tab)
        self.gridLayout_5.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_5.setObjectName("gridLayout_5")
        self.groupBox_3 = QtWidgets.QGroupBox(self.tab)
        self.groupBox_3.setObjectName("groupBox_3")
        self.gridLayout = QtWidgets.QGridLayout(self.groupBox_3)
        self.gridLayout.setObjectName("gridLayout")
        self.doubleSpinBox_pid1_1 = QtWidgets.QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_pid1_1.setObjectName("doubleSpinBox_pid1_1")
        self.gridLayout.addWidget(self.doubleSpinBox_pid1_1, 0, 1, 1, 1)
        self.label_6 = QtWidgets.QLabel(self.groupBox_3)
        self.label_6.setObjectName("label_6")
        self.gridLayout.addWidget(self.label_6, 0, 0, 1, 1)
        self.doubleSpinBox_pid1_3 = QtWidgets.QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_pid1_3.setObjectName("doubleSpinBox_pid1_3")
        self.gridLayout.addWidget(self.doubleSpinBox_pid1_3, 2, 1, 1, 1)
        self.doubleSpinBox_pid1_2 = QtWidgets.QDoubleSpinBox(self.groupBox_3)
        self.doubleSpinBox_pid1_2.setObjectName("doubleSpinBox_pid1_2")
        self.gridLayout.addWidget(self.doubleSpinBox_pid1_2, 1, 1, 1, 1)
        self.label_8 = QtWidgets.QLabel(self.groupBox_3)
        self.label_8.setObjectName("label_8")
        self.gridLayout.addWidget(self.label_8, 2, 0, 1, 1)
        self.label_7 = QtWidgets.QLabel(self.groupBox_3)
        self.label_7.setObjectName("label_7")
        self.gridLayout.addWidget(self.label_7, 1, 0, 1, 1)
        self.gridLayout_5.addWidget(self.groupBox_3, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QtWidgets.QWidget()
        self.tab_2.setObjectName("tab_2")
        self.gridLayout_7 = QtWidgets.QGridLayout(self.tab_2)
        self.gridLayout_7.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_7.setObjectName("gridLayout_7")
        self.groupBox_4 = QtWidgets.QGroupBox(self.tab_2)
        self.groupBox_4.setObjectName("groupBox_4")
        self.gridLayout_6 = QtWidgets.QGridLayout(self.groupBox_4)
        self.gridLayout_6.setObjectName("gridLayout_6")
        self.doubleSpinBox_pid2_1 = QtWidgets.QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_pid2_1.setObjectName("doubleSpinBox_pid2_1")
        self.gridLayout_6.addWidget(self.doubleSpinBox_pid2_1, 0, 1, 1, 1)
        self.label_9 = QtWidgets.QLabel(self.groupBox_4)
        self.label_9.setObjectName("label_9")
        self.gridLayout_6.addWidget(self.label_9, 0, 0, 1, 1)
        self.doubleSpinBox_pid2_3 = QtWidgets.QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_pid2_3.setObjectName("doubleSpinBox_pid2_3")
        self.gridLayout_6.addWidget(self.doubleSpinBox_pid2_3, 2, 1, 1, 1)
        self.doubleSpinBox_pid2_2 = QtWidgets.QDoubleSpinBox(self.groupBox_4)
        self.doubleSpinBox_pid2_2.setObjectName("doubleSpinBox_pid2_2")
        self.gridLayout_6.addWidget(self.doubleSpinBox_pid2_2, 1, 1, 1, 1)
        self.label_10 = QtWidgets.QLabel(self.groupBox_4)
        self.label_10.setObjectName("label_10")
        self.gridLayout_6.addWidget(self.label_10, 2, 0, 1, 1)
        self.label_11 = QtWidgets.QLabel(self.groupBox_4)
        self.label_11.setObjectName("label_11")
        self.gridLayout_6.addWidget(self.label_11, 1, 0, 1, 1)
        self.gridLayout_7.addWidget(self.groupBox_4, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab_2, "")
        self.tab_3 = QtWidgets.QWidget()
        self.tab_3.setObjectName("tab_3")
        self.gridLayout_11 = QtWidgets.QGridLayout(self.tab_3)
        self.gridLayout_11.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_11.setObjectName("gridLayout_11")
        self.groupBox_6 = QtWidgets.QGroupBox(self.tab_3)
        self.groupBox_6.setObjectName("groupBox_6")
        self.gridLayout_10 = QtWidgets.QGridLayout(self.groupBox_6)
        self.gridLayout_10.setObjectName("gridLayout_10")
        self.doubleSpinBox_pid3_1 = QtWidgets.QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_pid3_1.setObjectName("doubleSpinBox_pid3_1")
        self.gridLayout_10.addWidget(self.doubleSpinBox_pid3_1, 0, 1, 1, 1)
        self.label_15 = QtWidgets.QLabel(self.groupBox_6)
        self.label_15.setObjectName("label_15")
        self.gridLayout_10.addWidget(self.label_15, 0, 0, 1, 1)
        self.doubleSpinBox_pid3_3 = QtWidgets.QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_pid3_3.setObjectName("doubleSpinBox_pid3_3")
        self.gridLayout_10.addWidget(self.doubleSpinBox_pid3_3, 2, 1, 1, 1)
        self.doubleSpinBox_pid3_2 = QtWidgets.QDoubleSpinBox(self.groupBox_6)
        self.doubleSpinBox_pid3_2.setObjectName("doubleSpinBox_pid3_2")
        self.gridLayout_10.addWidget(self.doubleSpinBox_pid3_2, 1, 1, 1, 1)
        self.label_16 = QtWidgets.QLabel(self.groupBox_6)
        self.label_16.setObjectName("label_16")
        self.gridLayout_10.addWidget(self.label_16, 2, 0, 1, 1)
        self.label_17 = QtWidgets.QLabel(self.groupBox_6)
        self.label_17.setObjectName("label_17")
        self.gridLayout_10.addWidget(self.label_17, 1, 0, 1, 1)
        self.gridLayout_11.addWidget(self.groupBox_6, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab_3, "")
        self.tab_4 = QtWidgets.QWidget()
        self.tab_4.setObjectName("tab_4")
        self.gridLayout_9 = QtWidgets.QGridLayout(self.tab_4)
        self.gridLayout_9.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_9.setObjectName("gridLayout_9")
        self.groupBox_5 = QtWidgets.QGroupBox(self.tab_4)
        self.groupBox_5.setObjectName("groupBox_5")
        self.gridLayout_8 = QtWidgets.QGridLayout(self.groupBox_5)
        self.gridLayout_8.setObjectName("gridLayout_8")
        self.doubleSpinBox_pid4_1 = QtWidgets.QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_pid4_1.setObjectName("doubleSpinBox_pid4_1")
        self.gridLayout_8.addWidget(self.doubleSpinBox_pid4_1, 0, 1, 1, 1)
        self.label_12 = QtWidgets.QLabel(self.groupBox_5)
        self.label_12.setObjectName("label_12")
        self.gridLayout_8.addWidget(self.label_12, 0, 0, 1, 1)
        self.doubleSpinBox_pid4_3 = QtWidgets.QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_pid4_3.setObjectName("doubleSpinBox_pid4_3")
        self.gridLayout_8.addWidget(self.doubleSpinBox_pid4_3, 2, 1, 1, 1)
        self.doubleSpinBox_pid4_2 = QtWidgets.QDoubleSpinBox(self.groupBox_5)
        self.doubleSpinBox_pid4_2.setObjectName("doubleSpinBox_pid4_2")
        self.gridLayout_8.addWidget(self.doubleSpinBox_pid4_2, 1, 1, 1, 1)
        self.label_13 = QtWidgets.QLabel(self.groupBox_5)
        self.label_13.setObjectName("label_13")
        self.gridLayout_8.addWidget(self.label_13, 2, 0, 1, 1)
        self.label_14 = QtWidgets.QLabel(self.groupBox_5)
        self.label_14.setObjectName("label_14")
        self.gridLayout_8.addWidget(self.label_14, 1, 0, 1, 1)
        self.gridLayout_9.addWidget(self.groupBox_5, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab_4, "")
        self.gridLayout_2.addWidget(self.tabWidget, 0, 0, 1, 1)
        self.pushButton_4 = QtWidgets.QPushButton(self.groupBox_2)
        self.pushButton_4.setObjectName("pushButton_4")
        self.gridLayout_2.addWidget(self.pushButton_4, 1, 0, 1, 1)
        self.gridLayout_3.addWidget(self.groupBox_2, 1, 0, 1, 1)
        self.groupBox_com = QtWidgets.QGroupBox(Form)
        self.groupBox_com.setObjectName("groupBox_com")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.groupBox_com)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label = QtWidgets.QLabel(self.groupBox_com)
        self.label.setObjectName("label")
        self.horizontalLayout_2.addWidget(self.label)
        self.lineEdit_hostip = QtWidgets.QLineEdit(self.groupBox_com)
        self.lineEdit_hostip.setMaximumSize(QtCore.QSize(110, 16777215))
        self.lineEdit_hostip.setObjectName("lineEdit_hostip")
        self.horizontalLayout_2.addWidget(self.lineEdit_hostip)
        self.pushButton_3 = QtWidgets.QPushButton(self.groupBox_com)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_3.sizePolicy().hasHeightForWidth())
        self.pushButton_3.setSizePolicy(sizePolicy)
        self.pushButton_3.setMaximumSize(QtCore.QSize(250, 16777215))
        self.pushButton_3.setObjectName("pushButton_3")
        self.horizontalLayout_2.addWidget(self.pushButton_3)
        self.verticalLayout_3.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label_5 = QtWidgets.QLabel(self.groupBox_com)
        self.label_5.setObjectName("label_5")
        self.horizontalLayout_4.addWidget(self.label_5)
        self.lineEdit_2 = QtWidgets.QLineEdit(self.groupBox_com)
        self.lineEdit_2.setMaximumSize(QtCore.QSize(110, 16777215))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.horizontalLayout_4.addWidget(self.lineEdit_2)
        self.pushButton_5 = QtWidgets.QPushButton(self.groupBox_com)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_5.sizePolicy().hasHeightForWidth())
        self.pushButton_5.setSizePolicy(sizePolicy)
        self.pushButton_5.setMaximumSize(QtCore.QSize(250, 16777215))
        self.pushButton_5.setObjectName("pushButton_5")
        self.horizontalLayout_4.addWidget(self.pushButton_5)
        self.verticalLayout_3.addLayout(self.horizontalLayout_4)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_4 = QtWidgets.QLabel(self.groupBox_com)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout.addWidget(self.label_4)
        self.lineEdit_3 = QtWidgets.QLineEdit(self.groupBox_com)
        self.lineEdit_3.setMaximumSize(QtCore.QSize(110, 16777215))
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.horizontalLayout.addWidget(self.lineEdit_3)
        self.pushButton = QtWidgets.QPushButton(self.groupBox_com)
        self.pushButton.setMaximumSize(QtCore.QSize(250, 16777215))
        self.pushButton.setObjectName("pushButton")
        self.horizontalLayout.addWidget(self.pushButton)
        self.verticalLayout_3.addLayout(self.horizontalLayout)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_3 = QtWidgets.QLabel(self.groupBox_com)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_3.sizePolicy().hasHeightForWidth())
        self.label_3.setSizePolicy(sizePolicy)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_3.addWidget(self.label_3)
        self.doubleSpinBox = QtWidgets.QDoubleSpinBox(self.groupBox_com)
        self.doubleSpinBox.setObjectName("doubleSpinBox")
        self.horizontalLayout_3.addWidget(self.doubleSpinBox)
        self.verticalLayout_3.addLayout(self.horizontalLayout_3)
        self.gridLayout_3.addWidget(self.groupBox_com, 0, 0, 1, 1)

        self.retranslateUi(Form)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.groupBox.setTitle(_translate("Form", "ToolBox"))
        self.label_2.setText(_translate("Form", "Send extra data to STM32."))
        self.pushButton_2.setText(_translate("Form", "Send"))
        self.groupBox_2.setTitle(_translate("Form", "Parameter Setting"))
        self.groupBox_3.setTitle(_translate("Form", "PID"))
        self.label_6.setText(_translate("Form", "P_1"))
        self.label_8.setText(_translate("Form", "I_1"))
        self.label_7.setText(_translate("Form", "I_1"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("Form", "PID1"))
        self.groupBox_4.setTitle(_translate("Form", "PID"))
        self.label_9.setText(_translate("Form", "P_2"))
        self.label_10.setText(_translate("Form", "I_3"))
        self.label_11.setText(_translate("Form", "I_2"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("Form", "PID2"))
        self.groupBox_6.setTitle(_translate("Form", "PID"))
        self.label_15.setText(_translate("Form", "P_3"))
        self.label_16.setText(_translate("Form", "I_3"))
        self.label_17.setText(_translate("Form", "I_3"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), _translate("Form", "PID3"))
        self.groupBox_5.setTitle(_translate("Form", "PID"))
        self.label_12.setText(_translate("Form", "P_4"))
        self.label_13.setText(_translate("Form", "I_4"))
        self.label_14.setText(_translate("Form", "I_4"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_4), _translate("Form", "PID4"))
        self.pushButton_4.setText(_translate("Form", "Send"))
        self.groupBox_com.setTitle(_translate("Form", "Communication Setting"))
        self.label.setText(_translate("Form", "STM32 IP:"))
        self.lineEdit_hostip.setText(_translate("Form", "192.168.199.112"))
        self.pushButton_3.setText(_translate("Form", "Set"))
        self.label_5.setText(_translate("Form", "Host IP:"))
        self.lineEdit_2.setText(_translate("Form", "192.168.199.177"))
        self.pushButton_5.setText(_translate("Form", "Listen"))
        self.label_4.setText(_translate("Form", "Plane IP:"))
        self.lineEdit_3.setText(_translate("Form", "192.168.199.176"))
        self.pushButton.setText(_translate("Form", "Set"))
        self.label_3.setText(_translate("Form", "Grip Width(m):"))

