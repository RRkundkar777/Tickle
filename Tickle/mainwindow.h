#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    // Function to revert a move
    void revertMove(char array[3][3]);
    //
    void TogglePlayer();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
