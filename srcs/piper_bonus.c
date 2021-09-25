/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:19:17 by esaci             #+#    #+#             */
/*   Updated: 2021/08/25 00:19:19 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	calcul_in_out(int index, int *in, int *out)
{
	*in = (index - 2) * 2;
	*out = *in + 3;
}

int	bonus_piper2(t_pip *pip, int index)
{
	int	b_in;
	int	b_out;
	int	count;

	calcul_in_out(index, &b_in, &b_out);
	dup2(pip->b_pfd1[b_in], STDIN_FILENO);
	dup2(pip->b_pfd1[b_out], STDOUT_FILENO);
	count = 0;
	while (count < (pip->b_ac - 3) * 2)
		close(pip->b_pfd1[count++]);
	return (0);
}

int	bonus_piper(t_pip *pip, int index)
{
	int	count;

	if (index == 1)
	{
		dup2(pip->fd[0], STDIN_FILENO);
		dup2(pip->b_pfd1[1], STDOUT_FILENO);
		count = 0;
		while (count < (pip->b_ac - 3) * 2)
			close(pip->b_pfd1[count++]);
		close(pip->fd[0]);
	}
	else if (index == (pip->b_ac - 3))
	{
		dup2(pip->b_pfd1[(index - 2) * 2], STDIN_FILENO);
		dup2(pip->fd[1], STDOUT_FILENO);
		count = 0;
		while (count < (pip->b_ac - 3) * 2)
			close(pip->b_pfd1[count++]);
		close(pip->fd[1]);
	}
	else
		return (bonus_piper2(pip, index));
	return (0);
}
