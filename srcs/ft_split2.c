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
	free(s);
	return(str);
}

void	full_free(char **str)
{
	int count;

	count = 0;
	while(str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
}

char	**ft_split2(char **s, t_pip *pip, int fdindex)
{
	int		count;
	char	**d;
	int		count2;

	count = 0;
	while(s[count])
		count++;
	d = malloc(sizeof(char*) * (count + 2));
	if (!d)
		ft_stop(pip, "okok");
	count2 = 0;
	while(count2 < count)
	{
		d[count2] = s[count2];
		count2++;
	}
	d[count2] = pip->ptr[fdindex];
	count2++;
	d[count2] = NULL;
	s = d;
	return (s);
}
