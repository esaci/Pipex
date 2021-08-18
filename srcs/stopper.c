/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stopper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:40:14 by esaci             #+#    #+#             */
/*   Updated: 2021/07/14 14:40:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libpip.h"

void	koi(char *str)
{
	printf("|%s|\n", str);
}

void	ft_stop(t_pip *pip, char *str)
{
	int	count;

	count = 0;
	while (pip->ptr[count])
	{
		count++;
	}
	printf("%s est le msg d'erreur\n", str);
	exit(1);
}

void	double_free(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
}