/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-settingup-bastian.carou
** File description:
** my_strtok.c
*/

#include <stdlib.h>
#include <unistd.h>

static int get_len(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static int get_nbr_of_separators(char *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == separator)
            count++;
    }
    if (str[get_len(str) - 1] != separator)
        count++;
    return count;
}

char **my_strtok(char *str, char separator)
{
    int nbr_of_separators = get_nbr_of_separators(str, separator);
    char **array_2d = malloc(sizeof(char *) * (nbr_of_separators + 1));
    int len = 0;
    int marker = 0;

    array_2d[nbr_of_separators] = NULL;
    for (int i = 0; i < nbr_of_separators; ++i) {
        for (len = 0; str[len + marker] != separator; ++len);
        array_2d[i] = malloc(sizeof(char) * len + 1);
        array_2d[i][len] = '\0';
        for (int j = 0; j < len; ++j) {
            array_2d[i][j] = str[marker];
            marker++;
        }
        marker++;
        len = 0;
    }
    return array_2d;
}
