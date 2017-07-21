PATH:=C://TDM-GCC-64/bin;$(PATH);
dll_name=astart.dll
headers= map.h judge.h
sources=main.c map.c hex.c judge_crc8.c
INCFLAGS = -I./
CPPFLAGS = -O2  $(INCFLAGS) -Wall -Wno-strict-aliasing -std=c99 -m64 -finput-charset=utf-8 -shared
LINKFLAGS = 
CPP = gcc
all:$(dll_name)
$(dll_name) : $(sources) $(headers) 
	gcc -v
	$(CPP) $(CPPFLAGS) $(sources) -o $(dll_name) $(LINKFLAGS)
clean:
	rm -f $(dll_name)
.PHONY : clean all	