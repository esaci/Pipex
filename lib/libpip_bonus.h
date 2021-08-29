/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpip_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 14:11:49 by esaci             #+#    #+#             */
/*   Updated: 2021/08/29 14:12:06 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIP_BONUS_H
# define LIBPIP_BONUS_H

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
# include <sys/errno.h>
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
	int		pfd1[6];
	char	*tmptr;
	char	**b_ptr;
	int		b_ac;
	int		*b_pid;
	int		*b_pfd1;
}	t_pip;

int			ft_reader(t_pip *pip, int index, int fdindex, char **envp);
char		**ft_split2(char **s, t_pip *pip, int index);
int			ft_stop(t_pip *pip, char *str, char **arg_list, int mode);
pid_t		forker(t_pip *pip);
pid_t		ft_executeur(t_pip *pip);
int			ft_piper(t_pip *pip, int fdindex);
int			file_reader(int fd, char **arg_list);
char		*merge_twoarray(char *s, char *d);
void		koi(char *str);
void		double_free(char **str);
char		*copieur(char *s);
int			len_double(char **str);
void		ult_free(t_pip *pip, char **arg_list, int e);
void		print_error(char	*ptr);
char		**arg_listeur(t_pip *pip, int index);
char		*parse_path(char **arg_list, t_pip *pip);
void		checker_fd(t_pip *pip);
int			bonus_main(int argc, char *argv[], char *envp[], t_pip *pip);
int			bonus_reader(t_pip *pip, int index, char *envp[]);
void		bonus_ult_free(t_pip *pip, char **arg_list, int e);
int			bonus_piper(t_pip *pip, int index);
char		**bonus_arg_listeur(t_pip *pip, int index);
void		bonus_closer(t_pip *pip, int index);
int			bonus_stop(t_pip *pip, char *str, char **arg_list, int index);
int			bonus_here_doc(t_pip *pip, char *envp[]);
void		bonus_here_close(t_pip *pip, char *envp[]);
void		bonus_checker_fd(t_pip *pip);
#endif
