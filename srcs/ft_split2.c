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

#include "../lib/libpip.h"

char	*copieur(char *s)
{
	int		count;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	count = 0;
	while (s[count])
	{
		str[count] = s[count];
		count++;
	}
	str[count] = 0;
	return (str);
}

int	len_double(char **str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*merge_twoarray(char *s, char *d)
{
	int		count;
	int		count2;
	char	*ptr;

	if (!s && !d)
		return (NULL);
	count = ft_strlen(s) + ft_strlen(d);
	ptr = malloc(sizeof(char) * (count + 1));
	count = 0;
	count2 = 0;
	while (s[count])
	{
		ptr[count] = s[count];
		count++;
	}
	while (d[count2])
	{
		ptr[count + count2] = d[count2];
		count2++;
	}
	ptr[count + count2] = 0;
	return (ptr);
}

char	**ft_split3(char **d, char **s)
{
	int	count2;

	d[0][0] = '/';
	count2 = 1;
	while (s[count2])
	{
		d[count2] = copieur(s[count2]);
		free(s[count2]);
		count2++;
	}
	free(s[0]);
	free(s);
	d[count2] = NULL;
	return (d);
}

char	**ft_split2(char **s, t_pip *pip, int index)
{
	int		count;
	char	**d;

	index = 0;
	count = len_double(s);
	d = malloc(sizeof(char *) * (count + 2));
	if (!d)
		ft_stop(pip, "okok", NULL, 0);
	d[index] = malloc(sizeof(char) * (ft_strlen(s[0]) + 2));
	if (!d[0])
		ft_stop(pip, "okok", NULL, 0);
	count = 0;
	while (s[0][count])
	{
		d[0][count + 1] = s[0][count];
		count++;
	}
	d[0][++count] = 0;
	return (ft_split3(d, s));
}
