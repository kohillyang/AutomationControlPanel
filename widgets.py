import pyqtgraph as pg
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import QPointF,pyqtSignal,QPoint,Qt,QRectF
from pyqtgraph.graphicsItems.ViewBox.ViewBox import ViewBox
import threading
from communicationManger import ComManger
import time
import ctypes

pathPoints = []
class LocPlotWidget(pg.PlotWidget):
    def __init__(self,controlWidget,parent=None):
        super(LocPlotWidget,self).__init__(parent=parent)
        self.controlwidget = controlWidget
        l = pg.GraphicsLayout(border=(0,0,0))   
        self.setCentralItem(l)  
        self.setMinimumSize(640,140)    

        self.pLoc = l.addPlot(1, 1, rowspan = 1, colspan = 1)
        self.pLoc.setLabel('top',"位置x,y(m)")
        self.curveLocX = self.pLoc.plot(x= [],y = [],pen = 'g')
        self.curveLocY = self.pLoc.plot(x= [],y = [],pen = 'r')
        #采样波形显示
        self.p2 = l.addPlot(1,2,rowspan = 1,colspan = 1)
        self.p2.disableAutoRange(axis = ViewBox.YAxis)
        self.p2.showGrid(x=True,y=True)
        self.p2.setLabel('left', "Y Axis", units='V')
        self.p2.setLabel('bottom', "X Axis", units='s')
        self.curveCompass = self.p2.plot(pen = 'y')
        self.curveCompass.setData(x = [],y = []) 

        
class MapWidget(QWidget):
    signal_new_message = pyqtSignal(str)     
    __instance = None   
    def __init__(self,parent=None):
        super(MapWidget,self).__init__(parent=parent)
        self.changdiImg = QImage("resources/changdi.png")  
        size = self.changdiImg.size()
        self.setFixedSize(size)
        self.setMouseTracking(True)
        global pathPoints
        pathPoints = []
        self.changdiW = 28
        self.changdiH = 13
        self.gridWidth = 554/30
        self.hexDll = ctypes.CDLL("cpp/astart.dll")
        self.zipfloat2array3 = self.hexDll.zipfloat2array3
        #extern void zipfloat2array3(char *p,char id,float pos0,float pos1,float pos2);
        self.zipfloat2array3.argtypes = (ctypes.c_char_p,ctypes.c_char,ctypes.c_float,ctypes.c_float,ctypes.c_float)
    def convert2ComputerRect(self,countX,countY):
        pointOrigin = QPointF((countX) * self.gridWidth,(23-countY) * self.gridWidth )
        return QRectF(pointOrigin,pointOrigin + QPointF(self.gridWidth,self.gridWidth))
    def paintEvent(self,event):
        global pathPoints        
        super(MapWidget,self).paintEvent(event)
        painter = QPainter()
        painter.begin(self)
        painter.drawImage(QPoint(0,0),self.changdiImg)

        height = self.changdiImg.size().height()
        width = self.changdiImg.size().width()

        # for i in range(4):
        #     painter.drawLine(0, height / 4 *i ,width,height / 4 *i)
        pen = QPen(Qt.blue,25)
        painter.setPen(pen)
        painter.setBrush(Qt.red)
        for point in pathPoints:
            point  = self.convert2ComputerCoordinate(point)
            # painter.drawEllipse(point.x()-20,point.y()-20,40,40)
            painter.drawPoint(point)      
        pen = QPen(Qt.yellow,1)
        painter.setPen(pen)
        painter.setBrush(Qt.yellow)            
        with open("data.txt","rt") as f:
            for l in f:
                l = l.strip().split(',')
                x = float(l[0])
                y = float(l[1])
                rect = self.convert2ComputerRect(x,y)
                painter.drawRect(rect)
        pen = QPen(Qt.green,1)
        painter.setPen(pen)
        painter.setBrush(Qt.green)            
        with open("astart_path_point.txt","rt") as f:
            for l in f:
                l = l.strip().split(',')
                x = float(l[0])
                y = float(l[1])
                rect = self.convert2ComputerRect(x,y)
                painter.drawRect(rect)
        painter.end()

    def convert2Realcoordinate(self,fromPoint):
        maxPoint = QPointF(self.width(),self.height())        
        xDepends = 1.0 * fromPoint.x()/maxPoint.x()
        yDepends = 1.0 - fromPoint.y()/maxPoint.y()
        xReal = xDepends * self.changdiW
        yReal = yDepends * self.changdiH
        return QPointF(xReal,yReal)    
    def convert2ComputerCoordinate(self,fromPoint):
        maxPoint = QPointF(self.width(),self.height())         
        xDepends = 1.0 * fromPoint.x()/self.changdiW
        yDepends = 1.0 - fromPoint.y()/self.changdiH
        xReal = xDepends * maxPoint.x()
        yReal = yDepends * maxPoint.y()
        return QPointF(xReal,yReal)    
    def mouseMoveEvent(self,event):
        pos = event.pos()
        realPos = self.convert2Realcoordinate(QPointF(pos.x(),pos.y()))
        mess = "%f,%f,%f,%f"%(pos.x(),pos.y(),realPos.x(),realPos.y()) 
        self.signal_new_message.emit(mess)     
    def mouseDoubleClickEvent(self,event):
        if QMessageBox.question(self,"?","是否设置此点为终点？") == QMessageBox.Yes:
            realP= self.convert2Realcoordinate(event.pos())
            global pathPoints
            pathPoints.append(realP)
            print("set",realP);
        self.update()
    def clearAll(self,triggered):
        global pathPoints
        pathPoints = []
        self.update()
        pass
