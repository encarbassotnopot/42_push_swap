/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:18:46 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/23 17:22:43 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	base_case_2(t_stack *stacks[], int pos)
{
	const int	len = 2;

	if (peek_pos_at(stacks, pos, 0) < peek_pos_at(stacks, pos, 1)
		&& LOCATION(pos) == TOP)
		return ;
	if (peek_pos_at(stacks, pos, 0) > peek_pos_at(stacks, pos, 1)
		&& LOCATION(pos) == BOT)
		return ;
	if (LOCATION(pos) == BOT)
		rrot_sublist(stacks[STACK(pos)], len);
	do_swap(stacks[STACK(pos)]);
	if (LOCATION(pos) == BOT)
		rot_sublist(stacks[STACK(pos)], len);
}

// TODO
void	base_case_3(t_stack *stacks[], int pos)
{
	const int	len = 3;

	if (peek_pos_at(stacks, pos, 1) < peek_pos_at(stacks, pos, 2)
		&& LOCATION(pos) == TOP)
		return (base_case_2(stacks, pos));
	if (peek_pos_at(stacks, pos, 1) > peek_pos_at(stacks, pos, 2)
		&& LOCATION(pos) == BOT)
		return (base_case_2(stacks, pos));
	if (LOCATION(pos) == BOT)
		rrot_sublist(stacks[STACK(pos)], len);
	do_push(stacks[STACK(pos)], stacks[OTHER(pos)]);
	base_case_2(stacks, MY_TOP(pos));
	do_push(stacks[OTHER(pos)], stacks[STACK(pos)]);
	base_case_2(stacks, MY_TOP(pos));
	if (LOCATION(pos) == BOT)
		rot_sublist(stacks[STACK(pos)], len);
}

void	base_case(t_stack *stacks[], int pos, int len)
{
	if (len < 2)
		return ;
	if (len == 2)
		base_case_2(stacks, pos);
	if (len == 3)
		base_case_3(stacks, pos);
}
