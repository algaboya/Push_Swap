/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:45:25 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/14 18:26:43 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_sign(char **argv, int i, int j)
{
	if (!is_digit(argv[i][j + 1]))
		return (0);
	if (j != 0 && argv[i][j - 1] != ' ')
		return (0);
	return (1);
}

void	spases(char **argv)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				k++;
			j++;
		}
		if (ft_strlen(argv[i]) == k)
			ft_error();
		j = 0;
		i++;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	// system("leaks push_swap");
	exit(1);
}

int	is_valid(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (!is_digit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '+' && argv[i][j] != '-')
				return (0);
			if (argv[i][j] == '+' || argv[i][j] == '-' )
				if (for_sign(argv, i, j) == 0)
					return (0);
			if (argv[i][j] == ' ' && (argv[i][j + 1] != '+'
				&& argv[i][j + 1] != '-' && argv[i][j + 1] != ' '
				&& !is_digit(argv[i][j + 1]) && argv[i][j + 1] != '\0'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	min_max(long num)
{
	if (num <= 2147483647 && num >= -2147483648)
		return (1);
	return (0);
}
