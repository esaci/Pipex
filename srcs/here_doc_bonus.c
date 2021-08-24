/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:57:43 by esaci             #+#    #+#             */
/*   Updated: 2021/08/24 23:57:44 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

int	bonus_here_doc2(t_pip *pip, char *envp[])
{
	int		count;
	char	**str;

	pip->b_pid[2] = fork();
	if (!pip->b_pid[2])
	{
		pip->tmp[0] = open("./srcs/here_doc_file", O_RDWR);
		str = malloc(sizeof(char *) * 2);
		if (!str)
			bonus_ult_free(pip, NULL, 1);
		str[0] = copieur("/bin/cat");
		str[1] = NULL;
		dup2(pip->tmp[0], STDIN_FILENO);
		dup2(pip->b_pfd1[3], STDOUT_FILENO);
		count = 0;
		while (count < (pip->b_ac - 3) * 2)
			close(pip->b_pfd1[count++]);
		close(pip->tmp[0]);
		if (execve(str[0], str, envp) == -1)
			bonus_ult_free(pip, str, 1);
	}
	return (3);
}

int	bonus_here_doc(t_pip *pip, char *envp[])
{
	char	*ptr;

	if (pip->b_ac <= 5)
	{
		print_error("With here_doc Pipex: here_doc limiter cmd cmd1 outfile");
		bonus_ult_free(pip, NULL, 1);
	}
	pip->fd[0] = open("./srcs/here_doc_file", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (get_next_line(0, &ptr) > 0)
	{
		if (!ft_memcmp(ptr, pip->b_ptr[1], ft_strlen(pip->b_ptr[1]))
			&& ft_strlen(pip->b_ptr[1]) == ft_strlen(ptr))
			break ;
		write(pip->fd[0], ptr, ft_strlen(ptr));
		write(pip->fd[0], "\n", 1);
		free(ptr);
	}
	if (ptr)
		free(ptr);
	close(pip->fd[0]);
	return (bonus_here_doc2(pip, envp));
}

void	bonus_here_close(t_pip *pip, char *envp[])
{
	char	**str;

	unlink("./srcs/here_doc_file");
	return ;
	pip->b_pid[1] = fork();
	if (!pip->b_pid[1])
	{
		str = malloc(sizeof(char *) * 3);
		if (!str)
			bonus_ult_free(pip, NULL, 1);
		str[0] = copieur("/bin/rm");
		str[1] = copieur("./srcs/here_doc_file");
		if (execve(str[0], str, envp) == -1)
			bonus_ult_free(pip, str, 1);
	}
}
