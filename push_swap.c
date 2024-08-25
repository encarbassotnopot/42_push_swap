/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/25 16:57:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stacks[])
{
	if (is_sorted(stacks, 0, 3))
		return ;
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

/**
 * This should handle the worst imaginable case possible for 5 elements.
 */
void	i_hate_you(t_stack *stacks[])
{
	if (peek_pos_at(stacks, TOP_B, 0) > peek_pos_at(stacks, TOP_A, 1)
		&& peek_pos_at(stacks, TOP_B, 0) < peek_pos_at(stacks, TOP_A, 2))
	{
		do_rrot(stacks[STACK_A]);
		do_push(stacks[STACK_B], stacks[STACK_A]);
		do_rot(stacks[STACK_A]);
		do_rot(stacks[STACK_A]);
	}
}

void	sort_5(t_stack *stacks[])
{
	int	i;

	if (peek_pos_at(stacks, BOT_A, 0) == 0)
		do_rrot(stacks[STACK_A]);
	if (peek_pos_at(stacks, BOT_A, 1) == 0)
	{
		do_rrot(stacks[STACK_A]);
		do_rrot(stacks[STACK_A]);
	}
	i = -1;
	while (++i < 5)
		if (peek_pos_at(stacks, TOP_A, i) == 0)
			break ;
	rot_sublist(stacks[0], i);
	do_push(stacks[0], stacks[1]);
	do_push(stacks[0], stacks[1]);
	sort_3(stacks);
	i_hate_you(stacks);
	do_push(stacks[1], stacks[0]);
	if (peek_pos_at(stacks, TOP_A, 0) > peek_pos_at(stacks, TOP_A, 1)
		&& peek_pos_at(stacks, TOP_A, 0) < peek_pos_at(stacks, TOP_A, 2))
		do_swap(stacks[STACK_A]);
	else if (peek_pos_at(stacks, TOP_A, 0) > peek_pos_at(stacks, TOP_A, 3))
		do_rot(stacks[STACK_A]);
	do_push(stacks[1], stacks[0]);
}

void	begin_sort(t_stack *stacks[])
{
	if (is_sorted(stacks, 0, stacks[STACK_A]->len))
		return ;
	if (stacks[STACK_A]->len == 3)
		sort_3(stacks);
	else if (stacks[STACK_A]->len == 5)
		sort_5(stacks);
	else
		quick_sort(stacks, 0, 0, stacks[STACK_A]->len);
}

int	main(int argc, char **argv)
{
	t_stack			*stacks[2];
	int				**nums;
	unsigned int	*order;
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
	len = -1;
	while (nums[++len])
		append_node(stacks[0], *nums[len], order[len]);
	free(order);
	ft_free_arr((void **)nums);
	begin_sort(stacks);
	optimize_operations(&oc.ops);
	print_operations(oc.ops);
	free_operations(&oc.ops);
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
