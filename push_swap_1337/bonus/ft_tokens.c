/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:57:01 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/15 20:36:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	process_tokens(t_stack **stack_A, char *argv)
{
	char	**tokens;
	int		j;

	j = 0;
	while (*argv && *argv == ' ')
		argv++;
	if (!*argv)
		return (write(2, "Error\n", 6), 1);
	tokens = ft_split(argv, ' ');
	if (!tokens)
		return (write(2, "Error\n", 6), 1);
	while (tokens[j] != NULL)
	{
		if (process_token(stack_A, tokens[j]) != 0)
			return (free_tokens(tokens), 1);
		j++;
	}
	return (free_tokens(tokens), 0);
}

void	free_tokens(char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j] != NULL)
	{
		free(tokens[j]);
		j++;
	}
	free(tokens);
}

int	process_token(t_stack **stack_A, char *token)
{
	long	num;

	if (filter_number(token) == 0)
	{
		num = ft_atoi(token);
		ft_stack(stack_A, num);
		return (0);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
}

int	filter_number(const char *token)
{
	int		j;
	long	num;

	j = 0;
	if (!token || *token == '\0' || *token == ' ')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if ((token[j] == '+' || token[j] == '-')
		&& (token[j + 1] >= '0' && token[j + 1] <= '9'))
	{
		j++;
	}
	while (token[j])
	{
		if (token[j] < '0' || token[j] > '9')
			return (1);
		j++;
	}
	num = ft_atoi(token);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

void	ft_stack(t_stack **stack_A, int content)
{
	t_stack	*node;

	node = ft_lstnew(-1, content);
	if (!node)
	{
		write(2, "Error\n", 6);
		free_memory(*stack_A);
		free_memory(node);
		exit(1);
	}
	ft_lstadd_back(stack_A, node);
}
