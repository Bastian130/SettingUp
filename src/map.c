/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** map.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int get_size(char const *filename)
{
    struct stat st;
    int fileSize;

    stat(filename, &st);
    fileSize = st.st_size;
    return fileSize;
}

char *get_content(char const *filename)
{
    ssize_t size = get_size(filename);
    char *fileContent = malloc(sizeof(char) * (size + 1));
    int fd = open(filename, O_RDONLY);

    if (fd == -1 || size == 0)
        return NULL;
    size = read(fd, fileContent, size);
    fileContent[size] = '\0';
    close(fd);
    return fileContent;
}
