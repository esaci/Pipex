/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:26:00 by esaci             #+#    #+#             */
/*   Updated: 2020/02/08 00:20:40 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_flag(char countu[BUFFER_SIZE + 2])
{
	if (countu[BUFFER_SIZE + 1] != 'E')
	{
		countu[0] = 0;
		countu[BUFFER_SIZE + 1] = 'E';
	}
	else
		return (1);
	return (0);
}

int	get_next_line2(int ct, int count2, char *countu)
{
	if (ct == -1 || count2 == - 'E')
		countu[BUFFER_SIZE + 1] = 0;
	if (ct == -1)
		return (-1);
	return (count2 != - 'E');
}
