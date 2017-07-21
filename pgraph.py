# -*- coding: utf-8 -*-
"""
This example demonstrates many of the 2D plotting capabilities
in pyqtgraph. All of the plots may be panned/scaled by dragging with 
the left/right mouse buttons. Right click on any plot to show a context menu.
"""
import dataManager
from random import randint
import threading
from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg

class graphWidget(QWidget):
    def __init(self):
        super(QWidget,self).__init__()


    #QtGui.QApplication.setGraphicsSystem('raster')
    app = QtGui.QApplication([])
    #mw = QtGui.QMainWindow()
    #mw.resize(800,800)

    win = pg.GraphicsWindow(title="Basic plotting examples")
    win.resize(1000,600)
    win.setWindowTitle('pyqtgraph example: Plotting')

    # Enable antialiasing for prettier plots
    pg.setConfigOptions(antialias=True)




    p6 = win.addPlot(title="Updating plot")
    curve = p6.plot(pen='y')
    data = []
    ptr = 0

    def update():
        dm = dataManager.DataManager()
        dm.open()    
        while True:
            global curve, data, ptr, p6
            d = dm.getNextValue()
            if d:
                print(d)
                data.append(d)
            if len(data) > 100:
                del data[0]
    #    
    #         if ptr == 0:
    #             p6.enableAutoRange('xy', False)  ## stop auto-scaling after the first data set is plotted
    #         ptr += 1
    #         win.update()
    # p6.enableAutoRange('xy', False)
    def updatePlot():
        curve.setData(data)    
    thread  = threading.Thread(target=update,args=[])
    thread.start()
    timer = QtCore.QTimer()
    timer.timeout.connect(updatePlot)
    timer.start(50)
    ## Start Qt event loop unless running in interactive mode or using pyside.
