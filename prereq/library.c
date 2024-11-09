#include <stdio.h>  // printf ve scanf gibi fonksiyonları sağlar
#include <string.h> // stringler için fonksiyonlar sağlar

#define MAX_BOOKS 5 
// Max books 5 olarak tanımlandı bir int değişken yerine bunu kullanmak biraz daha verimlidir ve 
// program boyunca sabit kalacak değerleri definelamak bir best practice olarak görülür.
// immutable değişmez bir değer olarak kullanıma izin verir

// structlar özel data yapıları sağlar title ve author için  char arrayları yayın yılı için 
// int var
struct Book {
    char title[50];
    char author[50];
    int year;
};

// Function prototypeları compilera fonksiyon yapılarını tanıtmak için kullanılır
// imzaya bakarak compile zamanında denetlemeyi kolaylaştırır 
// fonksiyon definationları sonra olsa öncesinde fonksiyonu çağırmayı mümkün kılar
// normalde header(.h) dosylarında  tanımlanır
void addBook(struct Book books[], int *count); // count güncelleneceği için memorydeki adresi lazım
void displayBooks(const struct Book books[], int count);
void searchBook(const struct Book books[], int count, const char* title);
void listAuthors(const struct Book books[], int count);



// işlevsel kodu tanımlar dosya çalışınca bu  fonksiyon çağrılır
int main() {
    struct Book library[MAX_BOOKS]; // book tipinden bir array max_books boyutunda
    int bookCount = 0; // mevcut kitap sayısını tutmak için bir değişken 

    int choice; // değişkeni oluştur sonra kullanılacak

    while (1) { // kontrol menüsü için sonsuz döngü
        // menüyü yazdır 
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by Title\n");
        printf("4. List All Authors\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // seçimi oku ve choice değişkenine ata
        // bu atama scandan alınan bilginin choice değişkeni adresine konmasını sağlar
        scanf("%d", &choice);

        //choice üzerinde switch case kullanarak işlemleri çağır 
        switch (choice) {
            case 1:
                addBook(library, &bookCount); // eğer bookCount düz bir integer olarak verilerse işlem bookCounterın kendisini etkilemez, memorydeki adresi işlenmeli
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3: {
                char searchTitle[50];
                printf("Enter the title of the book to search: ");
                scanf(" %[^\n]", searchTitle); // new line \n gelene kadar okuma yap 
                searchBook(library, bookCount, searchTitle);
                break;
            }
            case 4:
                listAuthors(library, bookCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// Function to add a book
void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) { // Check if array is full
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    // Get book details from user
    printf("Enter book title: ");
    scanf(" %[^\n]", books[*count].title); // Read string with spaces
    printf("Enter author: ");
    scanf(" %[^\n]", books[*count].author);
    printf("Enter publication year: ");
    scanf("%d", &books[*count].year);

    (*count)++; // Increment book count
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks(const struct Book books[], int count) {
    if (count == 0) {
        printf("No books to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) { // Loop through array
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
        printf("------------------\n");
    }
}

// Function to search for a book by title
void searchBook(const struct Book books[], int count, const char* title) {
    int found = 0;

    for (int i = 0; i < count; i++) { // Loop through array to search
        if (strcmp(books[i].title, title) == 0) { // Compare titles
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book titled '%s' not found in the library.\n", title);
    }
}

// Function to list all authors
void listAuthors(const struct Book books[], int count) {
    if (count == 0) {
        printf("No authors to display.\n");
        return;
    }

    printf("Authors in the Library:\n");
    for (int i = 0; i < count; i++) { // Loop through books array to get authors
        printf("%s\n", books[i].author);
    }
}
