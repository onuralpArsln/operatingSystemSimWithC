// gcc *.c -o program
// ./Main


#include <stdio.h>
#include "TerminalPrint.h" // Include the header file to access the function

int main() {
   
   char *words[] = {"Hello", "World", "This", "is", "C"};
   clearPrint(words, 5);
    return 0;
}