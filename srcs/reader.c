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


	if (index == 1)
		pip->pid[0] = ft_executeur(pip);//fork
	else
		pip->pid[1] = ft_executeur(pip);//fork
	if (pip->pid[0] == 0 && pip->pid[1] == 'e')
		koi("premier proco fonctionne");
	if (pip->pid[0] == 'e' && pip->pid[1] == 0)
		koi("deuxieme proco fonctionne")
	if (index == 1 && pip->pid[1] && pip->pid[0])//si on est dans le parent, premiere iteration
		return (ft_reader(pip, 2, 3, envp));
	if ((!pip->pid[0] && !pip->pid[1]) || (pip->pid[0] != 0  && pip->pid[1] != 0))//fini le parent, la fille de la premiere fille
		return (-1);
	printf("Proc1:%d Proc2:%d\n", pip->pid[0], pip->pid[1]);
	arg_list = arg_listeur(pip, index);//split pour les options et ajoute une place de chaine de caractere a la fin pour mettre linterieur du fichier
	/* if (pip->pid[0] != 0 || pip->pid[1] != 0) *///je vire le parent, mais de base il est vire....
	arg_list[0] = parse_path(arg_list, pip);//jutilise le path qui correspond a la commande
	ft_piper(pip, fdindex, arg_list);//JE PIPE :
	if (!pip->pid[0] && pip->pid[0])
	{
		printf("On applique :\n < %s ", pip->ptr[fdindex]);
		int count = 0;
		while(arg_list[count + 1])
			printf("%s ", arg_list[count++]);
		printf("\n");
	}
	tmp = execve(arg_list[0], arg_list, envp);
	if (tmp < 0)
	{
		arg_list[0] = strerror(errno);
		perror(arg_list[0]);
		return (-1);
	}
	return (0);
}
