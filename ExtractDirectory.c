#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

void list_files(const char *path);

int main() {
    list_files(".");
    return 0;
}

void list_files(const char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (dir == NULL)
    {
        perror("Program Error!");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) // сheck of type directory contents //
    {
        if (entry->d_type == DT_DIR)
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            char *subdir_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(subdir_path, "%s/%s", path, entry->d_name);
            list_files(subdir_path);
        }
        else
        {
            printf("%s/%s\n", path, entry->d_name);
        }
    }
    closedir(dir);
}