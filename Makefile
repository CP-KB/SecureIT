CC=i386 g++
CC_WIN=i686-w64-mingw32-g++
LINKER=i386 g++
CPP= main.cpp ModuleSet.cpp Module.cpp Forms/MainWindow.cpp Forms/FrmScriptEditor.cpp Tests.cpp
OBJS = main.o ModuleSet.o Module.o MainWindow.o FrmScriptEditor.o Tests.o
OBJSLINUX = $(patsubst %.o, obj/linux/%.o, $(OBJS))
OBJSWIN = $(patsubst %.o, obj/win/%.o, $(OBJS))
OBJDIRLINUX=obj/linux/
OBJDIRWIN=obj/win/
DEBUG = -g
WXCONFIG=i386 wx-config #/home/logan/Documents/Libraries/wxWidgets-3.1.0/linux-i386/wx-config
WXCONFIGWIN=/home/administrator/Documents/Libraries/wxWidgets-3.1.0/windows-i386/wx-config
WXLIBS= `$(WXCONFIG) --libs all --debug=yes --linkdeps`
WXLIBSWIN= `$(WXCONFIGWIN) --libs all --debug=yes` #--linkdeps`
#/ "--libs all" adds all parts of wxWidgets - needed for wxStyledTextBox
WXINCLUDES=`$(WXCONFIG) --cppflags`
WXINCLUDESWIN= `$(WXCONFIGWIN) --prefix=/media/logan/MULTIBOOT/Portable/wxWidgets-3.10 --cppflags`
BOOSTINCDIR=-I/home/administrator/Documents/Libraries/boost_1_65_1/
BOOSTLIBDIR=-L/home/administrator/Documents/Libraries/boost_1_65_1/stage-lin-32/lib/
BOOSTLIBWIN=-L/home/administrator/Documents/Libraries/boost_1_65_1/stage-win-32/lib/
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
$(OBJDIRLINUX)main.o: main.h main.cpp
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) main.cpp -o $(OBJDIRLINUX)main.o

$(OBJDIRLINUX)ModuleSet.o: ModuleSet.cpp ModuleSet.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) ModuleSet.cpp -o $(OBJDIRLINUX)ModuleSet.o
#$(OBJDIRLINUX)ModuleAction.o:
#	$(CC) $(CFLAGS) $(BOOSTINCDIR) ModuleAction.cpp -o $(OBJDIRLINUX)ModuleAction.o
$(OBJDIRLINUX)Module.o: Module.cpp Module.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) Module.cpp -o $(OBJDIRLINUX)Module.o
#$(OBJDIRLINUX)Windows.o: Windows.cpp Windows.h
#	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) Windows.cpp -o $(OBJDIRLINUX)Windows.o
#$(OBJDIRLINUX)CodeEditWin.o: CodeEditWin.cpp CodeEditWin.h Forms/FrmScriptEditor.h
#	$(CC) $(CFLAGS) $(WXINCLUDES) CodeEditWin.cpp -o $(OBJDIRLINUX)CodeEditWin.o
$(OBJDIRLINUX)MainWindow.o: Forms/MainWindow.cpp Forms/MainWindow.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) Forms/MainWindow.cpp -o $(OBJDIRLINUX)MainWindow.o
$(OBJDIRLINUX)FrmScriptEditor.o: Forms/FrmScriptEditor.cpp Forms/FrmScriptEditor.h
	$(CC) $(CFLAGS) $(WXINCLUDES) Forms/FrmScriptEditor.cpp -o $(OBJDIRLINUX)FrmScriptEditor.o
$(OBJDIRLINUX)Tests.o: Tests.cpp Tests.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) Tests.cpp -o $(OBJDIRLINUX)Tests.o

########	For Windows Build
$(RELEASE_OUT_WIN): $(OBJSWIN)
	CC=$(CC_WIN)
	BOOSTLIBDIR=$(BOOSTLIBWIN)
	$(CC_WIN) $(OBJSWIN) $(LFLAGSWIN) $(WXLIBSWIN) -o $(RELEASE_OUT_WIN)
$(OBJDIRWIN)main.o: main.h main.cpp
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDESWIN) main.cpp -o $(OBJDIRWIN)main.o

$(OBJDIRWIN)ModuleSet.o:
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) ModuleSet.cpp -o $(OBJDIRWIN)ModuleSet.o
#$(OBJDIRWIN)ModuleAction.o:
#	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) ModuleAction.cpp -o $(OBJDIRWIN)ModuleAction.o
$(OBJDIRWIN)Module.o: Module.cpp Module.h
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) Module.cpp -o $(OBJDIRWIN)Module.o
#$(OBJDIRWIN)Windows.o: Windows.cpp Windows.h
#	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDESWIN) Windows.cpp -o $(OBJDIRWIN)Windows.o
#$(OBJDIRWIN)CodeEditWin.o: CodeEditWin.cpp CodeEditWin.h Forms/FrmScriptEditor.h
#	$(CC_WIN) $(CFLAGS) $(WXINCLUDESWIN) CodeEditWin.cpp -o $(OBJDIRWIN)CodeEditWin.o
$(OBJDIRWIN)MainWindow.o: Forms/MainWindow.cpp Forms/MainWindow.h
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDESWIN) Forms/MainWindow.cpp -o $(OBJDIRWIN)MainWindow.o
$(OBJDIRWIN)FrmScriptEditor.o: Forms/FrmScriptEditor.cpp Forms/FrmScriptEditor.h
	$(CC_WIN) $(CFLAGS) $(WXINCLUDESWIN) Forms/FrmScriptEditor.cpp -o $(OBJDIRWIN)FrmScriptEditor.o
$(OBJDIRWIN)Tests.o: Tests.cpp Tests.h
	$(CC_WIN) $(CFLAGS) $(BOOSTINCDIR) Tests.cpp -o $(OBJDIRWIN)Tests.o
#ReleaseWin.o:
#
#	$(CXX_WIN) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBWIN) $(BOOSTLIBS) -o $(RELEASE_OUT_WIN)

clean:
	#rm *.o
	rm ./obj/linux/*
