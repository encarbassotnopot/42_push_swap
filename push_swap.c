/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/19 17:33:54 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the given int is already part of the array arr.
 * Appends the number to the array if not repeated.
 * Returns 1 if repeated or on malloc error, 0 otherwise.
 */
int	is_repeated(int num, int **arr)
{
	int	i;
	int	*ptr;

	i = -1;
	while (arr[++i])
		if (*arr[i] == num)
			return (1);
	ptr = ft_calloc(sizeof(int), 1);
	if (!ptr)
		return (1);
	*ptr = num;
	arr[i] = ptr;
	return (0);
}

/**
 * Parses the given char*, creates nodes with its values and pushes them
 * to the given stack.
 * Returns 1 on error (memory error, invalid number...), 0 otherwise.
 */
int	argv_to_numarr(char *str, int **numarr)
{
	int		i;
	int		num;
	char	**splits;

	splits = ft_split(str, ' ');
	if (!splits)
		return (1);
	i = -1;
	while (splits[++i])
	{
		num = ft_atoi(splits[i]);
		if (!ft_isnumstr(splits[i]) || (num == 0 && errno == ERANGE)
			|| is_repeated(num, numarr))
		{
			ft_printf("Error: Repeated num\n");
			ft_free_arr((void **)splits);
			return (1);
		}
	}
	ft_free_arr((void **)splits);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*a;
	t_stack	*b;
	int		**nums;

	int n, i;
	i = 0;
	n = 0;
	while (++i < argc)
		n += ft_split_count(argv[i], ' ');
	nums = ft_calloc(sizeof(int *), n + 1);
	i = 0;
	while (argv[++i])
	{
		if (argv_to_numarr(argv[i], nums))
		{
			ft_free_arr((void **)nums);
			exit(1);
		}
	}
	a = create_stack('a');
	b = create_stack('b');
	i = -1;
	while (++i < n)
	{
		node = create_node(*nums[i]);
		if (node)
			append_node(node, a);
	}
	ft_free_arr((void **)nums);
	print_stack(a);
	print_stack(b);
	/*do_push(a, b);*/
	/*do_push(a, b);*/
	/*do_push(a, b);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	/*do_rot(a);*/
	/*do_rot(a);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	/*do_rrot(a);*/
	/*do_rrot(a);*/
	/*do_rrot(a);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	/*do_swap(a);*/
	/*do_swap(b);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	free_stack(&a);
	free_stack(&b);
}
