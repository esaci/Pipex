/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:51:13 by esaci             #+#    #+#             */
/*   Updated: 2019/11/25 21:24:54 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	ft_split2(char **s)
{
	int		count;

	count = 0;
	while(s[count])
	{
		s[count] = ft_strjoin("-", s[count]);
		count++;
	}
	s[count] = NULL;
}
