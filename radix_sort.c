/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/09/02 16:37:26 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stacks[], unsigned int bits, unsigned int len)
{
	unsigned int	i;

	if (is_sorted(stacks, TOP_A, len))
		return ;
	i = -1;
	print_stack(stacks[STACK_A]);
	print_stack(stacks[STACK_B]);
	while (++i < len)
	{
		if (((peek_pos(stacks, TOP_A) >> bits) & 1) == 1)
			do_rot(stacks[STACK_A]);
		else
			do_push(stacks[STACK_A], stacks[STACK_B]);
	}
	print_stack(stacks[STACK_A]);
	print_stack(stacks[STACK_B]);
	i = -1;
	while (stacks[STACK_B]->len)
		do_push(stacks[STACK_B], stacks[STACK_A]);
	return (radix_sort(stacks, bits + 1, len));
}
