#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256 // couple of megabyte text file size //

int main() {

    char buffer[BUFFER_SIZE]; // array with BUFFER_SIZE characters //
    FILE *f = fopen(" ", "r"); 
    if (f == NULL){
        printf("Ошибка открытия файла!");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, f) != NULL){
        printf( " %s\n", buffer);
    }

    fseek(f, 0, SEEK_SET);

    int len = 0;
    while (fseek(f, --len, SEEK_END) == 0)
    {
        printf("%c", fgetc(f));
    }
    
    printf("\n");
    fclose(f);
    return 0;
}