#include "mainwindow.h"
#include "ui_mainwindow.h"

// Function definition of Constructor, Destructor and Member Functions
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::on_StartGame_clicked()
{
    this->RestartGame();
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

// Button Clicked Events
void MainWindow::on_btn_0_0_clicked()
{
    ui->btn_0_0->setRow(0);
    ui->btn_0_0->setCol(0);
    int status = ui->btn_0_0->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_0_1_clicked()
{
    ui->btn_0_1->setRow(0);
    ui->btn_0_1->setCol(1);
    int status = ui->btn_0_1->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_0_2_clicked()
{
    ui->btn_0_2->setRow(0);
    ui->btn_0_2->setCol(2);
    int status = ui->btn_0_2->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_1_0_clicked()
{
    ui->btn_1_0->setRow(1);
    ui->btn_1_0->setCol(0);
    int status = ui->btn_1_0->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_1_1_clicked()
{
    ui->btn_1_1->setRow(1);
    ui->btn_1_1->setCol(1);
    int status = ui->btn_1_1->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_1_2_clicked()
{
    ui->btn_1_2->setRow(1);
    ui->btn_1_2->setCol(2);
    int status = ui->btn_1_2->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_2_0_clicked()
{
    ui->btn_2_0->setRow(2);
    ui->btn_2_0->setCol(0);
    int status = ui->btn_2_0->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_2_1_clicked()
{
    ui->btn_2_1->setRow(2);
    ui->btn_2_1->setCol(1);
    int status = ui->btn_2_1->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_btn_2_2_clicked()
{
    ui->btn_2_2->setRow(2);
    ui->btn_2_2->setCol(2);
    int status = ui->btn_2_2->setBtn(gameArray,&player);
    if(status)
    {
        RestartGame();
    }
}

void MainWindow::on_RestartGame_clicked()
{
    RestartGame();
}
