/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:32:56 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/25 12:02:12 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stack *p)
{
	t_node	*n;

	n = p->head;
	while (n)
	{
		free(n);
		n = n->next;
	}
	exit(0);
}

int	ft_lst_size(t_stack *p)
{
	int	cnt;
	t_node	*n;

	cnt = 0;
	n = p->head;
	while (n)
	{
		n = n->next;
		cnt++;
	}
	return (cnt);
}
int	ft_atoi(char *str)
{
	int	r;
	int	s;

	r = 0;
	s = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-'|| *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		r = r * 10 + (*str++) - '0';
	return (r * s);
}

void	in_head(t_stack *p, int v)
{
	t_node	*new;

	new = new_node(v);
	new->next = p->head;
	if (p->head != NULL)
		p->head->prev = new;
	p->head = new;
}

void	in_tail(t_stack *p, int v)
{
	t_node	*new;
	t_node	*o;

	if (p->head == NULL)
		return (in_head(p, v));
	new = new_node(v);
	o = p->head;
	while (o->next)
		o = o->next;
	o->next = new;
	new->prev = p->head;
}

int	ft_cmp(int a, int b)
{
	return (a - b);
}

void	minmax(t_stack *p)
{
	t_node	*x;
	t_node	*y;

	x = p->head;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (ft_cmp(x->data, y->data) > 0)
			{
				x->tmp = x->data;
				x->data = y->data;
				y->data = x->tmp;
			}
			y = y->next;
		}
		x = x->next;
	}
	ft_printf("\nfrom min to max\n");
}

void	maxmin(t_stack *p)
{
	t_node	*x;
	t_node	*y;

	x = p->head;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (ft_cmp(x->data, y->data) < 0)
			{
				x->tmp = x->data;
				x->data = y->data;
				y->data = x->tmp;
			}
			y = y->next;
		}
		x = x->next;
	}
	ft_printf("\nfrom max to min\n");
}

int	ft_last_elem(t_stack *p)
{
	while (p->head->next)
		p->head = p->head->next;
	return (p->head->data);
}

int	check_double(t_stack *a)
{
	t_node	*n;
	t_node	*tmp;

	n = a->head;
	while (n)
	{
		tmp = n->next;
		while (tmp)
		{
			if (n->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		n = n->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*n;
	t_node	*tmp;

	n = a->head;
	tmp = n;
	while (n)
	{
		if (tmp->data > n->data)
			return (0);
		tmp = n;
		n = n->next;
	}
	return (1);
}

int	the_max(t_stack *a)
{
	t_node	*n;
	int		max;

	n = a->head;
	max = n->data;
	while (n)
	{
		if (n->data > max)
			max = n->data;
		n = n->next;
	}
	return (max);
}

int	the_min(t_stack *a)
{
	t_node	*n;
	int		min;

	n = a->head;
	min = n->data;
	while (n)
	{
		if (n->data < min)
			min = n->data;
		n = n->next;
	}
	return (min);
}

int	where_is_i(t_stack *d, int v)
{
	t_node	*n;
	int		i;

	n = d->head;
	i = 0;
	while (n)
	{
		if (n->data == v)
			break;
		i++;
		n = n->next;
	}
	return (i);
}