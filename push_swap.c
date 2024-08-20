/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/20 11:48:14 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*a;
	t_stack	*b;
	int		**nums;
	int		i;

	if (argc == 1)
		exit(0);
	if (create_numarr(argc, argv, &nums))
	{
		ft_printerr("Error\n");
		exit(1);
	}
	a = create_stack('a');
	b = create_stack('b');
	i = -1;
	while (nums[++i])
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
