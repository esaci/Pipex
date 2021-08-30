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
	int		count;
	char	*ptr;

	pip->fd[0] = open(pip->ptr[0], O_RDONLY);
	pip->fd[1] = open(pip->ptr[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	checker_fd(pip);
	if (pip->fd[0] == -1)
		pip->fd[0] = 0;
	if (pipe(pip->pfd1) == -1)
		ult_free(pip, NULL, 1);
	if (pipe(pip->pfd1 + 2) == -1)
		ult_free(pip, NULL, 1);
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

int	waiter_error(t_pip *pip, int index, int pid)
{
	int		status;
	char	**arg_list;

	pip->tmp[0] = 0;
	arg_list = arg_listeur(pip, index);
	waitpid(pip->pid[pid], &status, 0);
	if (WIFEXITED(status))
	{
		pip->tmp[0] = WEXITSTATUS(status);
		if (access(arg_list[0], F_OK) == -1)
			ft_stop(pip, "FNOTOK", arg_list, index);
		else if (access(arg_list[0], X_OK) == -1)
			ft_stop(pip, "XNOTOK", arg_list, index);
		else if (access(pip->ptr[0], R_OK) == -1 && index == 1)
			ft_stop(pip, "RNOTOK", arg_list, index);
		else if (pip->tmp[0] == 2)
			ft_stop(pip, "CMDNOINPUT", arg_list, index);
		else if (pip->tmp[0] != 0 && index == 1)
			ft_stop(pip, "execve", arg_list, index);
		else if (pip->tmp[0] == 127 && index == 2)
			ft_stop(pip, "execve", arg_list, index);
	}
	double_free(arg_list);
	return (pip->tmp[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pip	pip;
	int		count;
	int		count2;

	if (argc != 5 || envp[0] == NULL)
	{
		print_error("Format: Pipex(Infile, cmd1, cmd2, .., cmdn, Outfile)");
		exit (2);
	}
	envp_init(envp, &pip);
	if (argc > 5 || !ft_memcmp(argv[1], "here_doc", 8))
		return (bonus_main(argc, argv, envp, &pip));
	init_pip(&pip, argv);
	count2 = ft_reader(&pip, 1, 0, envp);
	count = 0;
	while (count < 4)
		close(pip.pfd1[count++]);
	waiter_error(&pip, 1, 0);
	waiter_error(&pip, 2, 1);
	double_free(pip.pathptr);
	double_free(pip.pwd);
	return (pip.tmp[0]);
}
