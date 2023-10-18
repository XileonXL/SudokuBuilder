// sudokuWidget.cpp

#include "sudokuWidget.h"

SudokuWidget::SudokuWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(400, 400); // Tamaño de la ventana
    createSudokuGrid();
}

void SudokuWidget::createSudokuGrid() {
    gridLayout = new QGridLayout(this);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            QLineEdit *cell = new QLineEdit;
            cell->setAlignment(Qt::AlignCenter);
            cell->setMaxLength(1);
            cell->setFixedWidth(40);
            cell->setFixedHeight(40);

            cells.push_back(cell);
            gridLayout->addWidget(cell, i, j);
        }
    }

    std::vector<std::vector<int>> initialSudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int cellIndex = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (initialSudoku[i][j] != 0) {
                cells[cellIndex]->setText(QString::number(initialSudoku[i][j]));
                cells[cellIndex]->setReadOnly(true);
            }
            cellIndex++;
        }
    }

    setLayout(gridLayout);
}
