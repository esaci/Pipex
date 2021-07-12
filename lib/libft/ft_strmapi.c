/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:27:37 by esaci             #+#    #+#             */
/*   Updated: 2019/11/24 22:48:12 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	count;

	dst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(dst))
		return (NULL);
	count = 0;
	while (count < ft_strlen(s))
	{
		dst[count] = (*f)(count, s[count]);
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
