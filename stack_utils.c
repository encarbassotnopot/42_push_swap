/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:44:59 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/18 18:52:25 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char name)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	return (stack);
}

void	print_stack(t_stack *stack)
{
	int		i;
	t_node	*iter;

	printf("stack %c, len %d, contents:\n", stack->name, stack->len);
	i = -1;
	iter = stack->contents;
	while (++i < stack->len)
	{
		printf("%d\n", iter->value);
		/*printf("value: %d, next value: %d, prev value: %d\n",*/
		/*		iter->value, iter->next->value, iter->prev->value);*/
		iter = iter->next;
	}
}

void	free_stack(t_stack **stack)
{
	free_list(&(*stack)->contents);
	free(*stack);
	*stack = NULL;
}
