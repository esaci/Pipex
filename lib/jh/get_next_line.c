/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:50:46 by esaci             #+#    #+#             */
/*   Updated: 2021/03/27 13:59:14 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_test(int fd, char **line, char *countb, char *countu)
{
	if (line == 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX || fd < 0)
		return (- 'E');
	*line = malloc(sizeof(char) * 1);
	if (!(line))
		return (- 'E');
	countb[0] = 0;
	*line[0] = 0;
	if (ft_flag(countu) == 1)
	{
		*line = ft_joining(*line, countu);
		if (!(*line))
			return (- 'E');
	}
	return (1);
}

int	ft_testli(char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count] != '\n')
	{
		if (ptr[count] == '\0')
			return (- 'E');
		count++;
	}
	return (count);
}

char	*ft_joining(char *line, char *countu)
{
	char	*dst;
	int		count1;
	int		count2;
	char	*ptr;

	ptr = line;
	dst = malloc(sizeof(char) * (ft_strlen(countu) + ft_strlen(line) + 1));
	if (!(dst))
		return (0);
	count1 = 0;
	while (line[count1] != '\0')
	{
		dst[count1] = line[count1];
		count1++;
	}
	count2 = 0;
	while (countu[count2] != '\0')
	{
		dst[count1 + count2] = countu[count2];
		count2++;
	}
	dst[count1 + count2] = '\0';
	free(ptr);
	return (dst);
}

void	ft_fin(char *line, char *countu)
{
	int	counta;
	int	countb;

	counta = 0;
	while (line[counta] != '\n' && line[counta] != 0)
		counta++;
	countb = 0;
	if (line[counta] == '\n')
	{
		line[counta] = '\0';
		counta++;
		while (line[counta + countb] != '\0')
		{
			countu[countb] = line[counta + countb];
			countb++;
		}
	}
	countu[countb] = '\0';
	return ;
}

int	get_next_line(int fd, char **line)
{
	static char		countu[FOPEN_MAX][BUFFER_SIZE + 2];
	char			countb[BUFFER_SIZE + 1];
	int				ct;
	int				count2;

	ct = 0;
	if (ft_test(fd, line, countb, countu[fd]) == - 'E')
		return (-1);
	while ((ft_testli(*line) == - 'E'))
	{
		ct = read(fd, countb, BUFFER_SIZE);
		if (ct <= 0)
			break ;
		countb[ct] = '\0';
		*line = ft_joining(*line, countb);
		if (!(*line))
			return (-1);
	}
	count2 = ft_testli(*line);
	ft_fin(*line, countu[fd]);
	return (get_next_line2(ct, count2, countu[fd]));
}
