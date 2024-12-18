/*
** EPITECH PROJECT, 2024
** organized
** File description:
** add
*/

#include "my.h"
#include <stdlib.h>

void free_type(char **type)
{
    for (int i = 0; type[i] != NULL; i++)
        free(type[i]);
    free(type);
}

int type_check(char *str)
{
    char **type = malloc(sizeof(char *) * 6);

    type[0] = my_strdup("WIRE");
    type[1] = my_strdup("PROCESSOR");
    type[2] = my_strdup("SENSOR");
    type[3] = my_strdup("ACTUATOR");
    type[4] = my_strdup("DEVICE");
    type[5] = NULL;
    for (int i = 0; type[i] != NULL; i++)
        if (my_strcmp(type[i], str) == 0){
            free_type(type);
            return 1;
        }
    free_type(type);
    return 0;
}

int add(void *data, char **args)
{
    info_t *info;
    list_t *list = (list_t *)data;

    if (args[0] == NULL || args[1] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (type_check(args[i]) == 1) {
            info = malloc(sizeof(info_t));
            info->category = my_strdup(args[i]);
            info->id = list->size;
            i++;
            info->name = my_strdup(args[i]);
            pushfront(list, info);
            mini_printf("%s n°%i - \"%s\" added.\n", info->category, info->id,
                info->name);
        } else
            return 84;
    }
    return 0;
}
