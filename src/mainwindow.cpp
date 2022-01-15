// QT System Libs
#include<QDebug>
#include<QMessageBox>

// mainwindow and config classes
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stack.h"
#include"config.h"

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // The player who will make first move is Player1/Human
    ui->radioButton_Player->setChecked(1);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Function to ToggleMode
void MainWindow::ToggleMode(int *mode)
{
    // If current mode is computer --> set the current mode as two player
    if(*mode == computer)
    {
        *mode = twoPlayer;
        ui->radioButton_Player->setText("Player One");
        ui->radioButton_Player_2->setText("Player Two");
    }
    // Else --> set the current mode as computer
    else if(*mode == twoPlayer)
    {
        *mode = computer;
        ui->radioButton_Player->setText("Human");
        ui->radioButton_Player_2->setText("Computer");
    }
    tdebug("Toggled mode",TC_DBG,__FILE__);
}

// Function to Toggle Player in UI
void MainWindow::TogglePlayer()
{
    // If Player is Player2/Computer --> Set Player1/Human
    if(player)
    {
        ui->radioButton_Player->setChecked(0);
        ui->radioButton_Player_2->setChecked(1);
    }
    // Else
    else
    {
        ui->radioButton_Player->setChecked(1);
        ui->radioButton_Player_2->setChecked(0);
    }
}

//  Function to Restart the Game
void MainWindow::RestartGame()
{
    // Resetting all the TicButtons in MainWindow
    ui->btn_0_0->resetButton();
    ui->btn_0_1->resetButton();
    ui->btn_0_2->resetButton();
    ui->btn_1_0->resetButton();
    ui->btn_1_1->resetButton();
    ui->btn_1_2->resetButton();
    ui->btn_2_0->resetButton();
    ui->btn_2_1->resetButton();
    ui->btn_2_2->resetButton();

    // Resetting the gameArray
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            gameArray[i][j] = '_';
        }
    }

    // Resetting player to Player1/Human
    player = 0;

    // Displaying the changes in UI
    TogglePlayer();
}

/*------------------------------------------Button Clicked Events---------------------------------------------*/
void MainWindow::on_btn_0_0_clicked()
{
    // Setting the Row and Column
    ui->btn_0_0->setRow(0);
    ui->btn_0_0->setCol(0);

    // Button Clicked Event
    // Status/Mode --> which decides the mode of game
    int status;
    // If mode is 2 player --> call setBtn
    if(mode)
    {
        status = ui->btn_0_0->setBtn(gameArray,&player);
    }
    // If mode is computer --> call setBtnAuto
    else
    {
        // Note that setBtn option automatically pushes both player and computer moves to stack
        status = setBtnAuto(gameArray,&player,ui->btn_0_0);
    }

    // If Status is either draw, win or lose --> Call Restart Game
    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else if mode is 2 player Push the single move into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_0_0->getRow();
        int col = ui->btn_0_0->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_0_0->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI (For Both Modes)
    TogglePlayer();
}

void MainWindow::on_btn_0_1_clicked()
{
    ui->btn_0_1->setRow(0);
    ui->btn_0_1->setCol(1);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_0_1->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_0_1);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_0_1->getRow();
        int col = ui->btn_0_1->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_0_1->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);
        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
        // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_0_2_clicked()
{
    ui->btn_0_2->setRow(0);
    ui->btn_0_2->setCol(2);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_0_2->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_0_2);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_0_2->getRow();
        int col = ui->btn_0_2->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_0_2->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_1_0_clicked()
{
    ui->btn_1_0->setRow(1);
    ui->btn_1_0->setCol(0);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_1_0->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_1_0);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_1_0->getRow();
        int col = ui->btn_1_0->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_1_0->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_1_1_clicked()
{
    ui->btn_1_1->setRow(1);
    ui->btn_1_1->setCol(1);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_1_1->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_1_1);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_1_1->getRow();
        int col = ui->btn_1_1->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_1_1->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_1_2_clicked()
{
    ui->btn_1_2->setRow(1);
    ui->btn_1_2->setCol(2);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_1_2->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_1_2);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_1_2->getRow();
        int col = ui->btn_1_2->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_1_2->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_2_0_clicked()
{
    ui->btn_2_0->setRow(2);
    ui->btn_2_0->setCol(0);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_2_0->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_2_0);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_2_0->getRow();
        int col = ui->btn_2_0->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_2_0->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_2_1_clicked()
{
    ui->btn_2_1->setRow(2);
    ui->btn_2_1->setCol(1);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_2_1->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_2_1);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_2_1->getRow();
        int col = ui->btn_2_1->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_2_1->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_2_2_clicked()
{
    ui->btn_2_2->setRow(2);
    ui->btn_2_2->setCol(2);

    // Button Clicked Event
    int status;
    if(mode)
    {
        status = ui->btn_2_2->setBtn(gameArray,&player);
    }
    else
    {
        status = setBtnAuto(gameArray,&player,ui->btn_2_2);
    }

    if(status == MACHINE || status == HUMAN || status == DRAW)
    {
        RestartGame();
        return;
    }

    // Else Push the move data into moveStack
    else if((!status || status == REJECTED) && mode)
    {
        int row = ui->btn_2_2->getRow();
        int col = ui->btn_2_2->getCol();

        // Pushing the button character
        QByteArray ba = ui->btn_2_2->text().toLatin1();
        char* data = ba.data();

        // Pushing into the Stack
        pushIntoStack(&moveStack,row,col,data);

        // Debugging
        if(DEBUGGER)
        {
            qDebug() << "Row:"<<row<< "Col:" << col << "Value:" << stackTopData(moveStack);
        }
    }
    // The Change of Player must be reflected in UI
    TogglePlayer();
}



