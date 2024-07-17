/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babochka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:13:59 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/04 14:23:15 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_node(t_list *stack)
{
	t_list	*tmp;
	int		max_index;
	int		value;
	int		i;

	i = 0;
	max_index = 0;
	tmp = stack;
	value = tmp->value;
	while (tmp)
	{
		if (tmp->value > value)
		{
			value = tmp->value;
			max_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_index);
}

int	min_node(t_list *stack)
{
	int		i;
	t_list	*min;
	t_list	*current;

	i = 0;
	min = stack;
	current = stack->next;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	current = stack;
	while (current->value > min->value)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	babochka(t_list **a, t_list **b, long *sorted_arr, int len)
{
	int	i;
	int	step;

	i = 0;
	step = nstep(len);
	while (i < len)
	{
		if ((*a)->value <= sorted_arr[i])
		{
			pb(a, b);
			rb(b, 1);
			i++;
		}
		else if ((*a)->value <= sorted_arr[i + step])
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
		if (i + step > len)
			step--;
	}
}

void	final_sort(t_list **a, t_list **b, int len, long *final_arr)
{
	int		i;
	long	*sorted;

	i = 0;
	sorted = sorting_arr(final_arr, len);
	babochka(a, b, sorted, len);
	while (len > 0)
	{
		i = max_node(*b);
		if (i <= (len / 2))
			rb(b, i);
		else if (i > (len / 2))
			rrb(b, len - i);
		pa(a, b);
		len--;
	}
}
