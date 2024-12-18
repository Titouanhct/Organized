/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** ..
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int check(char const *str, int i)
{
    if (str[i] < 48)
        return 1;
    if (str[i] < 65 && str[i] > 57)
        return 1;
    if (str[i] > 90 && str[i] < 97)
        return 1;
    if (str[i] > 123)
        return 1;
    return 0;
}

static char *transfer(char const *str, int i, int base)
{
    char *trans;
    int j = base;
    int k = 0;

    if (str[i + 1] == '\0')
        i++;
    trans = malloc(sizeof(char) * (i - base + 1));
    while (j < i) {
        trans[k] = str[j];
        k++;
        j++;
    }
    trans[k] = '\0';
    return trans;
}

static int count_len(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check(str, i) == 1)
        count++;
    }
    count += 2;
    return count;
}

char **my_str_to_word_array(char const *str)
{
    char **res;
    int r = 0;
    int base = 0;

    res = malloc(sizeof(char *) * count_len(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (check(str, i) == 1 && check(str, i - 1) == 1) {
            base++;
            continue;
        }
        if ((check(str, i) == 1 && i - base > 0) || str[i + 1] == '\0') {
            res[r] = transfer(str, i, base);
            r++;
            base = i + 1;
        }
    }
    res[r] = NULL;
    return res;
}
