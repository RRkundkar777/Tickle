#include "mainwindow.h"
#include "ui_mainwindow.h"

// For Debugging
#include<QDebug>

// Enum for Debugger
enum
{
  on = 1,
  off = 0
};
// Debugger
int DEBUGGER = on;

// Function definition of Constructor, Destructor and Member Functions
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_Player->setChecked(1);
}

// Destructor of MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

// The Array Storing the State of the Board
char gameArray[3][3] = {{'_','_','_'},
                        {'_','_','_'},
                        {'_','_','_'}};

// player variable for deciding the currently active player
int player = 0;

// Function to Toggle Player in UI
void MainWindow::TogglePlayer()
{
    if(player)
    {
        ui->radioButton_Player->setChecked(0);
        ui->radioButton_Player_2->setChecked(1);
    }
    else
    {
        ui->radioButton_Player->setChecked(1);
        ui->radioButton_Player_2->setChecked(0);
    }
}

//  Function to Restart the Game
void MainWindow::RestartGame()
{
    // Resetting the Buttons in MainWindow
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
}

// On Restart Button Clicked --> Restart Game
void MainWindow::on_RestartGame_clicked()
{
    RestartGame();
}

/*---------------------------------------Stack Section -------------------------------------------------------*/
// Structure of a move
struct move
{
   int row,col;
   char data;
   struct move* next;
};

typedef move* stack;

// Functions on a Stack
void init(stack *S1)
{
    *S1 = NULL;
}

void pushIntoStack(stack *S1,int row,int col,char* data)
{
    // Initialising a newnode
    move *m1 = (move*)malloc(sizeof(move));
    m1->row = row;
    m1->col = col;
    m1->data = *data;
    if(*S1 == NULL)
    {
       *S1 = m1;
        return;
    }

    // Pushing into Stack
    m1->next = (*S1);
    (*S1) = m1;
}

void popFromStack(stack *S1,move** m1)
{
    if((*S1) == NULL)
    {
            qDebug() << "Stack Empty\n";
    }
    // If Stack is Unary --> Set it as NULL
    else if((*S1)->next == NULL)
    {
            move* traveller = *S1;
            *S1 = NULL;
            (*m1)->col = traveller->col;
            (*m1)->row = traveller->row;
            (*m1)->data = traveller->data;
            free(traveller);

    }
    // Else --> Remove an element from the stack
    else
        {
            move* traveller = *S1;
            *S1 = (*S1)->next;
            (*m1)->col = traveller->col;
            (*m1)->row = traveller->row;
            (*m1)->data = traveller->data;
            free(traveller);
        }
}

// Top of the Stack
char stackTopData(stack S1)
{
    return S1->data;
}

// MoveStack for recording the moves
stack moveStack = NULL;



/*------------------------------------------Button Clicked Events---------------------------------------------*/
void MainWindow::on_btn_0_0_clicked()
{
    // Setting the Row and Column
    ui->btn_0_0->setRow(0);
    ui->btn_0_0->setCol(0);

    // Button Clicked Event
    int status = ui->btn_0_0->setBtn(gameArray,&player);

    // If Status is either draw, win or lose --> Call Restart Game
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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
        // The Change of Player must be reflected in UI
        // The Change of Player must be reflected in UI
    TogglePlayer();
}

void MainWindow::on_btn_0_1_clicked()
{
    ui->btn_0_1->setRow(0);
    ui->btn_0_1->setCol(1);

    int status = ui->btn_0_1->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_0_2->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_1_0->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_1_1->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_1_2->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_2_0->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_2_1->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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

    int status = ui->btn_2_2->setBtn(gameArray,&player);
    if(status == -10 || status == 10 || status == -81)
    {
        RestartGame();
    }

    // Else Push the move data into moveStack
    else if(!status || status == -900)
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
    // Taking out a new move
    struct move* m1 = (struct move*) malloc(sizeof(struct move));
    if(moveStack == NULL)
    {
        return;
    }
    popFromStack(&moveStack,&m1);

    // Setting the Variables
    int row = m1->row;
    int col = m1->col;

    // Resetting the Array Elements
    array[row][col] = '_';

    // Reverting the GUI with respect to row and column
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
