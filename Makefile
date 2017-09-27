CC= g++
CC_WIN=i686-w64-mingw32-g++
CPP= main.cpp ModuleAction.cpp ModuleScan.cpp Windows.cpp Forms/MainWindow.cpp Forms/FrmScriptEditor.cpp Tests.cpp
OBJS = main.o ModuleAction.o ModuleScan.o Windows.o CodeEditWin.o MainWindow.o FrmScriptEditor.o Tests.o
DEBUG = -g
WXLIBS= `wx-config --libs all --debug=yes --linkdeps`
#/ "--libs all" adds all parts of wxWidgets - needed for wxStyledTextBox
WXINCLUDES= `wx-config --cppflags`
BOOSTINCDIR=-I/home/logan/myprogs/libraries/boost_1_64_0/
BOOSTLIBDIR=-L/home/logan/myprogs/libraries/boost_1_64_0/stage/lib_linux/
BOOSTLIBWIN=-L/home/logan/myprogs/libraries/boost_1_64_0/stage/lib/
BOOSTLIBS=-l:libboost_serialization.a #static library
EXTRA_DBG=-g	#for debugging
EXTRA_REL=-O3
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(WXLIBS) $(BOOSTLIBDIR) $(BOOSTLIBS)
DEBUG_OUT= ./bin/Debug/SecureIT
RELEASE_OUT= ./bin/Release/SecureIT
RELEASE_OUT_WIN= ./bin/Release-Win/SecureIT.exe


all: Debug

cleanDebug: clean

Debug: $(OBJS)

	$(CC) $(OBJS) $(LFLAGS) -o $(DEBUG_OUT)
#	$(CC) $(EXTRA_DBG) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(DEBUG_OUT)

Release:

	$(CC) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(RELEASE_OUT)

main.o: main.h main.cpp Windows.h
#Tests.h Forms/MainWindow.h Forms/FrmScriptEditor.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) main.cpp

ModuleAction.o:
	$(CC) $(CFLAGS) $(BOOSTINCDIR) ModuleAction.cpp ModuleAction.h
ModuleScan.o: ModuleScan.cpp ModuleScan.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) ModuleScan.cpp ModuleScan.h Constants.hpp
Windows.o: Windows.cpp Windows.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) $(WXINCLUDES) Windows.cpp
CodeEditWin.o: CodeEditWin.cpp CodeEditWin.h Forms/FrmScriptEditor.h
	$(CC) $(CFLAGS) $(WXINCLUDES) CodeEditWin.cpp

MainWindow.o: Forms/MainWindow.cpp Forms/MainWindow.h
	$(CC) $(CFLAGS) $(WXINCLUDES) Forms/MainWindow.cpp
FrmScriptEditor.o: Forms/FrmScriptEditor.cpp Forms/FrmScriptEditor.h
	$(CC) $(CFLAGS) $(WXINCLUDES) Forms/FrmScriptEditor.cpp
Tests.o: Tests.cpp Tests.h
	$(CC) $(CFLAGS) $(BOOSTINCDIR) Tests.cpp

#ReleaseWin.o:
#
#	$(CXX_WIN) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBWIN) $(BOOSTLIBS) -o $(RELEASE_OUT_WIN)

clean:
	rm *.o
