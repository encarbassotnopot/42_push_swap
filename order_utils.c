/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/09/02 16:36:10 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gen_order(int **nums, unsigned int *order, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = -1;
	while (++i < len)
	{
		j = -1;
		count = 0;
		while (++j < len)
			if (*nums[j] < *nums[i])
				count++;
		order[i] = count;
	}
}

/**
 * Returns the final_pos of the node at the given position.
 * Position is TOP_A, TOP_B, BOT_A or BOT_B.
 */
unsigned int	peek_pos(t_stack *stacks[], int pos)
{
	if (LOCATION(pos) == TOP)
		return (stacks[STACK(pos)]->contents->final_pos);
	else
		return (stacks[STACK(pos)]->contents->prev->final_pos);
}

/**
 * Returns the final_pos of the node at the given index in the position.
 * Position is TOP_A, TOP_B, BOT_A or BOT_B.
 */
unsigned int	peek_pos_at(t_stack *stacks[], int pos, unsigned int index)
{
	t_node			*iter;
	unsigned int	i;

	i = -1;
	if (LOCATION(pos) == TOP)
	{
		iter = stacks[STACK(pos)]->contents;
		while (++i < index)
			iter = iter->next;
	}
	else
	{
		iter = stacks[STACK(pos)]->contents->prev;
		while (++i < index)
			iter = iter->prev;
	}
	return (iter->final_pos);
}

/**
 * Returns 1 if the sublist is sorted, 0 otherwise.
 */
unsigned int	is_sorted(t_stack *stacks[], int pos, unsigned int len)
{
	t_node			*iter;
	unsigned int	i;

	i = 0;
	if (LOCATION(pos) == TOP)
	{
		iter = stacks[STACK(pos)]->contents;
		while (++i < len)
		{
			if (iter->final_pos > iter->next->final_pos)
				return (0);
			iter = iter->next;
		}
	}
	else
	{
		iter = stacks[STACK(pos)]->contents->prev;
		while (++i < len)
		{
			if (iter->final_pos < iter->prev->final_pos)
				return (0);
			iter = iter->prev;
		}
	}
	return (1);
}
