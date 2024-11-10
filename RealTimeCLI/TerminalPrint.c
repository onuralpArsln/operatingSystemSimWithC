#include "TerminalPrint.h" // Include the header file for function declarations

// char *strings[] = {"Hello", "World", "This", "is", "C"}; gelecek array stringi yerine char *arr[] kullanıyoruz
void clearPrint(char *arr[], int size) {
        for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}