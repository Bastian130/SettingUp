/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** generating_square.c
*/

#include <stdlib.h>
#include "../include/my.h"

static int reset_count(int count, char *pattern)
{
    if (count >= my_strlen(pattern))
        count = 0;
    return count;
}

char **generate_square(char *size_str, char *pattern)
{
    int size = my_getnbr(size_str);
    char **map_2d = malloc(sizeof(char *) * (size + 2));
    int count = 0;

    map_2d[0] = malloc(sizeof(char) * (my_strlen(size_str) + 1));
    my_strcpy(map_2d[0], size_str);
    for (int i = 1; i < size + 1; ++i) {
        map_2d[i] = malloc(sizeof(char) * (size + 1));
        map_2d[i][size] = '\0';
        for (int j = 0; j < size; ++j) {
            count = reset_count(count, pattern);
            map_2d[i][j] = pattern[count];
            count++;
        }
    }
    return map_2d;
}
