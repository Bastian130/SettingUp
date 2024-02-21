/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(const char *s)
{
    char *new_str = malloc(my_strlen(s) + 1);

    if (new_str) {
        my_strcpy(new_str, s);
    }
    return new_str;
}
