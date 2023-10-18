#ifndef SUDOKUWIDGET_H

#define SUDOKUWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <vector>

class SudokuWidget : public QWidget {
    Q_OBJECT

public:
    SudokuWidget(QWidget *parent = nullptr);
    const std::vector<int> valid_values{1,2,3,4,5,6,7,8,9};

private:
    QGridLayout *gridLayout;
    std::vector<QLineEdit *> cells;

    void createSudokuGrid();
    std::vector<std::vector<int>> generateInitialSudoku();
    bool checkGrid(std::vector<std::vector<int>> grid);
};

#endif // SUDOKUWIDGET_H
