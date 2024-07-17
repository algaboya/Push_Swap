/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:52:16 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/14 18:26:31 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ptr(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*my_join(int argc, char **argv)
{
	int		j;
	int		k;
	char	*joined;

	j = 0;
	k = ft_strlen(argv[0]);
	joined = malloc(k * (sizeof(char) + 1));
	while (j != k)
	{
		joined[j] = argv[0][j];
		j++;
	}
	joined[j] = '\0';
	j = 0;
	while (j < (argc - 2))
	{
		joined = usual_join(joined, " ");
		joined = usual_join(joined, argv[j + 1]);
		j++;
	}
	return (joined);
}

char	*usual_join(char *str1, char *str2)
{
	char	*final_join;

	final_join = ft_strjoin(str1, str2);
	free_ptr(&str1);
	return (final_join);
}

void	free_stack(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

int	main(int argc, char *argv[])
{
	int		len;
	long	*arr;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (argc < 2)
		return (0);
	if (is_valid(argv + 1) == 0)
		ft_error();
	spases(argv + 1);
	len = parsing(argc, argv + 1, &arr);
	if (arr == NULL || len == 0)
		return (0);
	a = my_stack(len, arr);
	lit_sort(&a, &b, arr);
	free_stack(&a);
	free_stack(&b);
	// system("leaks push_swap");
	return (0);
}
