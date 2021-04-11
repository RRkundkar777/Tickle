#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// The Class for Constructing a Window
#include <QMainWindow>
// The TicButton Class
#include"ticbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Class Tickle MainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

// Constructor, Destructor and Member Functions
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // Structure to store move (For storing optimal move in computer player mode)
    struct Location
    {
        int row;
        int col;
        char data;
    };
    // Function to Set Text to Button, check for win/lose/draw, evaluate best move
    // and update the Button accordingly
    int setBtnAuto(char array[3][3],int *player,TicButton *t1);
    // Function to find the best move for a given condition of board
    Location Optimise(char array[3][3]);
    // Function to toggle mode from 2 player to computer and vica versa
    void ToggleMode(int *mode);

// Private Members (UI)
private slots:
    // Function to Restart the Game
    void RestartGame();

    // Button Clicked Events
    void on_btn_0_0_clicked();
    void on_btn_0_1_clicked();
    void on_btn_0_2_clicked();
    void on_btn_1_0_clicked();
    void on_btn_1_1_clicked();
    void on_btn_1_2_clicked();
    void on_btn_2_0_clicked();
    void on_btn_2_1_clicked();
    void on_btn_2_2_clicked();

    // Restart Button Event
    void on_RestartGame_clicked();
    // Revert Button Event
    void on_revert_btn_clicked();
    // Switch Mode CLicked Event
    void on_switchMode_clicked();
    // Function to revert a move
    void revertMove(char array[3][3]);
    // Function to update the currently active player on GUI
    void TogglePlayer();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
