/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:30:46 by esaci             #+#    #+#             */
/*   Updated: 2020/07/14 21:10:03 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calcul(char *dst, long int val)
{
	long int	val2;
	size_t		counti;

	counti = 0;
	if (val == -2147483648)
	{
		dst[counti++] = '-';
		dst[counti++] = '8';
		val = 214748364;
	}
	if (val < 0)
	{
		dst[counti++] = '-';
		val = (-1) * val;
	}
	val = val * 10;
	while ((val / 10) != 0 || counti == 0)
	{
		val = val / 10;
		val2 = val % 10;
		dst[counti++] = val2 + '0';
	}
	dst[counti] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	count;
	char	swotch;

	dst = malloc(sizeof(char) * 12);
	if (!(dst))
		return (NULL);
	dst = ft_calcul(dst, (long int)n);
	count = ft_strlen(dst) - 1;
	n = 0;
	if (dst[0] == '-')
		n++;
	while ((size_t)n < count)
	{
		swotch = dst[count];
		dst[count] = dst[n];
		dst[n] = swotch;
		n++;
		count--;
	}
	return (dst);
}
