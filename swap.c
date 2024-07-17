/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:41:24 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/04 20:44:56 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**stack)
{
	long	temp;

	if (*stack == NULL || (*stack)->next == NULL || !stack)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	sa(t_list	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list	**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list	**a, t_list	**b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
