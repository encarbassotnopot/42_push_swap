/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sublist_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:35 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/23 14:42:17 by ecoma-ba         ###   ########.fr       */
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

	i = 0;
	while (++i < len)
		do_rot(from);
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
 * Rotates a sublist
 */
void	rot_sublist(t_stack *stack, unsigned int len)
{
	unsigned int	i;

	i = -1;
	while (++i < len)
		do_rot(stack);
}

/**
 * Reverse-rotates a sublist
 */
void	rrot_sublist(t_stack *stack, unsigned int len)
{
	unsigned int	i;

	i = -1;
	while (++i < len)
		do_rrot(stack);
}

/**
 * Moves a sublist from the position indicated by start
 * to the one indicated by end.
 */
void	move_sublist(t_stack *stacks[], int start, int end, unsigned int len)
{
	if (start == end)
		return ;
	if (LOCATION(start) == BOT)
		rrot_sublist(stacks[STACK(start)], len);
	if (STACK(start) != STACK(end))
		push_sublist(stacks[STACK(start)], stacks[STACK(end)], len);
	if (LOCATION(end) == BOT)
		rot_sublist(stacks[STACK(end)], len);
}
