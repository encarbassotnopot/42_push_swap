/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/25 16:17:11 by ecoma-ba         ###   ########.fr       */
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
	int	j;
	int	min;

	print_stack(stacks[0]);
	print_stack(stacks[1]);
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
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	do_push(stacks[1], stacks[0]);
	if (peek_pos_at(stacks, TOP_A, 0) > peek_pos_at(stacks, TOP_A, 1)
		&& peek_pos_at(stacks, TOP_A, 0) < peek_pos_at(stacks, TOP_A, 2))
		do_swap(stacks[STACK_A]);
	else if (peek_pos_at(stacks, TOP_A, 0) > peek_pos_at(stacks, TOP_A, 3))
		do_rot(stacks[STACK_A]);
	do_push(stacks[1], stacks[0]);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
}

void	sort_small(t_stack *stacks[])
{
	if (is_sorted(stacks, 0, stacks[STACK_A]->len))
		return ;
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
	if (len == 3 || len == 5)
		sort_small(stacks);
	else
		quick_sort(stacks, 0, 0, len);
	optimize_operations(&oc.ops);
	print_operations(oc.ops);
	free_operations(&oc.ops);
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
