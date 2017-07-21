
pyuic5="D:\PotableProgram\Anaconda3\Library\bin\pyuic5.bat"
all:ui_controlwidget.py ui_mainWindow.py
	cd cpp && $(MAKE) 
	echo $<
	python mainWindow.py
ui:ui_controlwidget.py ui_mainWindow.py
	echo "Convert ui to py finished."
ui_controlwidget.py:controlWidget.ui
	 $(pyuic5) -o ui_controlwidget.py controlWidget.ui
ui_mainWindow.py:mainWindow.ui
	$(pyuic5)  -o ui_mainWindow.py mainWindow.ui
clean:
	-rm -f cpp/astart.dll cpp/data.txt cpp/astart.exe

