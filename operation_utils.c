/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:34:54 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/26 10:34:28 by ecoma-ba         ###   ########.fr       */
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
 * Deletes the given operation and the following one from the list
 * and frees them.
 */
void	del_op(t_operation **head, t_operation *op)
{
	if (!head || !op)
		return ;
	if (op == op->next || op == op->next->next)
	{
		if (op != op->next)
			free(op->next);
		free(op);
		*head = NULL;
		return ;
	}
	if (op == *head)
		*head = op->next->next;
	op->prev->next = op->next->next;
	op->next->next->prev = op->prev;
	free(op->next);
	free(op);
}

int	optimizable(t_operation *op)
{
	if (op->stack == op->next->stack)
	{
		if ((op->type == ROT && op->next->type == RROT) || (op->type == RROT
				&& op->next->type == ROT))
			return (1);
		else if ((op->type == SWAP && op->next->type == SWAP))
			return (1);
	}
	else if ((op->type == PUSH && op->next->type == PUSH))
		return (1);
	return (0);
}

/**
 * Optimizes operations removing duplicates.
 */
void	optimize_operations(t_operation **list)
{
	t_operation	*iter;
	t_operation	*next;

	iter = *list;
	while (iter && iter->next != *list)
	{
		next = iter->next;
		if (optimizable(iter))
		{
			if (iter == *list)
			{
				del_op(list, iter);
				next = *list;
			}
			else
			{
				next = iter->prev;
				del_op(list, iter);
				next = next->next;
			}
		}
		iter = next;
	}
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
	if (!iter)
		return ;
	if (iter->type == PUSH)
		ft_printf("p%c\n", iter->stack);
	else if (iter->type == SWAP)
		ft_printf("s%c\n", iter->stack);
	else if (iter->type == ROT)
		ft_printf("r%c\n", iter->stack);
	else if (iter->type == RROT)
		ft_printf("rr%c\n", iter->stack);
}
