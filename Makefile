CXX= g++
CPP= main.cpp ModuleAction.cpp ModuleScan.cpp MainWindow.cpp Tests.cpp
WXLIBS= `wx-config --libs --debug=yes --linkdeps`
WXINCLUDES= `wx-config --cppflags`
BOOSTINCDIR=-I~/myprogs/libraries/boost_1_64_0/
BOOSTLIBDIR=-L~/myprogs/libraries/boost_1_64_0/stage/lib/
BOOSTLIBS=-l:libboost_serialization.a #static library
DEBUG_OUT= ./bin/Debug/SecureIT
RELEASE_OUT= ./bin/Release/SecureIT
EXTRA_DBG=-g	#for debugging
EXTRA_REL=-O3

all: Debug Release

Debug:

	$(CXX) $(EXTRA_DBG) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(DEBUG_OUT)

Release:

	$(CXX) $(EXTRA_REL) $(CPP) $(WXLIBS) $(WXINCLUDES) $(BOOSTINCDIR) $(BOOSTLIBDIR) $(BOOSTLIBS) -o $(RELEASE_OUT)
