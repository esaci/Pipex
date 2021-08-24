#include "../lib/libpip.h"

void	bonus_ult_free(t_pip *pip, char **arg_list, int e)
{
	double_free(pip->pathptr);
	double_free(pip->pwd);
	double_free(arg_list);
	double_free(pip->b_ptr);
    free(pip->b_pid);
	exit(e);
}

int	bonus_stop(t_pip *pip, char *str, char **arg_list, int index)
{
    if (!ft_memcmp(str, "RNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("no such file or directory: ", pip->b_ptr[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	if (!ft_memcmp(str, "FNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("command not found: ", arg_list[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	if (!ft_memcmp(str, "XNOTOK", 6))
	{
		pip->tmptr = merge_twoarray("permission denied: ", arg_list[0]);
		print_error(pip->tmptr);
		free(pip->tmptr);
	}
	if (!ft_memcmp(str, "execve", 6))
		perror(pip->b_ptr[index]);
    return (index);
}