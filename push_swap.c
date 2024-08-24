/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/24 18:56:44 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stacks[])
{
	if (peek_pos_at(stacks, 0, 1) > peek_pos_at(stacks, 0, 2)
		&& peek_pos_at(stacks, 0, 2) > peek_pos_at(stacks, 0, 0))
	{
		do_rrot(stacks[0]);
		do_swap(stacks[0]);
	}
	else if (peek_pos_at(stacks, 0, 0) > peek_pos_at(stacks, 0, 1)
		&& peek_pos_at(stacks, 0, 1) > peek_pos_at(stacks, 0, 2))
	{
		do_swap(stacks[0]);
		do_rrot(stacks[0]);
	}
	else if (peek_pos_at(stacks, 0, 2) > peek_pos_at(stacks, 0, 0)
		&& peek_pos_at(stacks, 0, 0) > peek_pos_at(stacks, 0, 1))
		do_swap(stacks[0]);
	else if (peek_pos_at(stacks, 0, 1) > peek_pos_at(stacks, 0, 0))
		do_rrot(stacks[0]);
	else
		do_rot(stacks[0]);
}

void	sort_5(t_stack *stacks[])
{
	do_push(stacks[0], stacks[1]);
	do_push(stacks[0], stacks[1]);
	if (peek_pos_at(stacks, 2, 0) > peek_pos_at(stacks, 2, 1))
		do_swap(stacks[1]);
	sort_3(stacks);
	int i = -1;
	// TODO resoldre això
}

void	sort_small(t_stack *stacks[])
{
	if (stacks[STACK_A]->len == 3)
		sort_3(stacks);
	else
		sort_5(stacks);
}

int	main(int argc, char **argv)
{
	t_stack			*stacks[2];
	int				**nums;
	unsigned int	*order;
	int				i;
	unsigned int	len;
	t_op_center		oc;

	oc.ops = NULL;
	if (argc == 1)
		exit(0);
	len = create_numarr(argc, argv, &nums);
	order = ft_calloc(sizeof(unsigned int), len);
	if (!len || !order)
	{
		ft_free_arr((void **)nums);
		free(order);
		ft_printerr("Error\n");
		exit(1);
	}
	gen_order(nums, order, len);
	stacks[0] = create_stack('a', &oc);
	stacks[1] = create_stack('b', &oc);
	i = -1;
	while (nums[++i])
		append_node(stacks[0], *nums[i], order[i]);
	free(order);
	ft_free_arr((void **)nums);
	if ((len == 3 || len == 5) && !is_sorted(stacks, 0, len))
		sort_small(stacks);
	else
		quick_sort(stacks, 0, 0, len);
	optimize_operations(&oc.ops);
	print_operations(oc.ops);
	free_operations(&oc.ops);
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
