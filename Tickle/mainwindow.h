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
    void on_StartGame_clicked();

    void RestartGame();

    void on_btn_0_0_clicked();

    void on_btn_0_1_clicked();

    void on_btn_0_2_clicked();

    void on_btn_1_0_clicked();

    void on_btn_1_1_clicked();

    void on_btn_1_2_clicked();

    void on_btn_2_0_clicked();

    void on_btn_2_1_clicked();

    void on_btn_2_2_clicked();

    void on_RestartGame_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
