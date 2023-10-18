# Makefile para compilar un proyecto de Qt5 en C++
# Asegúrate de que Qt5 esté instalado en tu sistema.

# Directorios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
MOC_DIR = moc

# Compilador y opciones
CXX = g++
MOC = moc
CXXFLAGS = -std=c++11 -Wall -fPIC
QT_CXXFLAGS = $(shell pkg-config --cflags Qt5Widgets)
QT_LIBS = $(shell pkg-config --libs Qt5Widgets)
QT_INCLUDE = -I/usr/include/qt

# Archivos de origen y objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
MOC_SOURCES = $(wildcard $(INCLUDE_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
MOC_OBJECTS = $(patsubst $(INCLUDE_DIR)/%.h, $(MOC_DIR)/moc_%.cpp, $(MOC_SOURCES))

# Ejecutable
TARGET = SudokuBuilder

all: $(BUILD_DIR) $(MOC_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(MOC_DIR):
	mkdir -p $(MOC_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(QT_CXXFLAGS) $(QT_INCLUDE) -I$(INCLUDE_DIR) -o $@ -c $<

$(MOC_DIR)/moc_%.cpp: $(INCLUDE_DIR)/%.h
	$(MOC) $< -o $@

$(TARGET): $(OBJECTS) $(MOC_OBJECTS)
	$(CXX) $(CXXFLAGS) $(QT_CXXFLAGS) -o $@ $^ $(QT_LIBS)

clean:
	rm -rf $(BUILD_DIR) $(MOC_DIR) $(TARGET)

.PHONY: all clean

