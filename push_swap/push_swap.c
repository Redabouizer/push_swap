#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(int argc, char *argv[]) {
    if (argc < 2)
        return (0);

    int i = 1;
    char **list = malloc(sizeof(char *) * argc);
    if (!list) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    int list_index = 0;

    while (i < argc) {
        char **tokens = ft_split(argv[i], ' ');

        if (tokens) {
            int j = 0;
            while (tokens[j] != NULL) {
                int id = 0;
                int error = 0;
                while (tokens[j][id] != '\0') {
                    if ((tokens[j][id] < '0' || tokens[j][id] > '9') && tokens[j][id] != '-') {
                        error = 1;
                    }
                    id++;
                }
                if (!error) {
                    list[list_index++] = tokens[j];
                } else {
                    printf("ERREUR\n");
                    free(tokens);
                    free(list);
                    return 0;
                }
                j++;
            }
            free(tokens);
        }

        i++;
    }
    printf("Tokens stored in list:\n");
    for (int k = 0; k < list_index; k++) {
        printf("%s\n", list[k]);
    }
    free(list);

    return 0;
}
