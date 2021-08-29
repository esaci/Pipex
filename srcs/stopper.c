/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stopper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:40:14 by esaci             #+#    #+#             */
/*   Updated: 2021/08/25 00:25:10 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

int	ft_stop2(t_pip *pip, char *str, int mode)
{
	if (!ft_memcmp(str, "CMDNOINPUT", 10))
	{
		str = merge_twoarray("Wrong usage of command: ", pip->ptr[mode]);
		print_error(str);
		free(str);
	}
	else if (!ft_memcmp(str, "CMDRNOTOK", 10))
	{
		str = merge_twoarray("permission denied: ", pip->ptr[mode]);
		print_error(str);
		free(str);
	}
	return (0);
}

int	ft_stop(t_pip *pip, char *str, char **arg_list, int mode)
{
	if (!ft_memcmp(str, "RNOTOK", 6))
	{
		if (access(pip->ptr[0], F_OK) != -1)
			return (0);
		pip->tmptr = merge_twoarray("no such file or directory: ", pip->ptr[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	else if (!ft_memcmp(str, "FNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("command not found: ", arg_list[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	else if (!ft_memcmp(str, "XNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("permission denied: ", arg_list[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	else
		return (ft_stop2(pip, str, mode));
	return (0);
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
	if (arg_list)
		double_free(arg_list);
	exit(e);
}
