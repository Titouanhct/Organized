/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del
*/

#include "my.h"
#include <stdlib.h>

static void free_info(info_t *info)
{
    if (info != NULL) {
        free(info->category);
        free(info->name);
        free(info);
    }
}

int check_nodes(list_t *list, int id)
{
    info_t *info;
    node_t *current = list->head;

    for (; current; current = current->next){
        info = current->data;
        if (info->id == id) {
            mini_printf("%s n°%i - \"%s\" deleted.\n", info->category,
                info->id, info->name);
            free_info(info);
            destroy_node(list, current);
            return 0;
        }
    }
    return 84;
}

int del(void *data, char **args)
{
    list_t *list = (list_t *)data;
    int done = 84;

    for (int i = 0; args[i]; i++){
        if (my_str_isnum(args[i]) == 1)
            done = check_nodes(list, my_getnbr(args[i]));
    }
    return done;
}
