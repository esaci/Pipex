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
	int count;

	if (fdindex == 0 && !pip->pid[0] && pip->pid[1] < 0)
	{
		tmp = dup2(pip->fd[0], STDIN_FILENO);
		tmp1= dup2(pip->pfd1[3], STDOUT_FILENO);
		count = 0;
		while (count < 4)
			close(pip->pfd1[count++]);
		close(pip->fd[0]);
	}
	if (fdindex == 3 && !pip->pid[1] && pip->pid[0] > 0)
	{
		tmp = dup2(pip->pfd1[2], STDIN_FILENO);
		tmp1 = dup2(pip->fd[1], STDOUT_FILENO);
		count = 0;
		while (count < 4)
			close(pip->pfd1[count++]);
	}
	return (0);
}
