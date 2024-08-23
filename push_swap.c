/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/23 14:55:15 by ecoma-ba         ###   ########.fr       */
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

void	base_case(t_stack *stacks[], int pos, int len)
{
	t_node	*first;
	t_node	*second;

	if (len < 2)
		return ;
	if (peek_pos_at(stacks, pos, 0) < peek_pos_at(stacks, pos, 1))
		return ;
	if (LOCATION(pos) == BOT)
		rrot_sublist(stacks[STACK(pos)], 2);
	do_swap(stacks[STACK(pos)]);
	if (LOCATION(pos) == BOT)
		rot_sublist(stacks[STACK(pos)], 2);

}

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

void	sort_down(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	sublen;

	sublen = len / 3;
	quick_sort(stacks, S_MIN(pos), start, len / 3);
	move_sublist(stacks, S_MIN(pos), pos, sublen);
	//
	sublen = len * 2 / 3 - len / 3;
	quick_sort(stacks, S_MID(pos), start + len / 3, sublen);
	move_sublist(stacks, S_MID(pos), pos, sublen);
	//
	sublen = len - len * 2 / 3;
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, sublen);
	move_sublist(stacks, S_MAX(pos), pos, sublen);
}

void	sort_up(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	sublen;

	sublen = len - len * 2 / 3;
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, sublen);
	move_sublist(stacks, S_MAX(pos), pos, sublen);
	//
	sublen = len * 2 / 3 - len / 3;
	quick_sort(stacks, S_MID(pos), start + len / 3, sublen);
	move_sublist(stacks, S_MID(pos), pos, sublen);
	//
	sublen = len / 3;
	quick_sort(stacks, S_MIN(pos), start, len / 3);
	move_sublist(stacks, S_MIN(pos), pos, sublen);
}

/*
 * Sorts the stack.
 */
void	quick_sort(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	if (len <= 2)
		return base_case(stacks, pos, len);
	threeway_split(stacks, pos, start, len);
	print_stack(stacks[0]);
	// això em fa funcionar bé una ordenació de 9 elements,
	// però hauria de ser solament una optimització.
	/*if (peek_pos(stacks, MY_TOP(pos)) < start + len*/
	/*	&& peek_pos(stacks, MY_TOP(pos)) >= start)*/
	/*	pos = MY_TOP(pos);*/
	//
	print_stack(stacks[0]);
	if (pos == 0 || pos == 2)
		sort_up(stacks, pos, start, len);
	else
		sort_down(stacks, pos, start, len);
}

int	main(int argc, char **argv)
{
	t_node			*node;
	t_stack			*stacks[2];
	int				**nums;
	unsigned int	*order;
	int				i;
	unsigned int	len;

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
	stacks[0] = create_stack('a');
	stacks[1] = create_stack('b');
	i = -1;
	while (nums[++i])
	{
		node = create_node(*nums[i], order[i]);
		if (node)
			append_node(node, stacks[0]);
	}
	free(order);
	ft_free_arr((void **)nums);
	print_stack(stacks[0]);
	quick_sort(stacks, 0, 0, len);
	print_stack(stacks[0]);
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
