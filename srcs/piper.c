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


int		ft_piper(t_pip *pip, int fdindex)
{
	int tmp;

	tmp = '?';
	tmp = file_reader(tmp, fdindex, pip->fd[0]);
	if (pipe(pip->fd) == -1)
	{
		printf("pipe a echoue \n");
		ft_stop(pip, "fork");
	}
	return (0);
}
