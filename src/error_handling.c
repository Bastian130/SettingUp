/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-settingup-bastian.carou
** File description:
** error_handling.c
*/

#include "../include/my.h"
#include <stdlib.h>
#include <sys/stat.h>

static int check_char(char *map)
{
    int count = 0;

    for (count = 0; map[count] != '\n'; ++count);
    for (int i = count; map[i] != '\0'; ++i) {
        if (map[i] != 'o' && map[i] != '.' && map[i] != '\n')
            return 84;
    }
    return 0;
}

static int check_size(char **map)
{
    int lines = my_getnbr(map[0]);
    int count = 0;
    int len_backup = 0;

    for (int i = 1; map[i] != NULL; ++i) {
        count++;
        if (i == 1) {
            len_backup = my_strlen(map[i]);
            continue;
        }
        if (my_strlen(map[i]) != len_backup)
            return 84;
        len_backup = my_strlen(map[i]);
    }
    if (lines != count)
        return 84;
    return 0;
}

static int check_file_size(char *filename)
{
    struct stat st;
    off_t fileSize;

    stat(filename, &st);
    fileSize = st.st_size;
    if (fileSize == 0)
        return 84;
    return 0;
}

int find_handling(char *filename)
{
    char *map = get_content(filename);
    char **map_2d = NULL;

    if (check_file_size(filename) == 84)
        return 84;
    if (check_char(map) == 84)
        return 84;
    map_2d = my_strtok(map, '\n');
    if (check_size(map_2d) == 84)
        return 84;
    for (int i = 0; map_2d[i] != NULL; ++i) {
        free(map_2d[i]);
    }
    free(map_2d);
    free(map);
    return 0;
}

static int is_number(char *number)
{
    for (int i = 0; number[i] != '\0'; ++i) {
        if (!(number[i] <= 57 && number[i] >= 48))
            return 1;
    }
    return 0;
}

int generation_handling(char *size, char *pattern)
{
    if (is_number(size) == 1)
        return 84;
    if (my_strlen(pattern) == 0)
        return 84;
    for (int i = 0; pattern[i] != '\0'; ++i) {
        if (pattern[i] != '.' && pattern[i] != 'o')
            return 84;
    }
    if (my_getnbr(size) < 0)
        return 84;
    return 0;
}
