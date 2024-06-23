/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:24:29 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/23 15:58:14 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstnew(int index, int content)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
    {
        ft_printf("Memory allocation error\n");
        exit(1);
    }
    new_node->content = content;
    new_node->index = index;
    new_node->next = NULL;

    return new_node;
}

int process_tokens(t_stack **stack_A, char *argv)
{
    char **tokens;
    int j = 0;

    while (*argv && *argv == ' ')
        argv++;
    if (!*argv)
    { 
        ft_printf("ERROR\n");
        return 1;
    }
    tokens = ft_split(argv, ' ');

    if (!tokens)
    {
        ft_printf("ERROR\n");
        ft_lstclear((t_stack **)stack_A, free);
        return 1;
    }

    while (tokens[j] != NULL)
    {
        if (process_token(stack_A, tokens[j]) != 0)
        {
            free_tokens(tokens);
            return 1;
        }
        j++;
    }

    free_tokens(tokens);
    return 0;
}

void free_tokens(char **tokens)
{
    int j = 0;
    while (tokens[j] != NULL)
    {
        free(tokens[j]);
        j++;
    }
    free(tokens);
}

int process_token(t_stack **stack_A, char *token)
{
    if (filter_number(token) == 0)
    {
        long num = ft_atoi(token);
        ft_stack(stack_A, num);
        return 0;
    }
    else
    {
        ft_printf("ERROR\n");
        return 1;
    }
}

int filter_number(const char *token)
{
    int j;
    long num;

    j = 0;
    if (!token || *token == '\0' || *token == ' ')
    {
        ft_printf("ERROR\n");
        return 1;
    }

    num = ft_atoi(token);
    if (num > INT_MAX || num < INT_MIN)
        return 1;

    if ((token[j] == '+' || token[j] == '-') &&
        (token[j + 1] >= '0' && token[j + 1] <= '9'))
    {
        j++;
    }
    while (token[j])
    {
        if (token[j] < '0' || token[j] > '9')
            return 1;
        j++;
    }
    return 0;
}

void ft_stack(t_stack **Stack_A, int content)
{
    t_stack *node;

    node = ft_lstnew(5, content);
    if (!node)
    {
        ft_printf("ERREUR\n");
        exit(1);
    }
    ft_lstadd_back(Stack_A, node);
}
