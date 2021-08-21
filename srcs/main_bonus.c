/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:57:25 by esaci             #+#    #+#             */
/*   Updated: 2021/08/21 16:57:27 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	init_pip_bonus(t_pip *pip, char *argv[], int argc)
{
	int		count;

	pip->b_ac = argc;
	pip->b_ptr = malloc(sizeof(char *) *(argc));
	if (!pip->b_ptr)
		ft_stop(pip, "malloc", NULL, 0);
	count = 0;
	while (count < (argc - 1))
	{
		pip->b_ptr[count] = copieur(argv[count + 1]);
		count++;
	}
	pip->b_ptr[count] = 0;
	if (pipe(pip->pfd1) == -1)
		exit(1);
	if (pipe(pip->pfd1 + 2) == -1)
		exit(1);
	pip->fd[0] = open(pip->b_ptr[0], O_RDONLY);
	pip->fd[1] = open(pip->b_ptr[argc - 2], O_RDONLY);
}

int	bonus_main(int argc, char *argv[], char *envp[], t_pip *pip)
{
	int		index;

	index = 1;
	while (index < (argc - 2))
	{
		init_pip_bonus(pip, argv, argc);
		bonus_reader(pip, index, envp);
		index++;
	}
	double_free(pip->b_ptr);
	double_free(pip->pathptr);
	double_free(pip->pwd);
	if (1 == 2)
		argv = envp;
	return (0);
}
