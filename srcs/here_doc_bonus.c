#include "../lib/libpip.h"

int     bonus_here_doc(t_pip *pip, char *envp[])
{
    char    *ptr;
    char    **str;
/*     int     status;
 */
    pip->fd[0] = open("./srcs/here_doc_file", O_RDWR | O_CREAT | O_TRUNC, 0777);
    while(get_next_line(0, &ptr) > 0)
    {
        if (!ft_memcmp(ptr, pip->b_ptr[1], ft_strlen(pip->b_ptr[1])) && ft_strlen(pip->b_ptr[1]) == ft_strlen(ptr))
            break;
        write(pip->fd[0], ptr, ft_strlen(ptr));
        write(pip->fd[0], "\n", 1);
        free(ptr);
    }
    if (ptr)
        free(ptr);
    pip->b_pid[2] = fork();
    if (!pip->b_pid[2])
    {
        pip->tmp[0] =open("./srcs/here_doc_file", O_RDWR);
        str = malloc(sizeof(char *) * 2);
        if (!str)
            bonus_ult_free(pip, NULL, 1);
        str[0] = copieur("/bin/cat");
        str[1] = NULL;
        dup2(pip->tmp[0], STDIN_FILENO);
        dup2(pip->b_pfd1[3], STDOUT_FILENO);
        close(pip->b_pfd1[3]);
        if (execve(str[0], str, envp) == -1)
            bonus_ult_free(pip, str, 1);
    }
/*     waitpid(pip->b_pid[2], &status, 0); */
    return (3);
}

void    bonus_here_close(t_pip *pip, char *envp[])
{
    char    **str;

    unlink("./srcs/here_doc_file");
    return;
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