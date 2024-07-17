/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:50:01 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/04 14:24:20 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **head)
{
	t_list	*current;
	t_list	*new_head;

	current = NULL;
	new_head = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	new_head = ft_lstlast(*head);
	while (current->next->next != NULL)
		current = current->next;
	current->next = NULL;
	new_head->next = *head;
	*head = new_head;
}

void	rra(t_list	**a, int count)
{
	while (count != 0)
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
		count--;
	}
}

void	rrb(t_list	**b, int count)
{
	while (count != 0)
	{
		rev_rotate(b);
		write(1, "rrb\n", 4);
		count--;
	}
}

void	rrr(t_list	**a, t_list	**b)
{
	rotate(a);
	rotate(b);
	write(1, "rrr\n", 4);
}
