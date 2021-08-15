/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:52:05 by esaci             #+#    #+#             */
/*   Updated: 2021/08/04 15:52:06 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

int	file_reader(int fd, char **arg_list)
{
	int		res;
	char	*ptr;
	int		count;

	count = 0;
	while (arg_list[count])
		count++;
	ptr = NULL;
	while((res = get_next_line(fd, &ptr)) > 0)
	{
		arg_list[count - 1] = ptr;
		return (0);
	}
	return (-1);
}

int		ft_piper(t_pip *pip, int fdindex)
{
	int tmp;
	int	tmp1;

	if (fdindex == 0)
	{
		close(pip->pfd1[0]);
		tmp = dup2(pip->fd[0], STDIN_FILENO);
		tmp1= dup2(pip->pfd1[1], STDOUT_FILENO);
	}
/* 	tmp = (fdindex == 0 ? pip->fd[0] : 0);
	tmp1 = (fdindex == 0 ? 0 : pip->fd[1]);
	fd[1] = pip->fd[1]; */
/* 	dup2(tmp1, tmp); */
	if (fdindex == 3)
	{
		tmp = dup2(pip->fd[1], STDOUT_FILENO);
		tmp1 = dup2(pip->pfd2[0], STDIN_FILENO);
	}
/* 	dup2(pip->fd[1], 0); */
	return (0);
}
