//Stack ADT for multiple Data Types

//Change the typedef for accomodating multiple data type
typedef int infi;

// For Large Data
typedef long long INT;

// Node of Stack 
typedef struct move
{
   int row,col;
   char data;
   struct move* next;
}move;

// Node pointer as a stack
typedef move* stack;

// Functions on Stack
void init(stack *S1);
void push(stack *S1,int row,int col,char chr);
void pop(stack *S1,move**);
int isEmpty(stack S1);
infi stackTop(stack S1);