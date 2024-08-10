/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:41:23 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/10 12:54:39 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
struct			node
{
	int			value;
	int			final_index;
	struct node	*prev;
	struct node	*next;
} typedef t_node;
t_node	*new_node(int value);
void	add_node(t_node **list, int value);
void	free_list(t_node **list);
#endif
