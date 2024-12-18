/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort
*/

#include "my.h"
#include "shell.h"
#include "stdlib.h"
#include "unistd.h"

void sorting_type(int r, node_t *tmp, node_t *next)
{
    info_t *tmp_info = (info_t *) tmp->data;
    info_t *next_info = (info_t *) next->data;

    if (r == 0) {
        if (my_strcmp(tmp_info->category, next_info->category) > 0)
        switch_nodes(tmp, next);
    }
    if (r == 1) {
        if (my_strcmp(tmp_info->category, next_info->category) < 0)
        switch_nodes(tmp, next);
    }
}

void sorting_name(int r, node_t *tmp, node_t *next)
{
    info_t *tmp_info = (info_t *) tmp->data;
    info_t *next_info = (info_t *) next->data;

    if (r == 0) {
        if (my_strcmp(tmp_info->name, next_info->name) > 0)
        switch_nodes(tmp, next);
    }
    if (r == 1) {
        if (my_strcmp(tmp_info->name, next_info->name) < 0)
        switch_nodes(tmp, next);
    }
}

void sorting_id(int r, node_t *tmp, node_t *next)
{
    info_t *tmp_info = (info_t *) tmp->data;
    info_t *next_info = (info_t *) next->data;

    if (r == 0) {
        if (tmp_info->id - next_info->id > 0)
        switch_nodes(tmp, next);
    }
    if (r == 1) {
        if (tmp_info->id - next_info->id < 0)
        switch_nodes(tmp, next);
    }
}

void check_sorting_param(char *str, node_t *tmp, node_t *next, int r)
{
    if (my_strcmp(str, "NAME") == 0)
        sorting_name(r, tmp, next);
    if (my_strcmp(str, "TYPE") == 0)
        sorting_type(r, tmp, next);
    if (my_strcmp(str, "ID") == 0)
        sorting_id(r, tmp, next);
}

static int valid_arg(char *str)
{
    if (my_strcmp(str, "NAME") == 0)
        return 0;
    if (my_strcmp(str, "TYPE") == 0)
        return 0;
    if (my_strcmp(str, "ID") == 0)
        return 0;
    if (my_strcmp(str, "-r") == 0)
        return 0;
    return 84;
}

static int check_for_current(char *str, node_t *tmp, node_t *next, int r)
{
    while (next != NULL) {
        check_sorting_param(str, tmp, next, r);
        tmp = next;
        next = tmp->next;
    }
    return 0;
}

static int base_sort(list_t *list, char *str, int r)
{
    node_t *current = list->tail;
    node_t *tmp = list->head;
    node_t *next = tmp->next;

    if (valid_arg(str) == 84)
        return 84;
    while (current != tmp) {
        if (check_for_current(str, tmp, next, r) == 84)
            return 84;
        tmp = list->head;
        next = tmp->next;
        current = current->prev;
    }
    return 0;
}

int sort(void *data, char **args)
{
    list_t *list = (list_t *) data;
    int r_value = 0;
    int x = 0;
    int r = 0;

    while (args[x] != NULL)
        x++;
    if (x == 0)
        return 84;
    for (int i = x - 1; i != -1; i--){
        if (args[i + 1] != NULL && my_strcmp(args[i + 1], "-r") == 0)
            r = 1;
        r_value = base_sort(list, args[i], r);
        if (r_value == 84)
            return 84;
        r = 0;
    }
    return 0;
}
