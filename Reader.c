#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main () {

    char buffer[BUFFER_SIZE];   
    FILE *f = fopen("Book.txt", "r");
    if (f == NULL)
    {
        printf("Ошибка открытия файла!");
        return 1;
    }
    

    while (fgets(buffer, BUFFER_SIZE, f) != NULL)
    {
        printf(" %s\n", buffer);
    }
    





    fclose(f);
    return 0;
}