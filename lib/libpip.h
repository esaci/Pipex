/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpip.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:38:47 by esaci             #+#    #+#             */
/*   Updated: 2021/07/12 14:38:49 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBPIP_H
# define LIBPIP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
typedef struct s_pip
{
	char	*ptr[4];
}	t_pip;

int			ft_reader(t_pip *pip);
char		**ft_split2(char **s, t_pip *pip, int fdindex);
void		ft_stop(t_pip *pip, char *str);
pid_t		forker(t_pip *pip);
void		full_free(char **str);
pid_t		ft_executeur(char *ptr, char **arg_list, t_pip *pip);
void																					koi(char *str);
#endif
