/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:07:56 by esaci             #+#    #+#             */
/*   Updated: 2019/11/24 00:44:40 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (*(s + count) != '\0')
	{
		if (*(s + count) == c)
			count2 = count;
		count++;
	}
	if (count2 != 0 || (char)s[count2] == c)
		return ((char *)s + count2);
	if (c == 0 && (char)s[count] == '\0')
		return ((char *)s + count);
	return (NULL);
}
