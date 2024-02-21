/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** get_final_map.c
*/

#include "../include/struct.h"

biggest_square_t update_struct(int **int_map, int i, int j,
    biggest_square_t square)
{
    if (int_map[i][j] > square.size) {
        square.x = j;
        square.y = i;
        square.size = int_map[i][j];
    }
    return square;
}

biggest_square_t find_biggest_int(int **int_map, int lines, int len,
    biggest_square_t square)
{
    square.x = 0;
    square.y = 0;
    square.size = 0;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < len; ++j) {
            square = update_struct(int_map, i, j, square);
        }
    }
    return square;
}

char **get_final_map(int **int_map, int lines, int len, char **map)
{
    biggest_square_t square = find_biggest_int(int_map, lines, len, square);

    for (int i = square.y; i > square.y - square.size; --i) {
        for (int j = square.x; j > square.x - square.size; --j) {
            map[i + 1][j] = 'x';
        }
    }
    return map;
}
