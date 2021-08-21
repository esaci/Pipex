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

void	init_pip2(t_pip *pip)
{
	pip->fd[0] = open(pip->ptr[0], O_RDONLY);
	pip->fd[1] = open(pip->ptr[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pip->fd[1] == -1)
		exit(1);
	if (pipe(pip->pfd1) == -1)
		exit(1);
	if (pipe(pip->pfd1 + 2) == -1)
		exit(1);
}

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
	init_pip2(pip);
}

void	envp_init(char **envp, t_pip *pip)
{
	int	count;

	count = 0;
	while (envp[count])
	{
		if (!ft_memcmp(envp[count], "PATH", 4))
			pip->pathptr = ft_split(envp[count] + 5, ':');
		if (!ft_memcmp(envp[count], "PWD", 3))
			pip->pwd = ft_split(envp[count] + 4, 1);
		count++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pip	pip;
	int		count;
	int		count2;
	int		status;
	char	**arg_list;

	if (argc < 5)
		return (1);
	init_pip(&pip, argv);
	envp_init(envp, &pip);
	count2 = ft_reader(&pip, 1, 0, envp);
	count = 0;
	while (count < 4)
		close(pip.pfd1[count++]);
	arg_list = arg_listeur(&pip, 1);
	waitpid(pip.pid[0], &status, 0);
	if (WIFEXITED(status))
	{
		pip.tmp[0] = WEXITSTATUS(status);
		if (access(arg_list[0], F_OK) == -1)
			ft_stop(&pip, "FNOTOK1", arg_list);
		else if (access(arg_list[0], X_OK) == -1)
			ft_stop(&pip, "XNOTOK1", arg_list);
		else if (pip.tmp[0] != 0)
			ft_stop(&pip, "execve1", arg_list);
	}
	arg_list = arg_listeur(&pip, 2);
	waitpid(pip.pid[1], &status, 0);
	if (WIFEXITED(status))
	{
		pip.tmp[0] = WEXITSTATUS(status);
		if (access(arg_list[0], F_OK) == -1)
			ft_stop(&pip, "FNOTOK2", arg_list);
		else if (access(arg_list[0], X_OK) == -1)
			ft_stop(&pip, "XNOTOK2", arg_list);
		if (pip.tmp[0] == 127)
			ft_stop(&pip, "execve2", arg_list);
	}
	double_free(pip.pathptr);
	double_free(pip.pwd);
	return (pip.tmp[0]);
}
