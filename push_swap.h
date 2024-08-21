/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:41:23 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/21 10:37:06 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TOP_A 0
# define BOT_A 1
# define TOP_B 2
# define BOT_B 3
# define STACK(i) i / 2
# define OTHER(i) STACK(i) + 1 % 2
# define S_MIN(i) ( (STACK(i) * 2 ) + 3 ) % 4
# define S_MID(i) ( (STACK(i) * 2 ) + 2 ) % 4
# define S_MAX(i) ( i  - (STACK(i) * 2 ) + 1 ) % 2 + STACK(i) * 2
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

struct				node
{
	int				value;
	unsigned int	final_pos;
	struct node		*prev;
	struct node		*next;
} typedef t_node;
struct				stack
{
	int				len;
	char			name;
	t_node			*contents;
} typedef t_stack;
t_node				*create_node(int value, unsigned int pos);
void				free_list(t_node **list);
void				append_node(t_node *node, t_stack *stack);
void				push_node(t_node *node, t_stack *stack);
t_node				*del_node(t_stack *stack);
t_stack				*create_stack(char name);
void				print_stack(t_stack *stack);
void				free_stack(t_stack **stack);
void				do_push(t_stack *from, t_stack *to);
void				do_rot(t_stack *stack);
void				do_rrot(t_stack *stack);
void				do_swap(t_stack *stack);
unsigned int		create_numarr(int argc, char **argv, int ***numarr);
#endif
