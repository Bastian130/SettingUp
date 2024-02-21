/*
** EPITECH PROJECT, 2024
** SettingUPV2
** File description:
** get_int_map.c
*/

int get_min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

void binary_to_int(int **binary_map, int i, int j)
{
    if (binary_map[i][j] != 0) {
        binary_map[i][j] = get_min(
            binary_map[i - 1][j],
            binary_map[i - 1][j - 1],
            binary_map[i][j - 1]
            ) + 1;
    }
}

int **get_int_map(int **binary_map, int len, int lines)
{
    for (int i = 1; i < lines; ++i) {
        for (int j = 1; j < len; ++j) {
            binary_to_int(binary_map, i, j);
        }
    }
    return binary_map;
}
