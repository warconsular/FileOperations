#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main()
{

    char buffer[BUFFER_SIZE];
    FILE *f = fopen(" ", "r");
    FILE *out = fopen(" ", "w");

    if (f == NULL || out == NULL)
    {
        printf("Ошибка считывания текста!\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, f) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        int i = atoi(buffer);
        int result = 0;
        if (i != 0)
        {
            result = i * 2;
            fprintf(out, "%d", result);
        }
    }

    fclose(f);  
    fclose(out);
    return 0;
}