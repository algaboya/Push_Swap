/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:58:16 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/09 17:58:25 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*pushing;

	pushing = (*b);
	(*b) = (*b)->next;
	pushing->next = (*a);
	(*a) = pushing;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*pushing;

	pushing = (*a);
	(*a) = (*a)->next;
	pushing->next = (*b);
	(*b) = pushing;
	write(1, "pb\n", 3);
}
