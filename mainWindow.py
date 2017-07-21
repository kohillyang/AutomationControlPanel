import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QIcon
from widgets import MapWidget,LocPlotWidget,ControlWidget
import ctypes
from ctypes import *
from communicationManger import ComManger
class App(QMainWindow):
 
    def __init__(self):
        super().__init__()

        self.title = '自动车上位机控制面板'
        self.left = 100
        self.top = 100
        self.width = 1024
        self.height = 250
        self.initUI()

    def initUI(self):
        from ui_mainWindow import Ui_MainWindow
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)        
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        centralWidget = QWidget(self)

        controlWidget  = ControlWidget(self)#
        # locWidget = LocPlotWidget(controlWidget,self)
        mapWidget = MapWidget(self)

        layout = QGridLayout(self)

        vlayout = QVBoxLayout(self)
        vlayout.addWidget(mapWidget)
        # vlayout.addWidget(locWidget)

        layout.addLayout(vlayout,0,0)
        layout.addWidget(controlWidget,0,1)

        centralWidget.setLayout(layout)
        self.setCentralWidget(centralWidget)

        self.setLayout(layout)

        self.labelStatusBar = QLabel(self)
        self.statusBar().addWidget(self.labelStatusBar)
        
        mapWidget.signal_new_message.connect(self.handleStatusMess)
        self.ui.actionClear_All.triggered.connect(mapWidget.clearAll)  
        self.ui.actionSend_All.triggered.connect(controlWidget.handleDestPosNeed2Send)
        self.ui.actionUpdate_Astart.triggered.connect(self.updateAstart)
        self.updateAstart()

        ComManger.instance().signalSerialData.connect(controlWidget.setText_serial)
        ComManger.instance().signalbeatData.connect(controlWidget.setText_beat)
        self.show()
    def updateAstart(self):
        print("info","update astart.")
        dll = ctypes.CDLL("cpp/astart.dll")
        lines_count = 0
        with open("astart_path_point.txt","rt") as f:
            for l in f:
                if(len(l.strip().split(",")) > 1):
                    lines_count += 1
        c_int_x = (ctypes.c_int * lines_count) ()
        c_int_y = (ctypes.c_int * lines_count) ()
        i = 0        
        with open("astart_path_point.txt","rt") as f:
            for l in f:
                l = l.strip().split(",")
                if(len(l) > 1):
                    c_int_x[i] = int(l[0])
                    c_int_y[i] = int(l[1])
                    i += 1
        node_setingfunc = dll.node_setingfunc
        node_setingfunc.argtypes = (POINTER(c_int),POINTER(c_int))
        node_setingfunc(c_int_x,c_int_y,i)
        dll.Astar_function()
        self.update()

    def handleStatusMess(self,mess):
        self.labelStatusBar.setText(mess);        
if __name__ == '__main__':
    import os
    # dll.float2hex()
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())