/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stopper_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:25:58 by esaci             #+#    #+#             */
/*   Updated: 2021/08/25 00:25:59 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	bonus_ult_free(t_pip *pip, char **arg_list, int e)
{
	if (access("./srcs/here_doc_file", F_OK) != -1)
		unlink("./srcs/here_doc_file");
	double_free(pip->pathptr);
	double_free(pip->pwd);
	if (arg_list)
		double_free(arg_list);
	double_free(pip->b_ptr);
	free(pip->b_pfd1);
	free(pip->b_pid);
	exit(e);
}

int	bonus_stop2(t_pip *pip, char *str, char **arg_list, int index)
{
	if (!ft_memcmp(str, "XNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("permission denied: ", arg_list[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	else if (!ft_memcmp(str, "CMDNOINPUT", 10))
	{
		str = merge_twoarray("Wrong usage of command: ", pip->b_ptr[index]);
		print_error(str);
		free(str);
	}
	else if (!ft_memcmp(str, "CMDRNOTOK", 10))
	{
		str = merge_twoarray("permission denied: ", pip->ptr[index]);
		print_error(str);
		free(str);
	}
	else if (!ft_memcmp(str, "execve", 6))
		perror(pip->b_ptr[index]);
	return (index);
}

int	bonus_stop(t_pip *pip, char *str, char **arg_list, int index)
{
	if (!ft_memcmp(str, "RNOTOK", 6))
	{
		if (access(pip->b_ptr[0], F_OK) != -1)
			return (0);
		pip->tmptr = merge_twoarray("no such file or directory: ",
				pip->b_ptr[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	else if (!ft_memcmp(str, "FNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("command not found: ", arg_list[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	else
		return (bonus_stop2(pip, str, arg_list, index));
	return (index);
}
