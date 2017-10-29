CC=i386 g++
CC_WIN=i686-w64-mingw32-g++ -DWIN32_LEAN_AND_MEAN
RES_WIN=i686-w64-mingw32-windres
LINKER=i386 g++
CPP= main.cpp ModuleSet.cpp Module.cpp Forms/MainWindow.cpp Forms/FrmScriptEditor.cpp Tests.cpp
OBJS = main.o ModuleSet.o Module.o MainWindow.o FrmScriptEditor.o Tests.o
OBJSLINUX = $(patsubst %.o, obj/linux/%.o, $(OBJS))
OBJSWIN = $(patsubst %.o, obj/win/%.o, $(OBJS)) obj/win/icons.rc.o
OBJDIRLINUX=obj/linux/
OBJDIRWIN=obj/win/
DEBUG = -g
WXCONFIG=/home/logan/Documents/Libraries/wxWidgets-3.1.0/linux-i386/wx-config
WXCONFIGWIN=/home/logan/Documents/Libraries/wxWidgets-3.1.0/windows-i386/wx-config
WXLIBS= `$(WXCONFIG) --libs all --debug=yes --linkdeps`
WXLIBSWIN= `$(WXCONFIGWIN) --libs all --debug=yes` #--linkdeps`
#/ "--libs all" adds all parts of wxWidgets - needed for wxStyledTextBox
WXINCLUDES=`$(WXCONFIG) --cppflags`
WXINCLUDESWIN= `$(WXCONFIGWIN) --cppflags`
BOOSTINCDIR=-I/home/logan/Documents/Libraries/boost_1_65_1/
BOOSTLIBDIR=-L/home/logan/Documents/Libraries/boost_1_65_1/stage-lin-32/lib/
BOOSTLIBWIN=-L/home/logan/Documents/Libraries/boost_1_65_1/stage-win-32/lib/
BOOSTLIBS=-l:libboost_serialization.a -l:libboost_system.a -l:libboost_filesystem.a #static library
EXTRA_DBG=-g	#for debugging
EXTRA_REL=-O3
CFLAGS = -m32 -Wall -c $(DEBUG)
LFLAGS = -m32 $(DEBUG) $(WXLIBS) $(BOOSTLIBDIR) $(BOOSTLIBS)
LFLAGSWIN= -m32 -l:libwinpthread.dll.a -l:libpthread.dll.a -static-libgcc -static-libstdc++ $(DEBUG) $(WXLIBSWIN) $(BOOSTLIBWIN) $(BOOSTLIBS)
DEBUG_OUT= ./bin/Debug/SecureIT
RELEASE_OUT= ./bin/Release/SecureIT
RELEASE_OUT_WIN= ./bin/Release-Win/SecureIT.exe


all: Debug

cleanDebug: clean Debug

Debug: $(DEBUG_OUT)

Release: $(RELEASE_OUT)

WinRelease: $(RELEASE_OUT_WIN)


########	For Linux Build
$(RELEASE_OUT): $(OBJSLINUX)
	$(CC) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(RELEASE_OUT)
$(DEBUG_OUT): $(OBJSLINUX)
	$(LINKER) -o $(DEBUG_OUT) $(OBJSLINUX) $(LFLAGS)
$(OBJDIRLINUX)main.o: main.cpp main.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) main.cpp -o $(OBJDIRLINUX)main.o
$(OBJDIRLINUX)ModuleSet.o: ModuleSet.cpp ModuleSet.h Module.h Constants.hpp
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) ModuleSet.cpp -o $(OBJDIRLINUX)ModuleSet.o
$(OBJDIRLINUX)Module.o: Module.cpp Module.h Constants.hpp
	$(CC) $(CFLAGS) $(BOOSTINCDIR) Module.cpp -o $(OBJDIRLINUX)Module.o
$(OBJDIRLINUX)MainWindow.o: Forms/MainWindow.cpp Forms/MainWindow.h Forms/FrmScriptEditor.h ModuleSet.h Module.h Constants.hpp Tests.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) Forms/MainWindow.cpp -o $(OBJDIRLINUX)MainWindow.o
$(OBJDIRLINUX)FrmScriptEditor.o: Forms/FrmScriptEditor.cpp Forms/FrmScriptEditor.h Module.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) Forms/FrmScriptEditor.cpp -o $(OBJDIRLINUX)FrmScriptEditor.o
$(OBJDIRLINUX)Tests.o: Tests.cpp Tests.h Module.h Constants.hpp
	$(CC) $(CFLAGS) $(BOOSTINCDIR) Tests.cpp -o $(OBJDIRLINUX)Tests.o

########	For Windows Build
$(RELEASE_OUT_WIN): $(OBJSWIN)
	BOOSTLIBDIR=$(BOOSTLIBWIN)
	$(CC_WIN) $(OBJSWIN) $(LFLAGSWIN) $(WXLIBSWIN) -o $(RELEASE_OUT_WIN)
$(OBJDIRWIN)main.o: main.h
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDESWIN) main.cpp -o $(OBJDIRWIN)main.o
$(OBJDIRWIN)ModuleSet.o: ModuleSet.h Module.h Constants.hpp
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) ModuleSet.cpp -o $(OBJDIRWIN)ModuleSet.o
$(OBJDIRWIN)Module.o: Module.h Constants.hpp
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) Module.cpp -o $(OBJDIRWIN)Module.o
$(OBJDIRWIN)MainWindow.o: Forms/MainWindow.h Forms/FrmScriptEditor.h ModuleSet.h Module.h Constants.hpp Tests.h
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDESWIN) Forms/MainWindow.cpp -o $(OBJDIRWIN)MainWindow.o
$(OBJDIRWIN)FrmScriptEditor.o: Forms/FrmScriptEditor.h Module.h
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDESWIN) Forms/FrmScriptEditor.cpp -o $(OBJDIRWIN)FrmScriptEditor.o
$(OBJDIRWIN)Tests.o: Tests.h Module.h Constants.hpp
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) Tests.cpp -o $(OBJDIRWIN)Tests.o
$(OBJDIRWIN)icons.rc.o:
	$(RES_WIN) -iicons.rc -o $(OBJDIRWIN)icons.rc.o
#ReleaseWin.o:
#
#	$(CXX_WIN) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBWIN) $(BOOSTLIBS) -o $(RELEASE_OUT_WIN)

clean:
	#rm *.o
	rm ./obj/linux/*
