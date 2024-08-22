/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/22 12:13:07 by ecoma-ba         ###   ########.fr       */
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
	printf("SPLITTNG\n");
	i = -1;
	while (++i < len)
	{
		if (LOCATION(pos) == BOT)
			do_rrot(stacks[STACK(pos)]);
		if (stacks[STACK(pos)]->contents->final_pos < start + len / 3)
		{
			do_push(stacks[STACK(pos)], stacks[OTHER(pos)]);
			do_rot(stacks[OTHER(pos)]);
		}
		else if (stacks[STACK(pos)]->contents->final_pos < start + len * 2 / 3)
			do_push(stacks[STACK(pos)], stacks[OTHER(pos)]);
		else if (LOCATION(pos) == TOP)
			do_rot(stacks[STACK(pos)]);
	}
}

/*
 * Sorts the stack in ascending order.
 */
void	sort_up(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	i;

	if (len <= 1)
		return ;
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("SPLITTNG\n");
	threeway_split(stacks, pos, start, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, len - len * 2 / 3);
	quick_sort(stacks, S_MID(pos), start + len / 3, len * 2 / 3 - len / 3);
	quick_sort(stacks, S_MIN(pos), start, len / 3);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING\n");
	i = len;
	while (i > len * 2 / 3)
	{
		if (LOCATION(pos) == TOP)
			do_rrot(stacks[STACK(pos)]);
		else
			do_rot(stacks[STACK(pos)]);
		i--;
	}
	while (i > len / 3)
	{
		do_push(stacks[OTHER(pos)], stacks[STACK(pos)]);
		if (LOCATION(pos) == BOT)
			do_rot(stacks[STACK(pos)]);
		i--;
	}
	while (i > 0)
	{
		do_rrot(stacks[OTHER(pos)]);
		do_push(stacks[OTHER(pos)], stacks[STACK(pos)]);
		if (LOCATION(pos) == BOT)
			do_rot(stacks[STACK(pos)]);
		i--;
	}
	print_stack(stacks[0]);
	print_stack(stacks[1]);
}

/*
 * Sorts the stack in descending order.
 */
void	sort_down(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	unsigned int	i;

	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("SPLITTNG\n");
	threeway_split(stacks, pos, start, len);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	quick_sort(stacks, S_MAX(pos), start + len * 2 / 3, len - len * 2 / 3);
	quick_sort(stacks, S_MID(pos), start + len / 3, len * 2 / 3 - len / 3);
	quick_sort(stacks, S_MIN(pos), start, len / 3);
	printf("start %d, end %d, len %d\n", start, start + len, len);
	printf("MERGING\n");
	i = 0;
	while (i < len / 3)
	{
		do_rrot(stacks[OTHER(pos)]);
		do_push(stacks[OTHER(pos)], stacks[STACK(pos)]);
		if (LOCATION(pos) == BOT)
			do_rot(stacks[STACK(pos)]);
		i++;
	}
	while (i < len * 2 / 3)
	{
		do_push(stacks[OTHER(pos)], stacks[STACK(pos)]);
		if (LOCATION(pos) == BOT)
			do_rot(stacks[STACK(pos)]);
		i++;
	}
	while (i < len)
	{
		if (LOCATION(pos) == TOP)
			do_rrot(stacks[STACK(pos)]);
		else
			do_rot(stacks[STACK(pos)]);
		i++;
	}
	print_stack(stacks[0]);
	print_stack(stacks[1]);
}

void	quick_sort(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	if (len <= 1)
		return ;
	if (STACK(pos) == STACK_A)
		sort_up(stacks, pos, start, len);
	else
		sort_down(stacks, pos, start, len);
	return ;
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
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
