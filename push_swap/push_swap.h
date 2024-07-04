/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:46:52 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/04 02:02:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"


void ft_swap(t_stack **stack, char c);
void ft_swap_a_b(t_stack **stack_A, t_stack **stack_B);
void ft_push(t_stack **stack_A, t_stack **stack_B, char c);
void ft_rotate(t_stack **stack, char c);
void ft_rotate_a_b(t_stack **stack_A, t_stack **stack_B);
void ft_reverse_rotate(t_stack **stack, char c);
void ft_reverse_rotate_a_b(t_stack **stack_A, t_stack **stack_B);

int process_token(t_stack **stack_A, char *token);
int process_tokens(t_stack **stack_A, char *argv);
int filter_number(const char *token);
void ft_stack(t_stack **Stack_A, int content);
void free_tokens(char **tokens);
int rep_number(t_stack *Stack_A);
void free_memory(t_stack *list);

int find_min(t_stack *stack);
int ft_check_sort(t_stack *list_A);
int ft_sort_index(t_stack *list_A);
void ft_sort_node(t_stack **a, t_stack **b);
void show(t_stack *list, const char *name);

#endif

