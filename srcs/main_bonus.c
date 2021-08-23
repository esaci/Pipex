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
	pip->b_ptr = malloc(sizeof(char *) * (argc));
	if (!pip->b_ptr)
		ft_stop(pip, "malloc", NULL, 0);
	count = 0;
	while (count < (argc - 1))
	{
		pip->b_ptr[count] = copieur(argv[count + 1]);
		count++;
	}
	pip->b_ptr[count] = 0;
	pip->fd[0] = open(pip->b_ptr[0], O_RDONLY);
	pip->fd[1] = open(pip->b_ptr[argc - 2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pip->b_pid = malloc(sizeof(int) *(argc));
	if (!pip->b_pid)
		ft_stop(pip, "malloc", NULL, 0);
	count = 0;
	while (count < argc)
		pip->b_pid[count++] = -2;
	if (pipe(pip->pfd1) == -1)
		exit(1);
	if (pipe(pip->pfd1 + 2) == -1)
		exit(1);
	if (pipe(pip->pfd1 + 4) == -1)
		exit(1);
}

int	bonus_waiter_error(t_pip *pip, int index)
{
	int		status;
	char	**arg_list;

	arg_list = bonus_arg_listeur(pip, index);
	waitpid(pip->b_pid[index], &status, 0);
	if (WIFEXITED(status))
	{
		pip->tmp[0] = WEXITSTATUS(status);
		if (access(arg_list[0], F_OK) == -1)
			ft_stop(pip, "FNOTOK", arg_list, index);
		else if (access(arg_list[0], X_OK) == -1)
			ft_stop(pip, "XNOTOK", arg_list, index);
		else if (access(pip->b_ptr[0], R_OK) == -1)
			ft_stop(pip, "RNOTOK", arg_list, index);
		else if (pip->tmp[0] != 0)
			ft_stop(pip, "execve", arg_list, index);
	}
	double_free(arg_list);
	return (pip->tmp[0]);
}

int	bonus_main(int argc, char *argv[], char *envp[], t_pip *pip)
{
/* 	int		index; */

	init_pip_bonus(pip, argv, argc);
	int index = 1;
	while (index < (argc - 2))
		index += bonus_reader(pip, index, envp);
/* 	bonus_reader(pip, 1, envp); */
/* 	bonus_reader(pip, 2, envp); */
/* 	index = 1;
	while (index < (argc - 2))
	{
		bonus_waiter_error(pip, index);
		index++;
	} */
/* 	double_free(pip->b_ptr);
	double_free(pip->pathptr);
	double_free(pip->pwd); */
	return (0);
}
