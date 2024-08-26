/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:48:03 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/08/26 10:10:22 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the given int is already part of the array arr.
 * Appends the number to the array if not repeated.
 * Returns 1 if repeated or on malloc error, 0 otherwise.
 */
int	is_repeated(int num, int **arr)
{
	int	i;
	int	*ptr;

	i = -1;
	while (arr[++i])
		if (*arr[i] == num)
			return (1);
	ptr = ft_calloc(sizeof(int), 1);
	if (!ptr)
		return (1);
	*ptr = num;
	arr[i] = ptr;
	return (0);
}

/**
 * Parses the given char*, creates nodes with its values
 * and places them in the list
 * Returns 1 on error (memory error, invalid number...), 0 otherwise.
 */
int	argv_to_numarr(char *str, int **numarr)
{
	int		i;
	int		num;
	char	**splits;

	splits = ft_split(str, ' ');
	if (!splits)
		return (1);
	i = -1;
	while (splits[++i])
	{
		num = ft_atoi(splits[i]);
		if ((num == 0 && errno == ERANGE) || !ft_isnumstr(splits[i])
			|| is_repeated(num, numarr))
		{
			ft_free_arr((void **)splits);
			return (1);
		}
	}
	ft_free_arr((void **)splits);
	return (0);
}

/**
 * Creates the num array with the arguments given to the program.
 * Stores it where numarr points.
 * Returns the array's len or 0 on error.
 */
unsigned int	create_numarr(int argc, char **argv, int ***numarr)
{
	unsigned int	len;
	int				i;

	i = 0;
	len = 0;
	while (++i < argc)
		len += ft_split_count(argv[i], ' ');
	*numarr = ft_calloc(sizeof(int *), len + 1);
	if (!*numarr)
		return (0);
	i = 0;
	while (++i < argc)
		if (argv_to_numarr(argv[i], *numarr))
			return (0);
	return (len);
}
