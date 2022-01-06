#ifndef TICBUTTON_H
#define TICBUTTON_H

// Classes from which TicButton will inherit
#include <QWidget>
#include<QPushButton>

// The States of Game
#define DRAW +81
#define HUMAN +10
#define MACHINE -10
#define REJECTED -900


// Class TicButton inherited from QPushButton
class TicButton:public QPushButton
{
    Q_OBJECT
private:
    // Row and Column Numbers
    int row,col;

public:
    // Constructor
    TicButton(QWidget*&);
    // Function to Set Text to Button, check for win/lose/draw
    // update the Button accordingly and return the status
    int setBtn(char array[3][3],int *player);
    // Function to check whether if some moves are left
    static bool areMovesLeft(char array[3][3]);
    // Function to set the UI of button as empty
    void setLabel();
    // Function to check for win/lose/draw and return the status of the same
    static int evaluate(char array[3][3]);

    // Functions to get and set the row and column of button
    void setRow(int);
    void setCol(int);
    int getRow();
    int getCol();

    // Function to reset button i.e. set the button as empty (UI)
    void resetButton();
    // Function to print an array in two dimensions
    static void print2D(char array[3][3]);
    // Function to set a button UI as computer's (Computer Mode)
    void setCompStyle();
};

#endif // TICBUTTON_H
