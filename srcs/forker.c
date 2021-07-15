/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:18:38 by esaci             #+#    #+#             */
/*   Updated: 2021/07/15 14:18:40 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

pid_t	forker(t_pip *pip)
{
	pid_t pid;


	pid = fork();
	if(pid == -1)
	{
		printf("fork a echoue \n");
		ft_stop(pip, "pid");
	}
	else if (pid == 0)
		printf("pid vaut 0, un child processus a ete cree\n");
	else
		printf("pid vaut %d et pas compris \n", pid);
	return (pid);
}

