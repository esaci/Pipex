/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:13:26 by esaci             #+#    #+#             */
/*   Updated: 2019/11/25 21:36:23 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	counts;
	char			*ptr;

	counts = (unsigned int)ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (NULL);
	if (counts < start)
	{
		ptr[0] = '\0';
		return (ptr);
	}
	counts = 0;
	while (s[counts + start] != '\0' && counts < (unsigned int)len)
	{
		ptr[counts] = s[counts + start];
		counts++;
	}
	ptr[counts] = '\0';
	return (ptr);
}
