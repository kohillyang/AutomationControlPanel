# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainWindow.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 26))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        self.menuPath = QtWidgets.QMenu(self.menubar)
        self.menuPath.setObjectName("menuPath")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionExit = QtWidgets.QAction(MainWindow)
        self.actionExit.setObjectName("actionExit")
        self.actionClear_All = QtWidgets.QAction(MainWindow)
        self.actionClear_All.setObjectName("actionClear_All")
        self.actionSend_All = QtWidgets.QAction(MainWindow)
        self.actionSend_All.setObjectName("actionSend_All")
        self.actionUpdate_Astart = QtWidgets.QAction(MainWindow)
        self.actionUpdate_Astart.setObjectName("actionUpdate_Astart")
        self.menuFile.addAction(self.actionExit)
        self.menuPath.addAction(self.actionClear_All)
        self.menuPath.addAction(self.actionSend_All)
        self.menuPath.addAction(self.actionUpdate_Astart)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuPath.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.menuPath.setTitle(_translate("MainWindow", "Path"))
        self.actionExit.setText(_translate("MainWindow", "Exit"))
        self.actionExit.setShortcut(_translate("MainWindow", "Alt+W"))
        self.actionClear_All.setText(_translate("MainWindow", "Clear All"))
        self.actionSend_All.setText(_translate("MainWindow", "Send All"))
        self.actionUpdate_Astart.setText(_translate("MainWindow", "Update Astart"))
        self.actionUpdate_Astart.setShortcut(_translate("MainWindow", "Alt+U"))

