/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:57:21 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/11 17:09:21 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*current;
	t_list	*new_head;

	current = NULL;
	new_head = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	new_head = (*head)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	(*head)->next = NULL;
	*head = new_head;
}

void	ra(t_list	**a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list	**b, int count)
{
	while (count != 0)
	{
		rotate(b);
		write(1, "rb\n", 3);
		count--;
	}
}

void	rr(t_list	**a, t_list	**b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

int	count_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}
