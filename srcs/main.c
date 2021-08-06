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
	count = 0;
	while (count < 2)
	{
		pip->pid[count] = -2;
		count++;
	}
	pip->tmp[0] = access(pip->ptr[0],R_OK);
	if (pip->tmp[0] == 0)
		pip->fd[0] = open(pip->ptr[0], O_RDONLY);
	pip->tmp[1] = access(pip->ptr[3], W_OK);
	if (pip->tmp[1] == 0)
		pip->fd[1] = open(pip->ptr[3], O_RDWR);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;
	int		count;


	if (argc < 5)
	{
		printf("\nIl manque des arguments (%d/5)\n", argc);
		return (0);
	}
	count = 0;
	while (envp[count])
	{
		if (!ft_memcmp(envp[count], "PATH", 4))
			pip.pathptr = ft_split(envp[count] + 5, ':');
		count++;
	}
	init_pip(&pip, argv);
	count = ft_reader(&pip, 1, 0, envp);
	if (count == -1)
		return (0);
	return (0);
}

