// main.cpp

#include <QApplication>
#include "sudokuWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SudokuWidget sudokuWidget;
    sudokuWidget.setWindowTitle("Sudoku Grid");
    sudokuWidget.show();
    return app.exec();
}
