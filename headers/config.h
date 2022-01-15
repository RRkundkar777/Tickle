// Global configuration of project

#ifndef CONFIG_H
#define CONFIG_H

#include<QString>
#include<QDebug>

// Debugging Macro
#define TC_DBG true

// Function to write debug statements
void tdebug(QString message,bool mode,QString file = "")
{
    QString filename = file.split("/").last();
    if(mode){
        qDebug() << filename << ":" << message;
    }
    return;
}

// Enum for Debugger
enum
{
  on = 1,
  off = 0
};

// Debugger
int DEBUGGER = on;

// Enum for Game Mode
enum
{
    computer = 0,
    twoPlayer = 1
};


// Game Mode
int mode = computer;

// The Game Array Storing the State of the Board
char gameArray[3][3] = {{'_','_','_'},
                        {'_','_','_'},
                        {'_','_','_'}};

// Player variable for deciding the currently active player
int player = 0;

// MoveStack for recording the moves made by the players
stack moveStack = NULL;

#endif // CONFIG_H