/*-----------------------------------------Other Functions----------------------------------------------------*/

// Function to Revert a Move
void MainWindow::revertMove(char array[3][3])
{
    // Allocating memory a new move
    struct move* m1 = (struct move*) malloc(sizeof(struct move));
    // If stack is empty --> return
    if(moveStack == NULL)
    {
        return;
    }
    // Else pop a move from stack and store it into a move
    popFromStack(&moveStack,&m1);

    // Setting the Variables
    int row = m1->row;
    int col = m1->col;

    // Reset that Array Element
    array[row][col] = '_';

    // Revert the GUI of the respective row and column
    switch(row)
    {
        case 0:
            switch(col)
            {
                case 0:
                    ui->btn_0_0->resetButton();
                    break;
                case 1:
                    ui->btn_0_1->resetButton();
                    break;
                case 2:
                    ui->btn_0_2->resetButton();
                    break;
            }
            break;
        case 1:
            switch(col)
            {
                case 0:
                    ui->btn_1_0->resetButton();
                    break;
                case 1:
                    ui->btn_1_1->resetButton();
                    break;
                case 2:
                    ui->btn_1_2->resetButton();
                    break;
            }
        break;
        case 2:
            switch(col)
            {
                case 0:
                    ui->btn_2_0->resetButton();
                    break;
                case 1:
                    ui->btn_2_1->resetButton();
                    break;
                case 2:
                    ui->btn_2_2->resetButton();
                    break;
            }
            break;
    }
}

// If the Revert Button is Clicked --> Revert the Move
void MainWindow::on_revert_btn_clicked()
{
    revertMove(gameArray);
}

// The miniMax algorithm
static int miniMax(char board[3][3], int depth, bool isMax)
{
    // Evaluating the Board
    int score = TicButton::evaluate(board);

    // If Maximizer wins --> return the score
    if (score == HUMAN)
    {
        return score - depth;
    }

    // If Minimizer wins --> return the score
    if (score == MACHINE)
    {
        return score - depth;
    }

    // If Game Draw --> return the score
    if (TicButton::areMovesLeft(board)==false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = 'X';

                    // Recursively call the miniMax function
                    best = std::max(best,miniMax(board, depth+1, !isMax) );

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        // Return the best
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = 'O';

                    // Recursively call the miniMax function
                    best = std::min(best,miniMax(board, depth+1, !isMax));

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        // Return the best move
        return best;
    }
}


// This will return the best possible move for the player
MainWindow::Location MainWindow::Optimise(char board[3][3])
{
    // The best score
    int optimus = -1000;
    // The structure to store Optimum move
    MainWindow::Location Optimum;
    // Initial values of row and col
    Optimum.row = -1;
    Optimum.col = -1;

    // Traverse all cells, evaluate minimax function for all empty cells. And return the cell with optimal value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (board[i][j]=='_')
            {
                // Make the move
                board[i][j] = 'X';

                // compute evaluation function for this
                // move.
                int current = miniMax(board, 0, false);

                // Undo the move
                board[i][j] = '_';

                // If the value of the current move is
                // more than the best value, then update
                // best
                if (current > optimus)
                {
                    Optimum.row = i;
                    Optimum.col = j;
                    optimus = current;
                }
            }
        }
    }
    return Optimum;
}

