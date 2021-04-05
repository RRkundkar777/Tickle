#include "ticbutton.h"

// For using messageBox functionality
#include<QMessageBox>

// For debugging
#include<QDebug>

// Enum for TDEBUGGER
enum
{
  on = 1,
  off = 0
};
// TDEBUGGER
int TDEBUGGER = on;

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

// Setting the Column of Button
void TicButton::setCol(int col)
{
    this->col = col;
}

// Getting the Column of Button
int TicButton::getCol()
{
    return this->col;
}


// Setting a Button if it is Clicked
// This function will return a status
// This statuses will be
    // Either player winning and accepting the win
    // Either player winning and not accepting the win
    // The Game is Draw
    // The Game is in Progress
// This will also set a button acccording to the current player and vacancy of a slot

int TicButton::setBtn(char array[3][3],int *player)
{
    // Message Box for Displaying a Warning (In case the Button is already occupied)
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

    // If it is player's turn --> Tick X
    else
    {
        // If Button is UnClicked --> Click It
        if(this->text() == "_")
        {
            this->setStyleSheet("font-size:100px;color:red;");
            this->setText("X");
            array[this->row][this->col] = 'X';
            *player = 1;
        }
        // Else --> Display Error Message
        else
        {
            messageBox.exec();
        }
    }

    // Printing the Array
    if(TDEBUGGER)
    {
        print2D(array);
    }

    // If Any of Player wins --> Display a Winning Message
    // Evaluate the Array for patterns of X and O
    int winLose = evaluate(array);

    // Winning Message
    QMessageBox WinMessage;
    WinMessage.setIcon(QMessageBox::Icon::Warning);
    WinMessage.setWindowTitle(tr("Winner             "));
    WinMessage.addButton("Accept" ,QMessageBox::AcceptRole);
    WinMessage.addButton("Reject" ,QMessageBox::RejectRole);

    // Player 1 wins --> Show that Player 1 won
    if(winLose == 10)
    {
        WinMessage.setText("Player 1 has Won the Game \n Do you accept the defeat?");

        int rejected = WinMessage.exec();
        // If losing player accepts defeat -->  return winLose
        if(!rejected)
        {
            return winLose;
        }
        // If losing player rejects defeat --> return -900
        else if(rejected == 1)
        {
            return -900;
        }
    }
    // Player 2 wins --> Show that Player 2 won
    else if(winLose == -10)
    {
        WinMessage.setText("Player 2 Won the Game \n Do you accept the defeat?");
        int rejected = WinMessage.exec();
        // If losing player accepts defeat -->  return winLose
        if(!rejected)
        {
            return winLose;
        }
        // If losing player rejects defeat --> return -900
        else if(rejected == 1)
        {
            return -900;
        }
    }
    // If Game Draw --> Show that Game is Draw
    else if(winLose == -81)
    {
        WinMessage.setText("Game Draw");
        WinMessage.exec();
        return winLose;
    }
    // Game is in progress
    return 0;
}

// This function checks if there are moves remaining on the board.
bool TicButton::areMovesLeft(char arr[3][3])
{
    // Checking the complete array for moves
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
int TicButton::evaluate(char array[3][3])
{
    // Checking Rows for patterns of X or O
    for (int row = 0; row < 3; row++)
    {
        // If any row is of either Xs or Os --> Return the status accordingly
        if(array[row][0] == array[row][1] && array[row][1] == array[row][2])
        {
            if (array[row][0] == 'X')
                return +10;
            else if (array[row][0] == 'O')
                return -10;
        }
    }

    // Checking columns for patterns of X or O
    for (int col = 0; col < 3; col++)
    {
        // If any column is of either Xs or Os --> Return the status accordingly
        if (array[0][col] == array[1][col] && array[1][col] == array[2][col])
        {
            if (array[0][col] == 'X')
                return +10;

            else if (array[0][col] == 'O')
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.

    // Checking the principle diagonal
    if (array[0][0] == array[1][1] && array[1][1] == array[2][2])
    {
        if (array[0][0] == 'X')
            return +10;
        else if (array[0][0] == 'O')
            return -10;
    }

    // Checking the non-principle diagonal
    if (array[0][2] == array[1][1] && array[1][1] == array[2][0])
    {
        if (array[0][2] == 'X')
            return +10;
        else if (array[0][2] == 'O')
            return -10;
    }

    // Else if none of them have won then and Moves are Remaining --> Return 0
    // That is Game is in Progress
    if(areMovesLeft(array))
    {
        return 0;
    }
    // Else --> Return -81
    // That is Game Draw
    return -81;
}

// Function to Reset Button Text
void TicButton::resetButton()
{
    this->setStyleSheet("font-size:100px;color:black;");
    this->setText("_");
}

// Function to Print 2D Game Array
void TicButton::print2D(char array[3][3])
{
    for (int i = 0;i < 3;i++)
    {
        QDebug deb = qDebug();
        for (int j = 0;j < 3;j++)
        {
            deb << array[i][j];
        }
    }
    qDebug() << " ";
}

//int minimax(char board[3][3], int depth, bool isMax)
//{
//    int score = evaluate(board);

//    // If Maximizer has won the game return his/her
//    // evaluated score
//    if (score == 10)
//        return score;

//    // If Minimizer has won the game return his/her
//    // evaluated score
//    if (score == -10)
//        return score;

//    // If there are no more moves and no winner then
//    // it is a tie
//    if (isMovesLeft(board)==false)
//        return 0;

//    // If this maximizer's move
//    if (isMax)
//    {
//        int best = -1000;

//        // Traverse all cells
//        for (int i = 0; i<3; i++)
//        {
//            for (int j = 0; j<3; j++)
//            {
//                // Check if cell is empty
//                if (board[i][j]=='_')
//                {
//                    // Make the move
//                    board[i][j] = player;

//                    // Call minimax recursively and choose
//                    // the maximum value
//                    best = max( best,
//                        minimax(board, depth+1, !isMax) );

//                    // Undo the move
//                    board[i][j] = '_';
//                }
//            }
//        }
//        return best;
//    }

//    // If this minimizer's move
//    else
//    {
//        int best = 1000;

//        // Traverse all cells
//        for (int i = 0; i<3; i++)
//        {
//            for (int j = 0; j<3; j++)
//            {
//                // Check if cell is empty
//                if (board[i][j]=='_')
//                {
//                    // Make the move
//                    board[i][j] = opponent;

//                    // Call minimax recursively and choose
//                    // the minimum value
//                    best = min(best,
//                           minimax(board, depth+1, !isMax));

//                    // Undo the move
//                    board[i][j] = '_';
//                }
//            }
//        }
//        return best;
//    }
//}
