/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:17:57 by esaci             #+#    #+#             */
/*   Updated: 2021/07/12 13:17:58 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	init_pip(t_pip *pip, char **argv)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		pip->ptr[count] = argv[count + 1];
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_pip	pip;
	int		count;


	if (argc < 5)
	{
		printf("\nIl manque des arguments (%d/5)\n", argc);
		return (0);
	}
	init_pip(&pip, argv);
	count = ft_reader(&pip, 1, 0);
	return (0);
}