// Function to Set Button, Compute the best move, modify the GameArray, push player and computer to the moveStack,check for win/lose/draw and return a status
int MainWindow::setBtnAuto(char array[3][3],int *player,TicButton *t1)
{
    // Message Box for Displaying a Warning (In case the Button is already occupied)
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Icon::Warning);
    messageBox.setWindowTitle(("Warning"));
    messageBox.setText("Slot Already Occpuied!!!\n Stop");
    messageBox.addButton(QMessageBox::Ok);


        // If Button is UnClicked --> Click It
        if(t1->text() == "_")
        {
            t1->setStyleSheet("font-size: 100px;color:red;");
            t1->setText("X");
            array[t1->getRow()][t1->getCol()] = 'X';

            // Pushing player's move on stack
            // Pushing the button character
            QString s1 = "X";
            QByteArray ba = s1.toLatin1();
            char* data = ba.data();
            pushIntoStack(&moveStack,t1->getRow(),t1->getCol(),data);
            *player = 0;
        }
        // Else --> Display Error Message
        else
        {
            messageBox.exec();
            return 0;
        }

        // Computing the Best move and making the changes
        MainWindow::Location opti = this->Optimise(array);
        int row = opti.row;
        int col = opti.col;

        array[row][col] = 'O';

        qDebug() << row << " " << col ;

        switch(row)
        {
            case 0:
                switch(col)
                {
                    case 0:
                        ui->btn_0_0->setCompStyle();
                        break;
                    case 1:
                        ui->btn_0_1->setCompStyle();
                        break;
                    case 2:
                        ui->btn_0_2->setCompStyle();
                        break;
                }
                break;
            case 1:
                switch(col)
                {
                    case 0:
                        ui->btn_1_0->setCompStyle();
                        break;
                    case 1:
                        ui->btn_1_1->setCompStyle();
                        break;
                    case 2:
                        ui->btn_1_2->setCompStyle();
                        break;
                }
            break;
            case 2:
                switch(col)
                {
                    case 0:
                        ui->btn_2_0->setCompStyle();
                        break;
                    case 1:
                        ui->btn_2_1->setCompStyle();
                        break;
                    case 2:
                        ui->btn_2_2->setCompStyle();
                        break;
                }
                break;
        }

    // Pushing computer's move on stack
    // Pushing the button character
    QString s1 = "O";
    QByteArray ba = s1.toLatin1();
    char* data = ba.data();
    pushIntoStack(&moveStack,row,col,data);

    // Printing the Array
    if(DEBUGGER == on)
    {
        TicButton::print2D(array);
    }

    // If Any of Player wins --> Display a Winning Message
    // Evaluate the Array for patterns of X and O
    int winLose = TicButton::evaluate(array);

    // Winning Message
    QMessageBox WinMessage;
    WinMessage.setIcon(QMessageBox::Icon::Warning);
    WinMessage.setWindowTitle(tr("Winner             "));

    // Player 1 wins --> Show that Player 1 won
    if(winLose == HUMAN)
    {
        WinMessage.setText("You have Won the Game \n Do you want to check out the moves?");
        WinMessage.addButton("  No, Restart the Game  " ,QMessageBox::AcceptRole);
        WinMessage.addButton("  Yes I want to check  " ,QMessageBox::RejectRole);
        int rejected = WinMessage.exec();
        // If losing player accepts defeat -->  return winLose
        if(!rejected)
        {
            return winLose;
        }
        // If losing player rejects defeat --> return -900
        else if(rejected == 1)
        {
            return REJECTED;
        }
    }
    // Computer wins --> Show that Computer won
    else if(winLose == MACHINE)
    {
        WinMessage.setText("Computer Won the Game \n Do you accept the defeat?");
        WinMessage.addButton("Accept" ,QMessageBox::AcceptRole);
        WinMessage.addButton("Reject" ,QMessageBox::RejectRole);
        int rejected = WinMessage.exec();
        // If losing player accepts defeat -->  return winLose
        if(!rejected)
        {
            return winLose;
        }
        // If losing player rejects defeat --> return -900
        else if(rejected == 1)
        {
            return REJECTED;
        }
    }
    // If Game Draw --> Show that Game is Draw
    else if(winLose == DRAW)
    {
        WinMessage.setText("Game Draw");
        WinMessage.exec();
        return winLose;
    }
    // Game is in progress
    return 0;
}

// --------------------------------------- Button Click Events ---------------------------------------------//
// On Restart Button Clicked --> Restart Game
void MainWindow::on_RestartGame_clicked()
{
    RestartGame();
}

// Switch Mode Click Event
void MainWindow::on_switchMode_clicked()
{
    ToggleMode(&mode);
}
