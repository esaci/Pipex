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

char	**arg_listeur(t_pip *pip, int index, int fdindex, char *ptr)
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
	ptr = ft_split2(ptr, pip, fdindex);
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
			koi(ptr);
			free(ptr);
		}
	}
	return (0);
}

int	ft_reader(t_pip *pip, int index, int fdindex)
{
	int		fd[2];
	char	**arg_list;
	char	*ptr;
	pid_t	pid;
	int		tmp;

	fd[1] = open(pip->ptr[3], O_RDWR);
	fd[0] = open(pip->ptr[0], O_RDONLY);
	tmp = access(pip->ptr[fdindex],R_OK);
	tmp = file_reader(tmp, fdindex, fd[0]);
	arg_list = arg_listeur(pip, index, fdindex);
	if (pipe(fd) == -1)
	{
		printf("pipe a echoue \n");
		ft_stop(pip, "fork");
	}
	ptr = ft_strjoin("/bin/", arg_list[0]);
	arg_list[0] = ft_strjoin("/bin/", arg_list[0]);
	if (index == 1)
		pid = ft_executeur(pip);
	if (index == 1 && pid == 0)
		return (ft_reader(pip, 2, 3));
	int count = 0;
	while(arg_list[count])
		koi(arg_list[count++]);
	printf("------------------------\n");
	tmp = execv(ptr, arg_list);
	if (tmp < 0)
	{
		perror("ERROR: ");
		return (-1);
	}
	return (0);
}
