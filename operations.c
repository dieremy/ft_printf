/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:44:51 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/25 10:05:57 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.*/
int	sa(t_stack *a, int f)
{
	t_node	*n;
	
	n = a->head;
	if (!a->head || n->next)
		return (0);
	n->tmp = n->data;
	n->data = n->next->data;
	n->next->data = n->tmp;
	if (f == 1)
		ft_printf("sa\n");
	return (1);
}

/*swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.*/
int	sb(t_stack *b, int f)
{
	t_node	*n;

	n = b->head;
	if (!b->head || !b->head->next)
		return (0);
	n->tmp = n->data;
	n->data = n->next->data;
	n->next->data = n->tmp;
	if (f == 1)
		ft_printf("sb\n");
	return (1);
}

/*sa and sb at the same time.*/
int	ss(t_stack *a, t_stack *b, int f)
{
	t_node	*na;
	t_node	*nb;
	
	na = a->head;
	nb = b->head;
	na->tmp = na->data;
	na->data = na->next->data;
	na->next->data = na->tmp;
	nb->tmp = nb->data;
	nb->data = nb->next->data;
	nb->next->data = nb->tmp;	
	if (f == 1)
		ft_printf("ss\n");
	return (1);
}
/*push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.*/
int	pa(t_stack *a, t_stack *b, int f)
{
	t_node	*n;

	if (!b->head)
		return (0);
	n = a->head;
	a->head = b->head;
	b->head = b->head->next;
	a->head->next = n;
	if (f == 1)
		ft_printf("pa\n");
	return (1);
}

/*push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.*/
int	pb(t_stack *a, t_stack *b, int f)
{
	t_node	*n;
	
	if (a->head == NULL)
		return (0);
	n = b->head;
	b->head = a->head;
	a->head = a->head->next;
	b->head->next = n;
	if (f == 1)
		ft_printf("pb\n");
	return (1);
}

/*rotate a - shift up all elements of stack a by 1. The first element becomes the last one.*/
int	ra(t_stack *a, int f)
{
	t_node	*n;
	t_node	*tmp;
	
	n = a->head;
	tmp = n;
	while (n->next)
		n = n->next;
	n->next = tmp;
	a->head = tmp->next;
	tmp->next = NULL;
	if (f == 1)
		ft_printf("ra\n");
	return (1);
}

/*rotate b - shift up all elements of stack b by 1. The first element becomes the last one.*/
int	rb(t_stack *b, int f)
{
	t_node	*tmp;

	tmp = b->head;
	while (b->head->next)
		b->head = b->head->next;
	b->head->next = tmp;
	b->head = tmp->next;
	tmp->next = NULL;
	if (f == 1)
		ft_printf("rb\n");
	return (1);
}

/*ra and rb at the same time.*/
int	rr(t_stack *a, t_stack *b, int f)
{
	t_node	*na;
	t_node	*nb;
	t_node	*tmp;

	na = a->head;
	tmp = na;
	while (na->next)
		na = na->next;
	na->next = tmp;
	a->head = tmp->next;
	tmp->next = 0;
	nb = b->head;
	tmp = nb;
	while (nb->next)
		nb = nb->next;
	nb->next = tmp;
	b->head = tmp->next;
	tmp->next = NULL;
	if (f == 1)
		ft_printf("rr\n");
	return (1);
}
/*reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.*/
int	rra(t_stack *a, int f)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->head;
	while (a->head->next)
	{
		a->head = a->head->next;
		i++;
	}
	a->head->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (f == 1)
		ft_printf("rra");
	return (1);
}

/*reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.*/
int	rrb(t_stack *b, int f)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = b->head;
	while (b->head->next)
	{
		b->head = b->head->next;
		i++;
	}
	b->head->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (f == 1)
		ft_printf("rrb\n");
	return (1);
}

/*rra and rrb at the same time.*/
int	rrr(t_stack *a, t_stack *b, int f)
{
	rra(a, 0);
	rrb(b, 0);
	if (f == 1)
		ft_printf("rrr\n");
	return (1);
}