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

void	koi(char *str)
{
	printf("|%s|\n", str);
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
		ptr = ft_split(pip->ptr[index] , ' ');
	else
	{
		ptr = malloc(sizeof(char *) * 2);
		ptr[0] = pip->ptr[index];
		ptr[1] = NULL;
	}
	ptr = ft_split2(ptr, pip, "test");
	return (ptr);
}

int	file_reader(int tmp, int mode, int fd)
{
	int		res;
	char	*ptr;

	ptr = NULL;
	if (mode == 0 && tmp == 0)
	{
		while((res = get_next_line(fd, &ptr)) > 0)
		{
			free(ptr);
		}
	}
	return (0);
}

int	ft_reader(t_pip *pip, int index, int fdindex)
{
	char	**arg_list;
	char	*ptr;
	int		tmp;


	arg_list = arg_listeur(pip, index);
	ptr = ft_strjoin("/bin/", arg_list[0]);
	arg_list[0] = ft_strjoin("/bin/", arg_list[0]);
	ft_piper(pip, fdindex);
	if (index == 1)
		pip->pid[0] = ft_executeur(pip);
	else
		pip->pid[1] = ft_executeur(pip);
	if (index == 1 && pip->pid[1] == 0 && pip->pid[0] != 0)
		return (ft_reader(pip, 2, 3));
/* 	int count = 0;
	while(arg_list[count])
		koi(arg_list[count++]);
	printf("------------------------\n"); */
	if (pip->pid[0] != 0)
		tmp = execv(ptr, arg_list);
/* 	if (tmp < 0)
	{
		perror("ERROR: ");
		return (-1);
	} */
	return (0);
}
