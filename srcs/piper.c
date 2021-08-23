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
	char	*ptr;
	int		count;

	count = 0;
	while (arg_list[count])
		count++;
	ptr = NULL;
	while (get_next_line(fd, &ptr) > 0)
	{
		arg_list[count - 1] = ptr;
		return (0);
	}
	return (-1);
}

int	ft_piper(t_pip *pip, int fdindex)
{
	int		count;

	if (fdindex == 0)
	{
		close(pip->pfd1[0]);
		dup2(pip->fd[0], STDIN_FILENO);
		dup2(pip->pfd1[1], STDOUT_FILENO);
		count = 0;
		while (count < 4)
			close(pip->pfd1[count++]);
		close(pip->fd[0]);
	}
	if (fdindex == 3)
	{
		close(pip->pfd1[1]);
		dup2(pip->pfd1[0], STDIN_FILENO);
		dup2(pip->fd[1], STDOUT_FILENO);
		count = 0;
		while (count < 4)
			close(pip->pfd1[count++]);
		close(pip->fd[1]);
	}
	return (0);
}

void	calcul_in_out(int index, int *in, int *out)
{
	*in = (index % 3) * 2;
	if (index == 2)
		*out = 1;
	else
		*out = 3 - ((index % 3) * 2);
}

int	bonus_piper2(t_pip *pip, int index)
{
	int	b_in;
	int	b_out;
	int	count;

	calcul_in_out(index, &b_in, &b_out);
	dup2(pip->pfd1[b_in], STDIN_FILENO);
	dup2(pip->pfd1[b_out], STDOUT_FILENO);
	count = 0;
	while (count < 6)
		close(pip->pfd1[count++]);
	return (0);
}
// (0,3) (2, 5) (4, 1) (0, 3) (2, 5) ..
int	bonus_piper(t_pip *pip, int index)
{
	int	count;

	if (index == 1)
	{
		dup2(pip->fd[0], STDIN_FILENO);
		dup2(pip->pfd1[5], STDOUT_FILENO);
		count = 0;
		while (count < 6)
			close(pip->pfd1[count++]);
		close(pip->fd[0]);
	}
	else if (index == (pip->b_ac - 3))
	{
		dup2(pip->pfd1[((index % 3) * 2)], STDIN_FILENO);
		dup2(pip->fd[1], STDOUT_FILENO);
		count = 0;
		while (count < 6)
			close(pip->pfd1[count++]);
		close(pip->fd[1]);
	}
	else
		return (bonus_piper2(pip, index));
	return (0);
}
