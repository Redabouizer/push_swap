#include "stdio.h"
#include "libft/libft.h"

int main(int argc , char *argv[]){
    char **list;
    char *lit;
    int i = 1;
    while (i != argc)
    {
        int j = 0;
        printf("%d : " , i);
        while (argv[i][j]!='\0')
        {
            if (argv[i][j-1]==32) {
                list = argv[i][j];
                // list =ft_split(char const *s, " ");
            }
            j++;
        }
        i++;
        printf("\n");
    }
}