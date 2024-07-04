
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:08 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 19:23:57 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack {
    int index;
    int content; 
    struct s_stack *next;
} t_stack;


char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_atoi(const char *str);

int		ft_lstsize(t_stack *lst);
t_stack *ft_lstnew(int index, int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));



#endif
