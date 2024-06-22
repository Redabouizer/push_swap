/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:24:29 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 19:29:20 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        if (token[0] == '+')
            ft_stack(stack_A, token + 1);
        else
            ft_stack(stack_A, token);
        return 0;
    }
    else
    {
        ft_printf("ERROR\n");
        return 1;
    }
}

int process_tokens(t_stack **stack_A, char *argv)
{
    char **tokens;
    int j = 0;

    tokens = ft_split(argv, ' ');
    if (!tokens)
    {
        ft_printf("ERROR\n");
        ft_lstclear((t_stack**)stack_A, free);
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

