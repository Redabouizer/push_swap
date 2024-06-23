/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:46:52 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/23 18:59:42 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack {
    int index;
    int content; 
    struct s_stack *next;
} t_stack;

t_stack *ft_lstnew(int index, int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
size_t	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

int process_token(t_stack **stack_A, char *token);
int process_tokens(t_stack **stack_A, char *argv);
int filter_number(const char *token);
void ft_stack(t_stack **Stack_A, int content);
void free_tokens(char **tokens);
int rep_number(t_stack *Stack_A);
void free_memory(t_stack *list);

void ft_swap(t_stack **stack, char c);
void ft_swap_a_b(t_stack **stack_A, t_stack **stack_B);
void ft_push(t_stack **stack_A, t_stack **stack_B, char c);
void ft_rotate(t_stack **stack, char c);
void ft_rotate_a_b(t_stack **stack_A, t_stack **stack_B);
void ft_reverse_rotate(t_stack **stack, char c);
void ft_reverse_rotate_a_b(t_stack **stack_A, t_stack **stack_B);

#endif

