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

void	print_error(char	*ptr)
{
	write(2, ptr, ft_strlen(ptr));
	write(2, "\n", 1);
}

int	ft_stop(t_pip *pip, char *str, char **arg_list, int mode)
{
	char	*ptr;

	if (!ft_memcmp(str, "FNOTOK", 6))
	{
		ptr = merge_twoarray("command not found: ", arg_list[0]);
		print_error(ptr);
		free(ptr);
	}
	if (!ft_memcmp(str, "XNOTOK", 6))
	{
		ptr = merge_twoarray("permission denied: ", arg_list[0]);
		print_error(ptr);
		free(ptr);
	}
	if (!ft_memcmp(str, "execve", 6))
	{
		ptr = strerror(errno);
		perror(pip->ptr[(mode - 1)*3]);
	}
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
	double_free(arg_list);
	exit(e);
}