class ControlWidget(QWidget):
    signal_ip_changed = pyqtSignal()       
    def updatestm32Ip(self,ip):
        self.ui.lineEdit_stm32_ip.setText(str(ip))
    def setText_beat(self,text1):
        self.ui.textBrowser_beat.append(text1)
    def setText_serial(self,text1):
        self.ui.textBrowser_serial.append(text1)        
        print("setTxte",text1)
    def __init__(self,parent = None):
        super(ControlWidget,self).__init__(parent = parent);
        # self.setFixedWidth(240)
        from ui_controlwidget import Ui_Form
        self.ui  = Ui_Form()
        self.ui.setupUi(self)
        self.handleipChanged()



        self.ui.pushButton_parameterSet.clicked.connect(self.handlepushButton_parameterSetClicked)
        self.ui.pushButton_pos_clear_all.clicked.connect(MapWidget().clearAll)
        self.ui.pushButton_pos_send.clicked.connect(self.handleDestPosNeed2Send)

        self.hexDll = ctypes.CDLL("cpp/astart.dll")
        self.zipfloat2array3 = self.hexDll.zipfloat2array3
        #extern void zipfloat2array3(char *p,char id,float pos0,float pos1,float pos2);
        self.zipfloat2array3.argtypes = (ctypes.c_char_p,ctypes.c_char,ctypes.c_float,ctypes.c_float,ctypes.c_float)
        raw_memory  = ctypes.create_string_buffer(b"",32)
        self.zipfloat2array3(raw_memory,0,1.0,2.0,3.0)
        print(bytes(raw_memory)) 

    def handleipChanged(self):
        pass
    def handlepushButton_parameterSetClicked(self,triggered):
        pid1_1 = self.ui.doubleSpinBox_pid1_1.value()
        pid1_2 = self.ui.doubleSpinBox_pid1_2.value()
        pid1_3 = self.ui.doubleSpinBox_pid1_3.value()
        pid2_1 = self.ui.doubleSpinBox_pid2_1.value()
        pid2_2 = self.ui.doubleSpinBox_pid2_2.value()
        pid2_3 = self.ui.doubleSpinBox_pid2_3.value()
        pid3_1 = self.ui.doubleSpinBox_pid3_1.value()
        pid3_2 = self.ui.doubleSpinBox_pid3_2.value()
        pid3_3 = self.ui.doubleSpinBox_pid3_3.value()
        
        raw_memory  = ctypes.create_string_buffer(b"",32)
        self.zipfloat2array3(raw_memory,0x01,pid1_1,pid1_2,pid1_3)
        ComManger.instance().sendData2Stm32(raw_memory)
        time.sleep(0.3)

        raw_memory  = ctypes.create_string_buffer(b"",32)
        self.zipfloat2array3(raw_memory,0x02,pid2_1,pid2_2,pid2_3)
        ComManger.instance().sendData2Stm32(raw_memory)        
        time.sleep(0.3)

        self.zipfloat2array3(raw_memory,0x03,pid3_1,pid3_2,pid3_3)
        ComManger.instance().sendData2Stm32(raw_memory)        
        time.sleep(0.3)
        pass
    def handleDestPosNeed2Send(self,triggered):
        global pathPoints         
        print (pathPoints)
        if len(pathPoints) >= 1:
            x = pathPoints[0].x()
            y = pathPoints[0].y()
            raw_memory  = ctypes.create_string_buffer(b"",32)
            self.zipfloat2array3(raw_memory,0x04,x,y,self.ui.doubleSpinBox_pos_yaw_angle.value())
            ComManger.instance().sendData2Stm32(raw_memory)
            print("info,send path Points.s",x,y)
        else:
            print(None,"警告","似乎在屏幕上没有找到点哎……");                
