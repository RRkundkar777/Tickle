#ifndef STACK_H
#define STACK_H

// Structure of a move
struct move
{
   int row,col;
   char data;
   struct move* next;
};

typedef move* stack;

void init(stack *S1);
void pushIntoStack(stack *S1,int row,int col,char* data);
void popFromStack(stack *S1,move** m1);
char stackTopData(stack S1);

#endif // STACK_H
