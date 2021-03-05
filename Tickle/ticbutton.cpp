#include "ticbutton.h"
#include<QMessageBox>

// TicButton Constructor
TicButton::TicButton(QWidget*&):QPushButton()
{
}


// Setting Label of Buttons
void TicButton::setLabel()
{
    this->setText("_");
}

// Setting the Row of Button
void TicButton::setRow(int row)
{
    this->row = row;
}

// Getting the Row of Button
int TicButton::getRow()
{
    return this->row;
}

// Getting the Column of Button
int TicButton::getCol()
{
    return this->col;
}

// Setting the Column of Button
void TicButton::setCol(int col)
{
    this->col = col;
}

// Setting a Button if it is Clicked
int TicButton::setBtn(char array[3][3],int *player)
{
    // Message Box for Displaying a Warning
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Icon::Warning);
    messageBox.setWindowTitle(tr("Warning"));
    messageBox.setText("Slot Already Occpuied!!!\n Stop");
    messageBox.addButton(QMessageBox::Ok);

    // If it is Computers turn --> Tick O
    if(*player)
    {
        // If Button is UnClicked --> Click It
        if(this->text() == "_")
        {
            this->setStyleSheet("font-size: 100px;color:blue;");
            this->setText("O");
            array[this->row][this->col] = 'O';
            *player = 0;
        }
        // Else --> Display Error Message
        else
        {
            messageBox.exec();
        }
    }

    // Else click --> Tick X
    else
    {
        if(this->text() == "_")
        {
            this->setStyleSheet("font-size:100px;color:red;");
            this->setText("X");
            array[this->row][this->col] = 'X';
            *player = 1;
        }
        else
        {
            messageBox.exec();
        }
    }

    // If Any of Player wins --> Display Winning Message
    int winLose = evaluate(array);
    QMessageBox WinMessage;
    WinMessage.setIcon(QMessageBox::Icon::Warning);
    WinMessage.setWindowTitle(tr("Winner           "));
    WinMessage.addButton(QMessageBox::Ok);

    // Player 1 wins --> Show that Player 1 won
    if(winLose == 10)
    {
        WinMessage.setText("Player 1 Won the Game");
        WinMessage.exec();
        return winLose;
    }
    else if(winLose == -10)
    {
        WinMessage.setText("Player 2 Won the Game");
        WinMessage.exec();
        return winLose;
    }
    else if(winLose == -81)
    {
        WinMessage.setText("Game Draw");
        WinMessage.exec();
        return winLose;
    }
    return 0;
}

// This function checks if there are moves remaining on the board.
bool TicButton::areMovesLeft(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++){
            if (arr[i][j] == '_'){
                return true;
            }
        }
    }
    return false;
}

// Function to Check if Either Player Has Won
int TicButton::evaluate(char b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == 'X')
                return +10;
            else if (b[row][0] == 'O')
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == 'X')
                return +10;

            else if (b[0][col] == 'O')
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == 'X')
            return +10;
        else if (b[0][0] == 'O')
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == 'X')
            return +10;
        else if (b[0][2] == 'O')
            return -10;
    }

    // Else if none of them have won then and Moves are Remaining --> Return 0
    if(areMovesLeft(b))
    {
        return 0;
    }
    // Else --> Return
    return -81;
}

// Function to Reset Button Text
void TicButton::resetButton()
{
    this->setStyleSheet("font-size:100px;color:black;");
    this->setText("_");
}
