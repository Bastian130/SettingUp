/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** my.h
*/

#ifndef SETTINGUPV2_MY_H
    #define SETTINGUPV2_MY_H
char **my_strtok(char *str, char separator);
char *my_strdup(const char *s);
void my_strcpy(char *dest, const char *src);
int my_strlen(char const *str);
char *get_content(char const *filename);
int get_size(char const *filename);
int mini_printf(const char *format, ...);
int my_getnbr(const char *str);
int find_handling(char *filename);
int generation_handling(char *size, char *pattern);
int **get_binary_map(char **map, int len, int lines);
int **get_int_map(int **binary_map, int len, int lines);
char **get_final_map(int **int_map, int lines, int len, char **map);
char **generate_square(char *size_str, char *pattern);
#endif //SETTINGUPV2_MY_H
