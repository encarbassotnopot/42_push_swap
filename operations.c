/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:29:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/18 18:12:05 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = del_node(from);
	if (!node)
		return ;
	printf("p%c\n", to->name);
	push_node(node, to);
}

void	do_rot(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	printf("r%c\n", stack->name);
	stack->contents = stack->contents->next;
}

void	do_rrot(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	printf("rr%c\n", stack->name);
	stack->contents = stack->contents->prev;
}
