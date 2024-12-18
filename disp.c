/*
** EPITECH PROJECT, 2024
** organized
** File description:
** disp
*/

#include "my.h"
#include <stdlib.h>

int disp(void *data, char **args)
{
    list_t *list = (list_t *)data;
    node_t *current = list->head;
    info_t *info;

    while (current != NULL){
        info = (info_t *)current->data;
        mini_printf("%s n°%i - \"%s\"\n", info->category, info->id,
            info->name);
        current = current->next;
    }
    return 0;
}
