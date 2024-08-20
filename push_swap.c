/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/20 15:56:25 by ecoma-ba         ###   ########.fr       */
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

void quick_sort(t_stack orig, t_stack other, int pos, unsigned int start, unsigned int len)
{

}


int	main(int argc, char **argv)
{
	t_node			*node;
	t_stack			*a;
	t_stack			*b;
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
	a = create_stack('a');
	b = create_stack('b');
	i = -1;
	while (nums[++i])
	{
		node = create_node(*nums[i], order[i]);
		if (node)
			append_node(node, a);
	}
	free(order);
	ft_free_arr((void **)nums);
	print_stack(a);
	print_stack(b);
	/*do_push(a, b);*/
	/*do_push(a, b);*/
	/*do_push(a, b);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	/*do_rot(a);*/
	/*do_rot(a);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	/*do_rrot(a);*/
	/*do_rrot(a);*/
	/*do_rrot(a);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	/*do_swap(a);*/
	/*do_swap(b);*/
	/*print_stack(a);*/
	/*print_stack(b);*/
	free_stack(&a);
	free_stack(&b);
}
