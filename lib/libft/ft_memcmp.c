/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:45:14 by esaci             #+#    #+#             */
/*   Updated: 2019/12/02 21:45:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;
	int		res;

	res = 0;
	count = 0;
	while (count < n)
	{
		if (!(*(unsigned char *)s1 == *(unsigned char *)s2))
		{
			res = *(unsigned char *)s1 - *(unsigned char *)s2;
			return (res);
		}
		s1++;
		s2++;
		count++;
	}
	return (0);
}
