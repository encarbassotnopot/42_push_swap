/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:29:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/10 13:04:20 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}

void	add_node(t_node **list, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
	{
		free_list(list);
		return ;
	}
	if (!*list)
	{
		*list = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*list)->prev->next = new_node;
		new_node->prev = (*list)->prev;
		(*list)->prev = new_node;
		new_node->next = *list;
	}
}

void	free_list(t_node **list)
{
	t_node	*iter;
	t_node	*next;

	iter = *list;
	while (iter->next != *list)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
	free(iter);
	*list = NULL;
}
