from PyQt5.QtWidgets import *
from PyQt5.QtCore import QObject,pyqtSignal,QTimer,QThread
from PyQt5.QtNetwork import QUdpSocket,QHostAddress
import ctypes
import socket

class ComManger(QThread):
    __instance=None       
    signalStm32IpChanged  = pyqtSignal(str)
    signalSerialData  = pyqtSignal(str)
    signalbeatData  = pyqtSignal(str)

    def handleWaitTimeout(self):
        print(None,"warning","TX Packet timeout.")
    def __init__(self):
        super(ComManger,self).__init__()
        self.udp_esp_serial_port = 8300
        self.udp_esp_port_beat = 8301

        self.stm32_port = 8800
        self.stm32ip = "192.168.0.7"
        # self.timeoutTimer = QTimer()
        # self.timeoutTimer.setSingleShot(True)
        # self.timeoutTimer.timeout.connect(self.handleWaitTimeout)
        self.start()      
        print("start_init_com")  
 
    def setHostip(self,ip):
        self.hostip = ip;
    def setSTM32ip(self,ip):
        self.stm32ip = ip
    def close(self):
        self.udp_esp_beat.close()
        self.udp_esp_serial.close()
    def run(self):
        hostAddr = '192.168.0.6'

        udp_esp_serial_socket  = QUdpSocket()
        udp_esp_serial_socket.bind(QHostAddress(hostAddr), 8300 )

        udp_esp_beat_socket  = QUdpSocket()
        udp_esp_beat_socket.bind(QHostAddress(hostAddr), 8301 )

        print("Enter threads")
        while True:
            if(udp_esp_beat_socket.hasPendingDatagrams()):
                r = udp_esp_beat_socket.readDatagram(32)
                if(len(r[0]) > 0):
                    self.signalbeatData.emit(str(r[0]))
            if(udp_esp_serial_socket.hasPendingDatagrams()):
                r = udp_esp_serial_socket.readDatagram(1024)
                if(len(r[0]) > 0):
                    a = ""
                    for x in r[0]:
                        a += str(int(x)) + " "
                    import time
                    self.signalSerialData.emit(str(time.time()) + str(len(r[0])) + a )
                    try:
                        self.signalSerialData.emit(str(time.time()) + str(r[0],encoding="utf-8") )                    
                    except:
                        self.signalSerialData.emit("decode failed.")                    
                
    def __new__(cls, *args, **kw):
        if ComManger.__instance is None:
            ComManger.__instance = super(ComManger,cls).__new__(cls, *args, **kw)
        return ComManger.__instance   
    def sendData2Stm32(self,da):
        da = bytes(da)
        print("send",da)        
        udp_socket = QUdpSocket()      
        udp_socket.writeDatagram(da,QHostAddress(self.stm32ip),self.stm32_port)
        udp_socket.flush()
        udp_socket.close()
    @staticmethod
    def instance():
        if ComManger.__instance is None:
            ComManger.__instance=ComManger()
        return ComManger.__instance        