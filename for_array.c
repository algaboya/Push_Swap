/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:23:42 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/11 17:14:53 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *str)
{
	int		i;
	int		j;
	long	val;

	j = 1;
	i = 0;
	val = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == '0' || str[i] == ' ')
		i++;
	if (count_len(str + i) > 11)
		ft_error();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	val *= j;
	return (val);
}

int	arr_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	*create_arr(char **splitted, int count)
{
	int		i;
	long	*my_arr;

	i = 0;
	my_arr = (long *)malloc(sizeof(long) * count);
	while (i < count)
	{
		my_arr[i] = ft_atoi(splitted[i]);
		if (!min_max(my_arr[i]))
			ft_error();
		i++;
	}
	return (my_arr);
}

int	check_dubls(long *my_arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (my_arr[i] == my_arr[j])
			{
				free(my_arr);
				ft_error();
			}
			j++;
		}
		i++;
	}
	return (1);
}
