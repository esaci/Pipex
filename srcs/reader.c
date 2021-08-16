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
	ptr = ft_split2(ptr, pip, index);
	return (ptr);
}

char	*parse_path(char **arg_list, t_pip *pip)
{
	int		count;
	int		tmp;
	char	*ptr;

	count = 0;
	tmp = access(arg_list[0], X_OK);
	if (tmp == 0)
		return (arg_list[0]);
/* 	tmp = access(arg_list[0] + 1, X_OK);
	if (tmp == 0)
		return (arg_list[0] + 1); */
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
	ptr = ft_strjoin(pip->pwd[0], arg_list[0]);
	tmp = access(ptr, X_OK);
	if (tmp == 0)
		return (ptr);
	free(ptr);
	ptr = merge_twoarray("command not found: ", arg_list[0] + 1);
	perror(ptr);
	free(ptr);
	exit(1);
}

int	ft_reader(t_pip *pip, int index, int fdindex, char **envp)
{
	char	**arg_list;
	int		tmp;

	tmp = 0;
	if (!(pip->pid[0] = fork()))
	{
		ft_piper(pip, fdindex);
		arg_list = arg_listeur(pip, index); //split pour les options et ajoute une place de chaine de caractere a la fin pour mettre linterieur du fichier
		arg_list[0] = parse_path(arg_list, pip); //jutilise le path qui correspond a la commande
		tmp = execve(arg_list[0], arg_list, envp);
		if (tmp < 0)
		{
			arg_list[0] = strerror(errno);
			perror(arg_list[0]);
			exit (tmp);
		}
	}
	else
	{
		if (!(pip->pid[1] = fork()))
		{
			index = 2;
			fdindex = 3;
			ft_piper(pip, fdindex);
			arg_list = arg_listeur(pip, index); //split pour les options et ajoute une place de chaine de caractere a la fin pour mettre linterieur du fichier
			arg_list[0] = parse_path(arg_list, pip); //jutilise le path qui correspond a la commande
			tmp = execve(arg_list[0], arg_list, envp);
			if (tmp < 0)
			{
				arg_list[0] = strerror(errno);
				perror(arg_list[0]);
				return (tmp);
			}
		}
	}
	/* printf("On a Index: %d Pour  (%d,%d)\n", index, pip->pid[0], pip->pid[1]); */
	return (tmp);
}
