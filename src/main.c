/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

static int setting_up(char **map)
{
    int len = my_strlen(map[1]);
    int lines = my_getnbr(map[0]);
    int **binary_map = get_binary_map(map, len, lines);
    int **int_map = get_int_map(binary_map, len, lines);
    char **final_map = get_final_map(int_map, lines, len, map);

    for (int i = 1; final_map[i] != NULL; ++i) {
        write(1, final_map[i], my_strlen(final_map[i]));
        write(1, "\n", 1);
    }
    for (int i = 0; final_map[i] != NULL; ++i) {
        free(final_map[i]);
    }
    free(final_map);
    for (int i = 0; i < lines; ++i) {
        free(int_map[i]);
    }
    free(int_map);
    return 0;
}

static int find_biggest_square(char *filename)
{
    char *map = get_content(filename);
    char **map_2d = my_strtok(map, '\n');

    setting_up(map_2d);
    free(map);
    return 0;
}

static char **generating_square(char *size, char *pattern)
{
    char **map_2d = generate_square(size, pattern);

    setting_up(map_2d);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (find_handling(av[1]) == 84)
            return 84;
        find_biggest_square(av[1]);
        return 0;
    }
    if (ac == 3) {
        if (generation_handling(av[1], av[2]) == 84)
            return 84;
        generating_square(av[1], av[2]);
        return 0;
    }
    return 84;
}
