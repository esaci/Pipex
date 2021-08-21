/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:37:56 by esaci             #+#    #+#             */
/*   Updated: 2021/08/21 17:37:57 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

char	**bonus_arg_listeur(t_pip *pip, int index)
{
	char	**ptr;
	int		count;

	count = 0;
	while (pip->b_ptr[index][count])
	{
		if (pip->b_ptr[index][count] == ' ')
			break ;
		count++;
	}
	if (pip->b_ptr[index][count])
		ptr = ft_split(pip->b_ptr[index], ' ');
	else
	{
		ptr = malloc(sizeof(char *) * 2);
		ptr[0] = copieur(pip->b_ptr[index]);
		ptr[1] = NULL;
	}
	ptr = ft_split2(ptr, pip, index);
	ptr[0] = parse_path(ptr, pip);
	return (ptr);
}

void	bonus_reader(t_pip *pip, int index, char *envp[])
{
	char	**arg_list;

	arg_list = bonus_arg_listeur(pip, index);
	if (1 == 2)
		envp = 0;
	if (!fork())
	{
		pip->tmp[1] = open("/dev/null", O_WRONLY);
		dup2(pip->tmp[1], 2);
		close(pip->tmp[1]);
		if (arg_list[0][0] != '/')
			ult_free(pip, arg_list, 127);
		bonus_piper(pip, fdindex);
		if (access(pip->ptr[0], R_OK) == -1)
			bonus_ult_free(pip, arg_list, 1);
		if (execve(arg_list[0], arg_list, envp) == -1)
			bonus_ult_free(pip, arg_list, 1);
	}
	double_free(arg_list);
}
