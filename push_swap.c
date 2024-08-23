/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/23 14:13:19 by ecoma-ba         ###   ########.fr       */
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

void	base_case(t_stack *stacks[], int pos, int len)
{
	t_node	*first;
	t_node	*second;

	if (len < 2)
		return ;
	if (LOCATION(pos) == BOT)
	{
		do_rrot(stacks[STACK(pos)]);
		do_rrot(stacks[STACK(pos)]);
	}
	first = stacks[STACK(pos)]->contents;
	second = first->next;
	if (first->final_pos > second->final_pos)
		do_swap(stacks[STACK(pos)]);
	if (LOCATION(pos) == BOT)
	{
		do_rot(stacks[STACK(pos)]);
		do_rot(stacks[STACK(pos)]);
	}
}

/**

	* Pushes a sublist from the top of one stack to the top of another one while keeping
 * the elements in order.
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
	printf("moving %d els from %d to %d\n", len, start, end);
	if (start == end)
		return ;
	if (LOCATION(start) == BOT)
		rrot_sublist(stacks[STACK(start)], len);
	if (STACK(start) != STACK(end))
		push_sublist(stacks[STACK(start)], stacks[STACK(end)], len);
	if (LOCATION(end) == BOT)
		rot_sublist(stacks[STACK(end)], len);
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

	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("pos %d, min %d, mid %d, max %d\n", pos, S_MIN(pos), S_MID(pos),
		S_MAX(pos));
	printf("SPLITTNG\n");
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
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING MIN\n");
	move_sublist(stacks, S_MIN(pos), pos, sublen);
	//
	sublen = len * 2 / 3 - len / 3;
	quick_sort(stacks, S_MID(pos), start + len / 3, sublen);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING MID\n");
	move_sublist(stacks, S_MID(pos), pos, sublen);
	//
	sublen = len - len * 2 / 3;
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, sublen);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING MAX\n");
	move_sublist(stacks, S_MAX(pos), pos, sublen);
}

void	sort_up(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	sublen;

	sublen = len - len * 2 / 3;
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, sublen);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING MAX\n");
	move_sublist(stacks, S_MAX(pos), pos, sublen);
	//
	sublen = len * 2 / 3 - len / 3;
	quick_sort(stacks, S_MID(pos), start + len / 3, sublen);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING MID\n");
	move_sublist(stacks, S_MID(pos), pos, sublen);
	//
	sublen = len / 3;
	quick_sort(stacks, S_MIN(pos), start, len / 3);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING MIN\n");
	move_sublist(stacks, S_MIN(pos), pos, sublen);
}

/*
 * Sorts the stack.
 */
void	quick_sort(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	sublen;

	if (len <= 1)
		return ;
	threeway_split(stacks, pos, start, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	// això em fa funcionar bé una ordenació de 9 elements,
	// però hauria de ser solament una optimització.
	/*if (peek_pos(stacks, MY_TOP(pos)) < start + len*/
	/*	&& peek_pos(stacks, MY_TOP(pos)) >= start)*/
	/*	pos = MY_TOP(pos);*/
	//
	sublen = len - len * 2 / 3;
	if (pos == 0 || pos == 2)
		sort_up(stacks, pos, start, len);
	else
		sort_down(stacks, pos, start, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
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
	print_stack(stacks[1]);
	quick_sort(stacks, 0, 0, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	/*i = -1;*/
	/*while (++i < 4)*/
	/*	printf("pos %d, stack %d, loc %d, MIN %d, MID %d, MAX %d, top %d, bot
			%d\n",*/
	/*			i, STACK(i), LOCATION(i), S_MIN(i), S_MID(i), S_MAX(i),
					MY_TOP(i), MY_BOT(i));*/
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
