/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:15 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/25 12:00:35 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				tmp;
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
}				t_stack;

t_stack	*new_stack();
t_node	*new_node(int v);
int		rrr(t_stack *a, t_stack *b, int f);
int		ss(t_stack *a, t_stack *b, int f);
int		pa(t_stack *a, t_stack *b, int f);
int		pb(t_stack *a, t_stack *b, int f);
int		rr(t_stack *a, t_stack *b, int f);
int		where_is_i(t_stack *d, int v);
int		check_double(t_stack *a);
int		ft_last_elem(t_stack *p);
int		ft_lst_size(t_stack *p);
int		rra(t_stack *a, int f);
int		rrb(t_stack *b, int f);
int		sa(t_stack *p, int f);
int		sb(t_stack *b, int f);
int		ra(t_stack *a, int f);
int		rb(t_stack *b, int f);
int		is_sorted(t_stack *a);
int		the_max(t_stack *a);
int		the_min(t_stack *a);
int		ft_atoi(char *str);
void	in_head(t_stack *p, int v);
void	in_tail(t_stack *p, int v);
void	print_stks(t_stack *a, t_stack *b);
void	minmax(t_stack *p);
void	maxmin(t_stack *p);
void	ft_exit(t_stack *p);

#endif
