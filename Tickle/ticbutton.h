#ifndef TICBUTTON_H
#define TICBUTTON_H

#include <QWidget>
#include<QPushButton>

// Class TicButton derived from QPushButton
class TicButton:public QPushButton
{
    Q_OBJECT
private:
    // Row and Column Numbers
    int row,col;

public:
    // Constructor
    TicButton(QWidget*&);
    int setBtn(char array[3][3],int *player);
    static bool areMovesLeft(char array[3][3]);
    void setLabel();
    static int evaluate(char array[3][3]);
    void setRow(int);
    void setCol(int);
    int getRow();
    int getCol();
    void resetButton();
    static void print2D(char array[3][3]);
    static int miniMax(char board[3][3],int depth,bool isMax);
};

#endif // TICBUTTON_H
