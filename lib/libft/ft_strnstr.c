/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:42:27 by esaci             #+#    #+#             */
/*   Updated: 2019/11/25 21:52:58 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count1;
	size_t	count2;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	count1 = 0;
	while (count1 < len && haystack[count1] != '\0')
	{
		count2 = 0;
		while (needle[count2] == haystack[count1 + count2]
			&& (count1 + count2) < len && needle[count2] != 0)
			count2++;
		if (count2 >= ft_strlen(needle))
			return ((char *)(haystack + count1));
		count1++;
	}
	return (NULL);
}
