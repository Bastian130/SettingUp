/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** get_binary_map.c
*/

#include <stdlib.h>

static void char_to_int(int **binary_map, char **map, int i, int j)
{
    if (map[i][j] == 'o')
        binary_map[i - 1][j] = 0;
    if (map[i][j] == '.')
        binary_map[i - 1][j] = 1;
}

int **get_binary_map(char **map, int len, int lines)
{
    int **binary_map = malloc(sizeof(int *) * lines + 1);

    for (int i = 1; i < lines + 1; ++i) {
        binary_map[i - 1] = malloc(sizeof(int) * len);
        for (int j = 0; j < len; ++j) {
            char_to_int(binary_map, map, i, j);
        }
    }
    return binary_map;
}
