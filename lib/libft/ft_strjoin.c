/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:22:38 by esaci             #+#    #+#             */
/*   Updated: 2019/11/09 21:25:20 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counts1;
	int		counts2;
	char	*ptr;

	counts1 = 1;
	counts2 = 1;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		counts1 = ft_strlen(s1);
	if (s2)
		counts2 = ft_strlen(s2);
	if (s1 && !s2)
		ptr = ft_substr(s1, 0, counts1);
	if (s2 && !s1)
		ptr = ft_substr(s2, 0, counts2);
	if (!s1 || !s2)
		return (ptr);
	ptr = malloc(sizeof(char) * (counts1 + counts2 + 1));
	if (!(ptr))
		return (NULL);
	ft_strlcpy(ptr, s1, counts1 + counts2 + 1);
	ft_strlcat(ptr, s2, counts2 + counts1 + 1);
	return (ptr);
}
