/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:34:54 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/24 16:21:51 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates and appends an operation at the end of the list.
 */
void	append_op(t_operation **head, int type, char stack)
{
	t_operation	*operation;

	if (!head)
		return ;
	operation = ft_calloc(1, sizeof(t_operation));
	if (!operation)
		return ;
	operation->type = type;
	operation->stack = stack;
	if (!*head)
	{
		operation->next = operation;
		operation->prev = operation;
		*head = operation;
	}
	else
	{
		operation->next = *head;
		operation->prev = (*head)->prev;
		operation->next->prev = operation;
		operation->prev->next = operation;
	}
}

/**
 * Deletes an operation from the list and frees it.
 */
void	del_op(t_operation **head, t_operation *op)
{
	if (!head || !op)
		return ;
	if (op == op->next)
	{
		free(op);
		*head = NULL;
		return ;
	}
	if (op == *head)
		*head = op->next;
	op->prev->next = op->next;
	op->next->prev = op->prev;
	free(op);
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
	list = NULL;
}

/**
 * Prints all operations.
 */
void	print_operations(t_operation *list)
{
	t_operation	*iter;

	iter = list;
	while (iter && iter->next != list)
	{
		if (iter->type == PUSH)
			ft_printf("p%c\n", iter->stack);
		else if (iter->type == SWAP)
			ft_printf("s%c\n", iter->stack);
		else if (iter->type == ROT)
			ft_printf("r%c\n", iter->stack);
		else if (iter->type == RROT)
			ft_printf("rr%c\n", iter->stack);
		iter = iter->next;
	}
	if (iter->type == PUSH)
		ft_printf("p%c\n", iter->stack);
	else if (iter->type == SWAP)
		ft_printf("s%c\n", iter->stack);
	else if (iter->type == ROT)
		ft_printf("r%c\n", iter->stack);
	else if (iter->type == RROT)
		ft_printf("rr%c\n", iter->stack);
}
