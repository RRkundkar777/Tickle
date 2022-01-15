#include "stack.h"
#include<iostream>
#include<QString>
// Functions on a Stack

// Declaration of tdebug
void tdebug(QString message,bool mode,QString file = "");
bool TCS_DBG = true;

// Initialising the Stack
void init(stack *S1)
{
    *S1 = NULL;
}

// Pushing a move into stack
void pushIntoStack(stack *S1,int row,int col,char* data)
{
    // Initialising a newnode
    move *m1 = (move*)malloc(sizeof(move));
    // Assigning the data to newnode
    m1->row = row;
    m1->col = col;
    m1->data = *data;
    // Handling empty stack case
    if(*S1 == NULL)
    {
       *S1 = m1;
        return;
    }

    // Pushing into Stack
    m1->next = (*S1);
    (*S1) = m1;
    return;
}

// Pop a move from stack
void popFromStack(stack *S1,move** m1)
{
    // Handling Empty Stack
    if((*S1) == NULL)
    {
            tdebug("Stack Empty",TCS_DBG,__FILE__);
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
