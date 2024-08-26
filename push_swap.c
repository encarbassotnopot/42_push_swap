/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/26 10:34:26 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_sort(t_stack *stacks[], t_op_center *oc)
{
	if (is_sorted(stacks, 0, stacks[STACK_A]->len))
		return ;
	if (stacks[STACK_A]->len == 3)
		sort_3(stacks);
	else if (stacks[STACK_A]->len == 5)
		sort_5(stacks);
	else
		quick_sort(stacks, 0, 0, stacks[STACK_A]->len);
	optimize_operations(&oc->ops);
	print_operations(oc->ops);
	free_operations(&oc->ops);
	free_stack(&stacks[0]);
	free_stack(&stacks[1]);
}

/**
 * Frees all operations.
 */
void	free_operations(t_operation **list)
{
	t_operation	*iter;
	t_operation	*next;

	iter = *list;
	while (iter && iter->next != *list)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
	free(iter);
	*list = NULL;
}

int	gen_stacks(t_stack *stacks[], int **nums, unsigned int *order,
	t_op_center *oc)
{
	int	i;

	stacks[0] = create_stack('a', oc);
	stacks[1] = create_stack('b', oc);
	if (!stacks[0] || !stacks[1])
		return (0);
	i = -1;
	while (nums[++i])
		append_node(stacks[0], *nums[i], order[i]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack			*stacks[2];
	int				**nums;
	unsigned int	*order;
	unsigned int	len;
	t_op_center		oc;

	oc.ops = NULL;
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
	if (gen_stacks(stacks, nums, order, &oc))
		begin_sort(stacks, &oc);
	free(order);
	ft_free_arr((void **)nums);
}
