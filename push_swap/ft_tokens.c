/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:24:29 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/28 19:21:57 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int process_tokens(t_stack **stack_A, char *argv)
{
    char **tokens;
    int j = 0;

    while (*argv && *argv == ' ')
        argv++;
    if (!*argv)
    { 
        ft_printf("Error\n");
        return 1;
    }
    tokens = ft_split(argv, ' ');

    if (!tokens)
    {
        ft_printf("Error\n");
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
        ft_printf("Error\n");
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
        ft_printf("Error\n");
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

void ft_stack(t_stack **stack_A, int content)
{
    t_stack *node;

    node = ft_lstnew(-1, content);
    if (!node)
    {
        ft_printf("Error\n");
        free_memory(*stack_A);
        exit(1);
    }
    ft_lstadd_back(stack_A, node);
}
