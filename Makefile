CXX= g++
CXX_WIN=i686-w64-mingw32-g++
CPP= main.cpp ModuleAction.cpp ModuleScan.cpp Windows.cpp Forms/MainWindow.cpp Tests.cpp
WXLIBS= `wx-config --libs --debug=yes --linkdeps`
WXINCLUDES= `wx-config --cppflags`
BOOSTINCDIR=-I/home/logan/myprogs/libraries/boost_1_64_0/
BOOSTLIBDIR=-L/home/logan/myprogs/libraries/boost_1_64_0/stage/lib_linux/
BOOSTLIBWIN=-L/home/logan/myprogs/libraries/boost_1_64_0/stage/lib/
BOOSTLIBS=-l:libboost_serialization.a #static library
DEBUG_OUT= ./bin/Debug/SecureIT
RELEASE_OUT= ./bin/Release/SecureIT
RELEASE_OUT_WIN= ./bin/Release-Win/SecureIT.exe
EXTRA_DBG=-g	#for debugging
EXTRA_REL=-O3

all: Debug Release

Debug:

	$(CXX) $(EXTRA_DBG) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(DEBUG_OUT)

Release:

	$(CXX) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(RELEASE_OUT)

ReleaseWin:

	$(CXX_WIN) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBWIN) $(BOOSTLIBS) -o $(RELEASE_OUT_WIN)
