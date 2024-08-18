/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:29:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/18 17:32:39 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Appends a node at the end of the stack.
 */
void	append_node(t_node *node, t_stack *stack)
{
	if (stack->len == 0)
	{
		node->next = node;
		node->prev = node;
		stack->contents = node;
	}
	else
	{
		node->next = stack->contents;
		node->next->prev = node;
		node->prev = stack->contents->prev;
		node->prev->next = node;
	}
	stack->len++;
}

/**
 * Pushes a node to the top of the stack.
 */
void	push_node(t_node *node, t_stack *stack)
{
	if (stack->len == 0)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->contents;
		node->next->prev = node;
		node->prev = stack->contents->prev;
		node->prev->next = node;
	}
	stack->contents = node;
	stack->len++;
}

/**
 * Deletes the top node of the stack.
 * Returns a pointer to the deleted node.
 */
t_node	*del_node(t_stack *stack)
{
	t_node	*del;

	if (stack->len == 0)
		return (NULL);
	else if (stack->len == 1)
	{
		del = stack->contents;
		stack->contents == NULL;
	}
	else
	{
		del = stack->contents;
		del->next->prev = del->prev;
		del->prev->next = del->prev;
		stack->contents = del->next;
	}
	stack->len--;
}
