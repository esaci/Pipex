/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:54:42 by esaci             #+#    #+#             */
/*   Updated: 2019/11/25 21:49:13 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		count;
	char		*dep;
	const char	*sorc;

	count = 0;
	dep = dst;
	sorc = src;
	while (count < len)
	{
		dep[count] = sorc[count];
		count++;
	}
	return (dst);
}
