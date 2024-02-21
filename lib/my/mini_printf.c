/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** mini_printf.c
*/

/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-secured-eric.le-roux
** File description:
** mini_printf.c
*/

#include <stdarg.h>
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_put_nbr(int nb)
{
    if (nb < -2147483647 || nb > 2147483647) {
        return -1;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

static int my_putstr(char const *str)
{
    int i = 0;
    char end = '\0';

    while (str[i] != end) {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static int my_get_len_nbr(int nb, int len)
{
    if (nb < -2147483647 || nb > 2147483647) {
        return -1;
    }
    if (nb < 0) {
        nb = nb * (-1);
        len++;
    }
    if (nb >= 0 && nb <= 9) {
        len++;
    }
    if (nb > 9) {
        len++;
        len = my_get_len_nbr(nb / 10, len);
    }
    return len;
}

int mini_printf_case(const char *format, va_list ap, int i)
{
    switch (format[i + 1]) {
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            my_putchar((char) va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, long));
            break;
        case '%':
            my_putchar('%');
            break;
    }
    i++;
    return i;
}

int get_len(const char *format, va_list ap2, int i, int len)
{
    switch (format[i + 1]) {
        case 's':
            len = len + my_strlen(va_arg(ap2, char *));
            break;
        case 'd':
            len = my_get_len_nbr(va_arg(ap2, int), len);
            break;
        case 'c':
            len++;
            break;
        case 'i':
            len = my_get_len_nbr(va_arg(ap2, long), len);
            break;
        case '%':
            len++;
            break;
    }
    return len;
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    va_list ap2;
    int len = 0;

    va_start(ap2, format);
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            len++;
            write(1, &format[i], 1);
        } else {
            len = get_len(format, ap2, i, len);
            i = mini_printf_case(format, ap, i);
        }
    }
    va_end(ap);
    va_end(ap2);
    return len;
}
