/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:52:53 by esaci             #+#    #+#             */
/*   Updated: 2020/02/09 16:54:34 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

int		ft_flag(char countu[BUFFER_SIZE + 2]);
int		ft_test(int fd, char **line, char *countb, char *countu);
int		ft_testli(char *ptr);
char	*ft_joining(char *line, char *countb);
void	ft_fin(char *line, char *countu);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		get_next_line2(int ct, int count2, char *countu);
#endif
