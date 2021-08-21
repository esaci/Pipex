/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stopper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:40:14 by esaci             #+#    #+#             */
/*   Updated: 2021/07/14 14:40:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	koi(char *str)
{
	printf("|%s|\n", str);
}

void	ft_stop(t_pip *pip, char *str)
{
	char	*ptr;

	if (!ft_memcmp(str, "XNOTOK1", 7))
	{
		ptr = merge_twoarray("Permission denied: ", pip->ptr[0]);
		perror(ptr);
		free(ptr);
	}
	if (!ft_memcmp(str, "XNOTOK2", 7))
	{
		ptr = merge_twoarray("command not found: ", pip->ptr[2]);
		perror(ptr);
		free(ptr);
	}
	if (!ft_memcmp(str, "execve", 6) && pip->pid[1] < 0)
	{
		ptr = strerror(errno);
		perror(pip->ptr[0]);
		exit(0);
	}
	else if (!ft_memcmp(str, "execve", 6))
	{
		ptr = strerror(errno);
		perror(pip->ptr[3]);
		exit(0);
	}
	exit(0);
}

void	double_free(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
}

void	ult_free(t_pip *pip, char **arg_list, int e)
{
	double_free(pip->pathptr);
	double_free(pip->pwd);
	double_free(arg_list);
	exit(e);
}
