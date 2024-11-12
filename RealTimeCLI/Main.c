// gcc *.c -o program
// ./Main

#include <stdio.h>

#include "TerminalPrint.h" // Include the header file to access the function
#include "clock.h"

int main()
{

    char *words[] = {"Hello", "World", "This", "is", "C"};
    char *newWords[] = {"Goodbye", "World", "C", "is", "me"};
    clearPrint(words, 5);

    time_t initTime = getTime();

    while (1)
    {

        if (elapsedTime(initTime) > 2)
        {
            clearPrint(newWords, 5);
            break;
        }
    }

    return 0;
}