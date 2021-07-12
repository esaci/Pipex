/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:56:05 by esaci             #+#    #+#             */
/*   Updated: 2019/11/20 07:03:49 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countreverse(char const *s1, char const *set, int count)
{
	int	count2;
	int	count3;

	count2 = (unsigned int)ft_strlen(s1);
	count3 = 0;
	while (count2 > count && set[count3] != '\0')
	{
		count3 = 0;
		count2--;
		while (set[count3] != s1[count2] && set[count3] != '\0')
			count3++;
	}
	return (count2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	count;
	unsigned int	count2;
	unsigned int	count3;

	if (!s1)
		return (NULL);
	count = 0;
	count3 = -1;
	while (set[count3 + 1] != '\0' && s1[count] != '\0')
	{
		if (set[count3 + 1] == s1[count])
		{
			count++;
			count3 = -2;
		}
		count3++;
	}
	count2 = ft_countreverse(s1, set, count);
	return (ft_substr(s1, count, count2 - count + 1));
}
