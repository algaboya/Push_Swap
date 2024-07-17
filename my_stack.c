/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:38:16 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/01 18:36:52 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

void	append(t_list **a_stack, int value)
{
	t_list	*new;

	new = create_node(value);
	if (!new)
		return ;
	if (*a_stack == NULL)
		*a_stack = new;
	else
		ft_lstadd_back(a_stack, new);
}

t_list	*my_stack(int lenarr, long *arr)
{
	int		i;
	t_list	*a_stack;

	i = 0;
	a_stack = NULL;
	while (i < lenarr)
	{
		append(&a_stack, arr[i]);
		i++;
	}
	return (a_stack);
}
