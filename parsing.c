/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:46:34 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/08 17:13:58 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_word_count(char const *s, char c)
{
	int		i;
	int		d_count;

	i = 0;
	d_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i + 1])
				i++;
			d_count++;
		}
		i++;
	}
	return (d_count);
}

char	**ft_ptrptr(char *s, char **ptr, char c)
{
	int	i;
	int	let_count;
	int	d_count;

	i = 0;
	d_count = ft_word_count(s, c);
	while (i < d_count)
	{
		let_count = 0;
		while (*s != c && *s)
		{
			let_count++;
			s++;
		}
		if (let_count != 0)
		{
			ptr[i] = (char *)malloc(sizeof(char) * (let_count + 1));
			ft_strlcpy(ptr[i], s - let_count, let_count + 1);
			i++;
		}
		s++;
	}
	return (ptr);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		d_count;
	char	**ptr;

	if (!s)
		return (NULL);
	i = 0;
	d_count = ft_word_count(s, c);
	ptr = (char **)malloc(sizeof(int *) * (d_count + 1));
	if (!ptr)
		return (NULL);
	ptr[d_count] = NULL;
	return (ft_ptrptr(s, ptr, c));
}

void	free_arr(long **arr)
{
	if (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
	}
}

int	parsing(int argc, char **argv, long **final_arr)
{
	char	*joined;
	char	**splitted;
	long	*array;
	int		i;
	int		len;

	i = 0;
	joined = my_join(argc, argv);
	splitted = ft_split(joined, ' ');
	free(joined);
	joined = NULL;
	len = arr_count(splitted);
	array = create_arr(splitted, len);
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	splitted = NULL;
	check(array, len);
	*final_arr = array;
	return (len);
}
