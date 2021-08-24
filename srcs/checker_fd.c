/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:55:20 by esaci             #+#    #+#             */
/*   Updated: 2021/08/24 23:55:22 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	checker_fd(t_pip *pip)
{
	int		count;
	char	*ptr;

	count = access(pip->ptr[0], R_OK);
	if (count == -1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->ptr[0]);
		print_error(ptr);
		free(ptr);
	}
	count = access(pip->ptr[3], W_OK);
	if (pip->fd[1] == -1 || count == -1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->ptr[3]);
		print_error(ptr);
		free(ptr);
		ult_free(pip, 0, 1);
	}
}

void	bonus_checker_fd(t_pip *pip)
{
	int		count;
	char	*ptr;

	if (!ft_memcmp(pip->b_ptr[0], "here_doc", 8)
		&& ft_strlen(pip->b_ptr[0]) == 8)
		return ;
	count = access(pip->b_ptr[0], R_OK);
	if (count == -1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->b_ptr[0]);
		print_error(ptr);
		free(ptr);
	}
	count = access(pip->b_ptr[pip->b_ac - 2], W_OK);
	if (pip->fd[1] == -1 || count == -1)
	{
		ptr = merge_twoarray("permission non accordée: ",
				pip->b_ptr[pip->b_ac - 2]);
		print_error(ptr);
		free(ptr);
		bonus_ult_free(pip, 0, 1);
	}
}
