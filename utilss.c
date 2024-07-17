/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:21:39 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/04 14:22:03 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_arr_sorted(long *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

long	*sorting_arr(long *arr, int len)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	while ((i <= (nb / 2)) && i <= 46340 && (i * i) < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int	ft_log2(unsigned int n)
{
	int	result;

	result = -1;
	while (n)
	{
		n >>= 1;
		result++;
	}
	return (result);
}

int	nstep(int len)
{
	return (ft_sqrt(len) + ft_log2(len) - 1);
}
