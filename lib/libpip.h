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
# include <errno.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
typedef struct s_pip
{
	char	*ptr[4];
	int		errnum;
	pid_t	pid[2];
	int		fd[2];
	int		tmp[2];
	char	**pathptr;
	char	**pwd;
	int		pfd1[2];
	int		pfd2[2];
}	t_pip;

extern int errno ;
int			ft_reader(t_pip *pip, int index, int fdindex, char **envp);
char		**ft_split2(char **s, t_pip *pip, int index);
void		ft_stop(t_pip *pip, char *str);
pid_t		forker(t_pip *pip);
void		full_free(char **str);
pid_t		ft_executeur(t_pip *pip);
int			ft_piper(t_pip *pip, int fdindex);
int			file_reader(int fd, char **arg_list);
void																					koi(char *str);
#endif
