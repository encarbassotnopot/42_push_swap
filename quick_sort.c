/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/09/02 16:06:18 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Splits a len amount of elements from the given position.
 * Top third will get rotated to the other end of the current stack.
 * The second third will get split to the top of the other stack, and
 * the bottom third to the end of the other stack.
 */
void	threeway_split(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	i;

	i = -1;
	while (++i < len)
	{
		if (peek_pos(stacks, pos) < start + len / 3)
			move_sublist(stacks, pos, S_MIN(pos), 1);
		else if (peek_pos(stacks, pos) < start + len * 2 / 3)
			move_sublist(stacks, pos, S_MID(pos), 1);
		else
			move_sublist(stacks, pos, S_MAX(pos), 1);
	}
}

void	sort_up(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	sublen1;
	unsigned int	sublen2;
	unsigned int	sublen3;

	sublen1 = len - len * 2 / 3;
	sublen2 = len * 2 / 3 - len / 3;
	sublen3 = len / 3;
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, sublen1);
	quick_sort(stacks, S_MID(pos), start + len / 3, sublen2);
	quick_sort(stacks, S_MIN(pos), start, sublen3);
	move_sublist(stacks, S_MAX(pos), pos, sublen1);
	move_sublist(stacks, S_MID(pos), pos, sublen2);
	move_sublist(stacks, S_MIN(pos), pos, sublen3);
}

void	sort_down(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	sublen1;
	unsigned int	sublen2;
	unsigned int	sublen3;

	sublen1 = len - len * 2 / 3;
	sublen2 = len * 2 / 3 - len / 3;
	sublen3 = len / 3;
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, sublen1);
	quick_sort(stacks, S_MID(pos), start + len / 3, sublen2);
	quick_sort(stacks, S_MIN(pos), start, sublen3);
	move_sublist(stacks, S_MAX(pos), pos, sublen1);
	move_sublist(stacks, S_MID(pos), pos, sublen2);
	move_sublist(stacks, S_MIN(pos), pos, sublen3);
}

/*
 * Sorts the stack.
 */
void	quick_sort(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	if (len <= 3)
		return (base_case(stacks, pos, len));
	if (is_sorted(stacks, pos, len))
		return ;
	threeway_split(stacks, pos, start, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	if (LOCATION(pos) == TOP)
		sort_up(stacks, pos, start, len);
	else
		sort_down(stacks, pos, start, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
}
