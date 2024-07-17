/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lit_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:37:49 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/05 11:56:46 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_list **a)
{
	if ((*a)->next->value > (*a)->value
		&& (*a)->next->value < (*a)->next->next->value)
		return ;
	if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		rra(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
	{
		rra(a, 1);
		sa(a);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		ra(a);
	else
	{
		sa(a);
		rra(a, 1);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	if (((*a)->value < (*a)->next->value)
		&& ((*a)->value < (*a)->next->next->value)
		&& ((*a)->value < (*a)->next->next->next->value))
		pb(a, b);
	else
	{
		if (((*a)->next->value < (*a)->value)
			&& ((*a)->next->value < (*a)->next->next->value)
			&& ((*a)->next->value < (*a)->next->next->next->value))
			sa(a);
		else if (((*a)->next->next->value < (*a)->value)
			&& ((*a)->next->next->value < (*a)->next->value)
			&& ((*a)->next->next->value < (*a)->next->next->next->value))
			rra(a, 2);
		else
			rra(a, 1);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	i;

	i = min_node(*a) + 1;
	if (i == 2)
		sa(a);
	else if (i == 3)
		rra(a, 3);
	else if (i == 4)
		rra(a, 2);
	else if (i == 5)
		rra(a, 1);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	lit_sort(t_list **a, t_list **b, long *final)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 1)
		return ;
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else
		final_sort(a, b, len, final);
}
