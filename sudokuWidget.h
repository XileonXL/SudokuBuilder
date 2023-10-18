// sudokuWidget.h

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

private:
    QGridLayout *gridLayout;
    std::vector<QLineEdit *> cells;

    void createSudokuGrid();
};

#endif // SUDOKUWIDGET_H
