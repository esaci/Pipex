/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:51:13 by esaci             #+#    #+#             */
/*   Updated: 2019/11/25 21:24:54 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word(char const *s, char c)
{
	int	countw;
	int	counti;

	countw = 0;
	counti = 0;
	while (s[counti] != '\0')
	{
		while (s[counti] == c)
			counti++;
		if (s[counti] != c && s[counti] != '\0')
			countw++;
		while (s[counti] != c && s[counti] != '\0')
			counti++;
	}
	return (countw);
}

int	ft_len(char const *s, char c, int start)
{
	int	count;

	count = 0;
	while (s[start] == c)
		start++;
	while (s[start + count] != c && s[start + count] != '\0')
		count++;
	return (count);
}

char	**ft_vide(char const *s)
{
	char	**ptr;

	ptr = malloc(sizeof(char *) * (2));
	if (!(ptr))
		return (NULL);
	ptr[0] = ft_strdup(s);
	ptr[1] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		count3;
	char	**ptr;

	count3 = 0;
	while (s[count3] == c)
		count3++;
	ptr = malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!(ptr))
		return (NULL);
	count = 0;
	while (count < ft_word(s, c))
	{
		while (s[count3] == c)
			count3++;
		if (s[count3] == '\0')
			return (ft_vide(s));
		ptr[count] = ft_substr(s, count3, ft_len(s, c, count3));
		count3 = count3 + ft_len(s, c, count3);
		count++;
	}
	ptr[count] = 0;
	return (ptr);
}
