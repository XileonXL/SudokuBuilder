# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Qt flags and libraries
QT_CXXFLAGS = $(shell pkg-config --cflags Qt5Widgets)
QT_LIBS = $(shell pkg-config --libs Qt5Widgets)

# Target executable
TARGET = sudoku_app

# QT generated files directory
QT_DIR = qt_utils

# Source files
SOURCES = main.cpp sudokuWidget.cpp
MOC_SOURCES = $(QT_DIR)/moc_sudokuWidget.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o) $(MOC_SOURCES:.cpp=.o)


.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(QT_LIBS)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(QT_CXXFLAGS) -c $< -o $@

$(QT_DIR)/moc_sudokuWidget.cpp: sudokuWidget.h
	mkdir -p $(QT_DIR)
	moc $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET) $(QT_DIR)

