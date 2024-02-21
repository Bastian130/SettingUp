/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** my_strcpy.c
*/

void my_strcpy(char *dest, const char *src)
{
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
