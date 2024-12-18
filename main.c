/*
** EPITECH PROJECT, 2024
** my_Linked_list
** File description:
** main
*/

#include "my.h"
#include "shell.h"
#include <stdlib.h>

static void free_info(info_t *info)
{
    if (info != NULL) {
        free(info->category);
        free(info->name);
        free(info);
    }
}

void free_list(list_t *list)
{
    node_t *current = list->head;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        free_info((info_t *)current->data);
        free(current);
        current = next;
    }
    free(list);
}

int main(void)
{
    list_t *list = create_list();
    int r_value = workshop_shell(list);

    free_list(list);
    return r_value;
}
