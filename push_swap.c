/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/18 19:07:24 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**nums;
	int		i;
	t_node	*node;
	t_stack	*a;
	t_stack	*b;

	a = create_stack('a');
	b = create_stack('b');
	if (argc != 2)
	{
		ft_printf("Wrong args\n");
		exit(EXIT_FAILURE);
	}
	nums = ft_split(argv[1], ' ');
	i = -1;
	while (nums[++i])
	{
		node = create_node(ft_atoi(nums[i]));
		/*if (i % 2 == 0)*/
			append_node(node, a);
		/*else*/
		/*	append_node(node, b);*/
	}
	ft_free_arr(nums);
	print_stack(a);
	print_stack(b);
	do_push(a, b);
	do_push(a, b);
	do_push(a, b);
	print_stack(a);
	print_stack(b);
	do_rot(a);
	do_rot(a);
	print_stack(a);
	print_stack(b);
	do_rrot(a);
	do_rrot(a);
	do_rrot(a);
	print_stack(a);
	print_stack(b);
	do_swap(a);
	do_swap(b);
	print_stack(a);
	print_stack(b);
	free_stack(&a);
	free_stack(&b);
}
