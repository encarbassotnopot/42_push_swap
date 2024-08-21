/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/21 10:47:27 by ecoma-ba         ###   ########.fr       */
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

void	quick_sort(t_stack *stacks[], int pos, unsigned int start,
		unsigned int len)
{
	int		stop;
	int		i;
	t_node	iter;

	i = -1;
	unsigned int limits = {start + len * 1 / 3, start + len * 2 / 3, start + len}
	iter = stacks[STACK(pos)]->contents;
	stop = iter->prev->final_pos;
	while (++i < len)
	{
		if (iter->final_pos < start + len * 1 / 3)
		{
			do_push(stacks[STACK(pos)], stacks[OTHER(pos)]);
			do_rot(stacks[OTHER(pos)]);
		}
		else if (iter->final_pos < start + len * 2 / 3)
			do_push(stacks[STACK(pos)], stacks[OTHER(pos)]);
		else
			do_rot(stacks[STACK(pos)]);
	}
	quick_sort(stacks, S_MAX(i), start + len * 2 / 3, len - len * 2 / 3);
	quick_sort(stacks, S_MID(i), start + len * 1 / 3, len * 2 / 3 - len * 1 / 3);
	quick_sort(stacks, S_MIN(i), start, len * 1 / 3);
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
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}
