/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:17:49 by esaci             #+#    #+#             */
/*   Updated: 2021/07/12 13:17:50 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

char	*parse_path2(char **arg_list, t_pip *pip)
{
	char	*ptr;
	int		tmp;

	ptr = ft_strjoin(pip->pwd[0], arg_list[0]);
	tmp = access(ptr, F_OK);
	if (tmp == 0)
	{
		if (arg_list[0][1] == '.')
		{
			free(ptr);
			ptr = ft_strjoin(pip->pwd[0], arg_list[0] + 2);
		}
		free(arg_list[0]);
		return (ptr);
	}
	free(ptr);
	ptr = copieur(arg_list[0] + 1);
	free(arg_list[0]);
	return (ptr);
}

char	*parse_path(char **arg_list, t_pip *pip)
{
	int		count;
	int		tmp;
	char	*ptr;

	count = 0;
	tmp = access(arg_list[0], F_OK);
	if (tmp == 0)
		return (arg_list[0]);
	tmp = 1;
	while (pip->pathptr[count] && tmp != 0)
	{
		ptr = ft_strjoin(pip->pathptr[count], arg_list[0]);
		tmp = access(ptr, F_OK);
		if (tmp != 0)
			free(ptr);
		count++;
	}
	if (tmp == 0)
	{
		free(arg_list[0]);
		return (ptr);
	}
	return (parse_path2(arg_list, pip));
}

char	**arg_listeur(t_pip *pip, int index)
{
	char	**ptr;
	int		count;

	count = 0;
	while (pip->ptr[index][count])
	{
		if (pip->ptr[index][count] == ' ')
			break ;
		count++;
	}
	if (pip->ptr[index][count])
		ptr = ft_split(pip->ptr[index], ' ');
	else
	{
		ptr = malloc(sizeof(char *) * 2);
		ptr[0] = copieur(pip->ptr[index]);
		ptr[1] = NULL;
	}
	ptr = ft_split2(ptr, pip, index);
	ptr[0] = parse_path(ptr, pip);
	return (ptr);
}

int	ft_reader2(t_pip *pip, char **envp, int index, int fdindex)
{
	char	**arg_list;

	arg_list = arg_listeur(pip, index);
	pip->pid[1] = fork();
	if (!(pip->pid[1]))
	{
		pip->tmp[1] = open("/dev/null", O_WRONLY);
		dup2(pip->tmp[1], 2);
		close(pip->tmp[1]);
		if (arg_list[0][0] != '/')
			ult_free(pip, arg_list, 127);
		if (access(arg_list[0], X_OK) == -1)
			ult_free(pip, arg_list, 126);
		ft_piper(pip, fdindex);
		if (execve(arg_list[0], arg_list, envp) == -1)
			ult_free(pip, arg_list, 1);
	}
	double_free(arg_list);
	return (0);
}

int	ft_reader(t_pip *pip, int index, int fdindex, char **envp)
{
	char	**arg_list;

	arg_list = arg_listeur(pip, index);
	pip->pid[0] = fork();
	if (!(pip->pid[0]))
	{
		pip->tmp[1] = open("/dev/null", O_WRONLY);
		dup2(pip->tmp[1], 2);
		close(pip->tmp[1]);
		if (arg_list[0][0] != '/')
			ult_free(pip, arg_list, 127);
		ft_piper(pip, fdindex);
		if (access(pip->ptr[0], R_OK) == -1)
			ult_free(pip, arg_list, 1);
		if (execve(arg_list[0], arg_list, envp) == -1)
			ult_free(pip, arg_list, 1);
	}
	double_free(arg_list);
	return (ft_reader2(pip, envp, 2, 3));
}
