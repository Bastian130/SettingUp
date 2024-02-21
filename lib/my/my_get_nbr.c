/*
** EPITECH PROJECT, 2024
** B-PSU-100-PAR-1-1-navy-bastian.carou
** File description:
** my_get_nbr.c
*/

int my_getnbr(const char *str)
{
    int result = 0;
    int signe = 1;
    int i = 0;
    int num;

    while (str[i] == ' ')
        i++;
    if (str[i] == '-') {
        signe = -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        num = str[i] - '0';
        result = result * 10 + num;
        i++;
    }
    return result * signe;
}
