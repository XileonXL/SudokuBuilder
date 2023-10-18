#include "sudokuWidget.h"

SudokuWidget::SudokuWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(400, 400);
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

    std::vector<std::vector<int>> initialSudoku = generateInitialSudoku();

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

std::vector<std::vector<int>> SudokuWidget::generateInitialSudoku() {
    std::vector<std::vector<int>> voidSudoku = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    return voidSudoku;
}

bool SudokuWidget::checkGrid(std::vector<std::vector<int>> grid) {
    bool isGridFull = true;
    for (int i = 0; i < 9 && isGridFull; ++i) {
        for (int j = 0; j < 9 && isGridFull; ++j) {
            if (grid[i][j] == 0) {
                isGridFull = false;
            }
        }
    }

    return isGridFull;
}


