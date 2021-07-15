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
	printf("La phrase:\n%s|\n", str);
}

char	**arg_listeur(t_pip *pip, int index, int fdindex)
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



int	ft_reader(t_pip *pip)
{
	int		fd[2];
	char	**arg_list;
	char	*ptr;


	fd[0] = open(pip->ptr[0], O_RDONLY);
	fd[1] = open(pip->ptr[3], O_RDWR);
	arg_list = arg_listeur(pip, 1, 0);
	if (pipe(fd) == -1)
	{
		printf("pipe a echoue \n");
		ft_stop(pip, "fork");
	}
	ptr = ft_strjoin("/bin/", arg_list[0]);
	arg_list[0] = ft_strjoin("/bin/", arg_list[0]);
	int count = 0;
	while(arg_list[count])
	{
		printf("arg_list[%d] vaut %s\n", count, arg_list[count]);
		count++;
	}
/* 	if (ft_strncmp("/bin/cat", ptr, ft_strlen(ptr)))
		printf("ptr vaut %s\nptr vaut %s\n et %zu vs %zu\n", ptr, "/bin/ls", ft_strlen(ptr), ft_strlen("/bin/ls")); */
	printf("------------------------\n");
	execv(ptr, arg_list);
	return (0);
}
