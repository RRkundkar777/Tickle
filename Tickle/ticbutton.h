#ifndef TICBUTTON_H
#define TICBUTTON_H

#include <QWidget>
#include<QPushButton>

class TicButton:public QPushButton
{
    Q_OBJECT
private:
    int row,col;

public:
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
};

#endif // TICBUTTON_H
