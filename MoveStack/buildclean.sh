gcc -c main.c -Wall
gcc -c moveStack.c -Wall 
gcc main.o moveStack.o -lm -o app
./app
rm *.o
rm app