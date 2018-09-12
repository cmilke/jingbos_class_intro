TARGET = rootTree

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)

FLAGS = $(ROOTCFLAGS)
LIBS = $(ROOTLIBS) $(ROOTGLIBS)

TARGET: $(SOURCE)
	@g++ $(TARGET).cc $(FLAGS) $(LIBS) -o $(TARGET)
