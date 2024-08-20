/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:29:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/20 13:13:58 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, unsigned int pos)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->final_pos = pos;
	return (node);
}

void	free_list(t_node **list)
{
	t_node	*iter;
	t_node	*next;

	iter = *list;
	while (iter && iter->next != *list)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
	free(iter);
	list = NULL;
}

/**
 * Appends a node at the end of the stack.
 */
void	append_node(t_node *node, t_stack *stack)
{
	if (!node)
		return ;
	if (stack->len == 0)
	{
		node->next = node;
		node->prev = node;
		stack->contents = node;
	}
	else
	{
		node->next = stack->contents;
		node->prev = stack->contents->prev;
		node->next->prev = node;
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
		node->prev = stack->contents->prev;
		node->next->prev = node;
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
		stack->contents = NULL;
	}
	else
	{
		del = stack->contents;
		del->next->prev = del->prev;
		del->prev->next = del->next;
		stack->contents = del->next;
	}
	del->next = NULL;
	del->prev = NULL;
	stack->len--;
	return (del);
}
