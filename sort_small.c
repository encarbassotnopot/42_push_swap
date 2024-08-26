/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:18:58 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/26 10:20:22 by ecoma-ba         ###   ########.fr       */
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
