/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sublist_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:35 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/24 17:16:46 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Pushes a sublist from the top of one stack to the top of another one
 * while keeping the elements in order.
 */
void	push_sublist(t_stack *from, t_stack *to, unsigned int len)
{
	unsigned int	i;

	if (len == 0)
		return ;
	rot_sublist(from, len - 1);
	if (len)
		do_push(from, to);
	i = 0;
	while (++i < len)
	{
		do_rrot(from);
		do_push(from, to);
	}
}

/**
 * Pushes a sublist from the bottom of one stack to the top of another one
 * or viceversa while keeping the elements in order.
 */
void	direct_push_sublist(t_stack *stacks[], int pos, unsigned int len)
{
	unsigned int	i;

	i = -1;
	while (++i < len)
	{
		if (LOCATION(pos) == BOT)
			do_rrot(stacks[STACK(pos)]);
		do_push(stacks[STACK(pos)], stacks[OTHER(pos)]);
		if (LOCATION(pos) == TOP)
			do_rot(stacks[OTHER(pos)]);
	}
}

/**
 * Rotates a sublist
 */
void	rot_sublist(t_stack *stack, unsigned int len)
{
	unsigned int	i;
	void			(*my_rot)(t_stack *);

	my_rot = do_rot;
	if (len == stack->len)
		return ;
	if (len > stack->len / 2)
		my_rot = do_rrot;
	i = -1;
	while (++i < len)
		my_rot(stack);
}

/**
 * Reverse-rotates a sublist
 */
void	rrot_sublist(t_stack *stack, unsigned int len)
{
	unsigned int	i;
	void			(*my_rrot)(t_stack *);

	my_rrot = do_rrot;
	if (len == stack->len)
		return ;
	if (len > stack->len / 2)
		my_rrot = do_rot;
	i = -1;
	while (++i < len)
		my_rrot(stack);
}

/**
 * Moves a sublist from the position indicated by start
 * to the one indicated by end.
 */
void	move_sublist(t_stack *stacks[], int start, int end, unsigned int len)
{
	if (start == end)
		return ;
	if (LOCATION(start) != LOCATION(end) && STACK(start) != STACK(end))
		return (direct_push_sublist(stacks, start, len));
	else if (STACK(start) != STACK(end) && LOCATION(start) == BOT)
	{
		direct_push_sublist(stacks, start, len);
		rot_sublist(stacks[STACK(end)], len);
		return ;
	}
	if (LOCATION(start) == BOT && stacks[STACK(start)]->len != len)
		rrot_sublist(stacks[STACK(start)], len);
	if (STACK(start) != STACK(end))
		push_sublist(stacks[STACK(start)], stacks[STACK(end)], len);
	if (LOCATION(end) == BOT && stacks[STACK(end)]->len != len)
		rot_sublist(stacks[STACK(end)], len);
}
