/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 07:15:07 by esaci             #+#    #+#             */
/*   Updated: 2019/11/24 21:20:05 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		*(unsigned char *)(ptr + count) = val;
		count++;
	}
	return (ptr);
}
