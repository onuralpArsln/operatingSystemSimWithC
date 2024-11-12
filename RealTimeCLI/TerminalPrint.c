#include "TerminalPrint.h" 
#include <stdio.h>
#include <stdlib.h> 


// char *strings[] = {"Hello", "World", "This", "is", "C"}; gelecek array stringi yerine char *arr[] kullanıyoruz
void clearPrint(char *arr[], int size) {

    #ifdef _WIN32
    system("cls"); // Windows
    #else
    system("clear"); // Linux or macOS
    #endif


    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}