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

char	*parse_path(char **arg_list, t_pip *pip)
{
	int		count;
	int		tmp;
	char	*ptr;

	count = 0;
	tmp = 1;
	while (pip->pathptr[count] && tmp != 0)
	{
		ptr = ft_strjoin(pip->pathptr[count], arg_list[0]);
		tmp = access(ptr ,X_OK);
		if (tmp != 0)
			free(ptr);
		count++;
	}
	if (tmp == 0)
		return (ptr);
	return(arg_list[0]);
}

int	ft_reader(t_pip *pip, int index, int fdindex, char **envp)
{
	char	**arg_list;
	int		tmp;


	ft_piper(pip, fdindex);
	if (index == 1)
		pip->pid[0] = ft_executeur(pip);
	else
		pip->pid[1] = ft_executeur(pip);
	if (index == 1)
		return (ft_reader(pip, 2, 3, envp));
	printf("les combinaison sont pip[0]:%d pip[1]:%d index:%d\n", pip->pid[0],pip->pid[1], index);
	arg_list = arg_listeur(pip, index);
	if (pip->pid[0] != 0)
	{
		arg_list[0] = parse_path(arg_list, pip);
		printf("------------------------\n");
		int count = 0;
		while(arg_list[count])
			koi(arg_list[count++]);
		printf("------------------------\n");
		tmp = execve(arg_list[0], arg_list, envp);
		if (tmp < 0)
		{
			arg_list[0] = strerror(errno);
			perror(arg_list[0]);
			return (-1);
		}
	}
	return (0);
}
