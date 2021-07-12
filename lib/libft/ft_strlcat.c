/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:56:25 by esaci             #+#    #+#             */
/*   Updated: 2019/12/02 21:56:27 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	countdst;
	size_t	count3;
	size_t	count4;

	if (dstsize == 0)
		return (ft_strlen(src));
	countdst = ft_strlen(dst);
	if (countdst > dstsize)
		countdst = dstsize;
	count3 = 0;
	count4 = countdst;
	if (countdst < dstsize)
	{
		while (count4 < dstsize - 1 && src[count3] != '\0')
			dst[count4++] = src[count3++];
		dst[count4] = '\0';
	}
	if (dstsize - 1 < countdst)
		return (dstsize + ft_strlen(src));
	return (ft_strlen(src) + countdst);
}
