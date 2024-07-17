/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:01:53 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/09 17:35:57 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

int		arr_count(char **str);
long	*create_arr(char **splitted, int count);
int		ft_word_count(char const *s, char c);
char	**ft_ptrptr(char *s, char **ptr, char c);
char	**ft_split(char *s, char c);

int		ft_strlen(char *str);
int		parsing(int argc, char **argv, long **final_arr);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
int		is_digit(char c);
char	*my_join(int argc, char **argv);
long	ft_atoi(char *str);
int		for_sign(char **argv, int i, int j);
int		count_len(char *str);
int		ft_lstsize(t_list *lst);

t_list	*create_node(int value);
t_list	*ft_lstlast(t_list *lst);
t_list	*my_stack(int lenarr, long *arr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	append(t_list **a_stack, int value);
int		min_node(t_list *stack);
int		max_node(t_list *stack);
int		nstep(int len);
int		ft_log2(unsigned int n);
int		ft_sqrt(int nb);

//validation

int		is_valid(char **argv);
int		check_dubls(long *my_arr, int len);
int		min_max(long num);
void	ft_error(void);
void	check(long *array, int len);
void	spases(char **argv);

//operators

void	sa(t_list	**a);
void	sb(t_list	**b);
void	ss(t_list	**a, t_list	**b);
void	ra(t_list	**a);
void	rb(t_list	**b, int count);
void	rr(t_list	**a, t_list	**b);
void	rra(t_list	**a, int count);
void	rrb(t_list	**b, int count);
void	rrr(t_list	**a, t_list	**b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	swap(t_list	**stack);
void	rotate(t_list **head);
void	rev_rotate(t_list **head);

// sorts

void	lit_sort(t_list **a, t_list **b, long *final);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
int		is_arr_sorted(long *arr, int len);
long	*sorting_arr(long *arr, int len);
void	babochka(t_list **a, t_list **b, long *sorted_arr, int len);
void	final_sort(t_list **a, t_list **b, int len, long *final_arr);
void	free_stack(t_list **head);
void	free_arr(long **arr);
void	free_ptr(char **ptr);
char	*usual_join(char *str1, char *str2);

#endif
