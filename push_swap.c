/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:07 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/25 14:32:23 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int v)
{
	t_node	*out;

	out = (t_node *)malloc(sizeof(t_node));
	if (!out)
	{
		free(out);
		return (NULL);
	}
	out->data = v;
	out->next = 0;
	out->prev = 0;
	return (out);
}

t_stack	*new_stack()
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(t_stack));
	if (!out)
	{
		free(out);
		return (NULL);
	}
	out->head = 0;
	return (out);
}

void	print_stks(t_stack *a, t_stack *b)
{
	int		i, j;
	t_node	*n;

	i = 0;
	n = a->head;
	ft_printf("\nSTACK A\n\n");
	while (n)
	{
		ft_printf("%d. %d\n", ++i, n->data);
		n = n->next;
	}
	j = 0;
	ft_printf("\nSTACK B\n\n");
	n = b->head;
	while (n)
	{
		ft_printf("%d. %d\n", ++j, n->data);
		n = n->next;
	}
	ft_printf("\n#########################\n\n");
}

// t_stack	*sort_a(t_stack *a)
// {
	
// }

t_stack	*sort_b(t_stack *a, t_stack *b)
{
	if (ft_lst_size(a) > 3 && !is_sorted(a))
	{
		pb(a, b, 1);
		pb(a, b, 1);
	}
	return (b);
}

int main(int ac, char **av)
{
	int	i, i_a, i_b, cnt;
	t_stack	*a, *b;

	i = 1;
	i_a = 0;
	i_b = 0;
	cnt = 0;
	a = new_stack();
	b = new_stack();
	while (i < ac)
		in_tail(a, ft_atoi(av[i++]));
	print_stks(a, b);
	i_a = where_is_i(a, the_max(a));
	if (ac > 3 && !check_double(a))
	{
		b = sort_b(a, b);
		i_b = where_is_i(b, the_max(b));
		if (i_b != 0)
			rb(b, 1);
			pb(a, b, 1);
		print_stks(a, b);
	}
	ft_exit(a);
	ft_exit(b);

	// (void)ac;
	// (void)av;
	// t_stack	*a, *b;
	
	// a = new_stack();
	// b = new_stack();

	// in_tail(a, 11);
	// in_tail(a, 12);
	// in_tail(a, 13);
	// in_tail(a, 14);

	// in_tail(b, 21);
	// in_tail(b, 22);
	// in_tail(b, 23);
	// in_tail(b, 24);

	// print_stks(a, b);
	// // print_stks(a, b);
	
	// ft_printf("last-> %d\n", ft_last_elem(b));
	// ft_printf("min-> %d\n", the_min(a));
	// ft_printf("index-> %d\n", where_is_i(a, 12));
}