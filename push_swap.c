/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:35:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/10 13:02:35 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**nums;
	t_node	*list;
	int		i;
	t_node	*iter;

	if (argc != 2)
	{
		ft_printf("Wrong args\n");
		exit(EXIT_FAILURE);
	}
	nums = ft_split(argv[1], ' ');
	i = -1;
	while (nums[++i])
	{
		add_node(&list, ft_atoi(nums[i]));
	}
	ft_printf("%d\n", list->value);
	iter = list->next;
	while (iter != list)
	{
		ft_printf("%d\n", iter->value);
		iter = iter->next;
	}
	iter = list->prev;
	while (iter != list)
	{
		ft_printf("%d\n", iter->value);
		iter = iter->prev;
	}
	ft_printf("%d\n", iter->value);
	ft_free_arr(nums);
	free_list(&list);
}
