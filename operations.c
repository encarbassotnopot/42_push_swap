/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:29:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/24 16:04:32 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = del_node(from);
	if (!node)
		return ;
	append_op(&to->op_center->ops, PUSH, to->name);
	push_node(node, to);
}

void	do_rot(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	append_op(&stack->op_center->ops, ROT, stack->name);
	stack->contents = stack->contents->next;
}

void	do_rrot(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	append_op(&stack->op_center->ops, RROT, stack->name);
	stack->contents = stack->contents->prev;
}

void	do_swap(t_stack *stack)
{
	t_node	*last;
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->len < 2)
		return ;
	append_op(&stack->op_center->ops, SWAP, stack->name);
	last = stack->contents->prev;
	first = stack->contents;
	second = stack->contents->next;
	third = stack->contents->next->next;
	if (stack->len > 2)
	{
		last->next = second;
		second->prev = last;
		second->next = first;
		first->prev = second;
		if (stack->len == 3)
		{
			first->next = last;
			last->prev = first;
		}
		else
		{
			first->next = third;
			third->prev = first;
		}
	}
	stack->contents = second;
}
