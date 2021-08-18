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
	{
		printf("pipe a echoue \n");
		ft_stop(pip, "fork");
	}
	if (pipe(pip->pfd1 + 2) == -1)
	{
		printf("pipe a echoue \n");
		ft_stop(pip, "fork");
	}
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

	if (argc < 5)
		return (1);
	envp_init(envp, &pip);
	init_pip(&pip, argv);
	count2 = ft_reader(&pip, 1, 0, envp);
	count = 0;
	while (count < 4)
		close(pip.pfd1[count++]);
	waitpid(pip.pid[0], &status, 0);
	waitpid(pip.pid[1], &status, 0);
	double_free(pip.pathptr);
	double_free(pip.pwd);
	if (WIFEXITED(status))
	{
		count = WEXITSTATUS(status);
		if (count != 0)
			return (count);
	}
	return (status);
}
