/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:41:23 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/26 10:19:43 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TOP 0
# define BOT 1
# define STACK_A 0
# define STACK_B 1
# define TOP_A 0
# define BOT_A 1
# define TOP_B 2
# define BOT_B 3
# define STACK(i) i / 2
# define LOCATION(i) i % 2
# define MY_TOP(i) STACK(i) * 2
# define MY_BOT(i) STACK(i) * 2 + 1
# define OTHER(i) (STACK(i) + 1) % 2
# define S_MIN(i) ((STACK(i) * 2) + 3) % 4
# define S_MID(i) ((STACK(i) * 2) + 2) % 4
# define S_MAX(i) (i - (STACK(i) * 2) + 1) % 2 + STACK(i) * 2
# define PUSH 0
# define SWAP 1
# define ROT 2
# define RROT 3
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

typedef struct node
{
	int					value;
	unsigned int		final_pos;
	struct node			*prev;
	struct node			*next;
}						t_node;
typedef struct operation
{
	int					type;
	char				stack;
	struct operation	*next;
	struct operation	*prev;
}						t_operation;
typedef struct op_center
{
	struct operation	*ops;
}						t_op_center;
typedef struct stack
{
	unsigned int		len;
	char				name;
	t_node				*contents;
	t_op_center			*op_center;
}						t_stack;
void					free_list(t_node **list);
void					append_node(t_stack *stack, int value,
							unsigned int pos);
void					push_node(t_node *node, t_stack *stack);
t_node					*del_node(t_stack *stack);
t_stack					*create_stack(char name, t_op_center *oc);
void					print_stack(t_stack *stack);
void					free_stack(t_stack **stack);
void					do_push(t_stack *from, t_stack *to);
void					do_rot(t_stack *stack);
void					do_rrot(t_stack *stack);
void					do_swap(t_stack *stack);
unsigned int			create_numarr(int argc, char **argv, int ***numarr);
void					sort_up(t_stack *stacks[], int pos, unsigned int start,
							unsigned int len);
void					sort_down(t_stack *stacks[], int pos,
							unsigned int start, unsigned int len);
void					quick_sort(t_stack *stacks[], int pos,
							unsigned int start, unsigned int len);
void					push_sublist(t_stack *from, t_stack *to,
							unsigned int len);
void					rot_sublist(t_stack *stack, unsigned int len);
void					rrot_sublist(t_stack *stack, unsigned int len);
void					move_sublist(t_stack *stacks[], int start, int end,
							unsigned int len);
void					base_case(t_stack *stacks[], int pos, int len);
unsigned int			peek_pos(t_stack *stacks[], int pos);
unsigned int			peek_pos_at(t_stack *stacks[], int pos,
							unsigned int index);
t_operation				*create_operation(int type, char stack);
void					append_op(t_operation **head, int type, char stack);
void					del_op(t_operation **head, t_operation *op);
void					free_operations(t_operation **list);
void					print_operations(t_operation *list);
void					optimize_operations(t_operation **list);
void					gen_order(int **nums, unsigned int *order,
							unsigned int len);
unsigned int			peek_pos(t_stack *stacks[], int pos);
unsigned int			peek_pos_at(t_stack *stacks[], int pos,
							unsigned int index);
unsigned int			is_sorted(t_stack *stacks[], int pos, unsigned int len);
void					sort_3(t_stack *stacks[]);
void					sort_5(t_stack *stacks[]);
#endif
