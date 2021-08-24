#include "../lib/libpip.h"

int     bonus_here_doc(t_pip *pip, char *envp[])
{
    char    *ptr;
    char    **str;
    int     count;
    pip->fd[0] = open("./srcs/here_doc_file", O_RDWR | O_CREAT | O_TRUNC, 0777);
    while(get_next_line(0, &ptr) > 0)
    {
        if (!ft_memcmp(ptr, pip->b_ptr[1], ft_strlen(pip->b_ptr[1])) && ft_strlen(pip->b_ptr[1]) == ft_strlen(ptr))
            exit(0);
        write(pip->fd[0], ptr, ft_strlen(ptr));
        write(pip->fd[0], "\n", 1);
        free(ptr);
    }
    close(pip->pfd1[3]);
    dup2(pip->fd[0], pip->pfd1[3]);
    pip->pfd1[2] = fork();
    if (!pip->pfd1[2])
    {
        str = malloc(sizeof(char *) * 3);
        if (!str)
            bonus_ult_free(pip, NULL, 1);
        str[0] = copieur("/bin/cat");
        str[1] = NULL;
        dup2(pip->pfd1[3], STDOUT_FILENO);
        count = 0;
		while (count < (pip->b_ac - 3) * 2)
			close(pip->b_pfd1[count++]);
        if (execve(str[0], str, envp) == -1)
            bonus_ult_free(pip, str, 1);
        close(pip->fd[0]);
    }
    return (3);
}

void    bonus_here_close(t_pip *pip, char *envp[])
{
    char    **str;

    pip->b_pid[1] = fork();
	if (!pip->b_pid[1])
    {
        str = malloc(sizeof(char *) * 3);
        if (!str)
            bonus_ult_free(pip, NULL, 1);
        str[0] = copieur("/bin/rm");
        str[1] =copieur("./srcs/here_doc_file");
        if (execve(str[0], str, envp) == -1)
            bonus_ult_free(pip, str, 1);
    }
}