#include "../lib/libpip.h"

void    checker_fd(t_pip *pip)
{
    int     count;
    char    *ptr;

    count = access(pip->ptr[0], R_OK);
    if (count == - 1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->ptr[0]);
		print_error(ptr);
		free(ptr);
	}
    count = access(pip->ptr[3], W_OK);
    if (pip->fd[1] == -1 || count == - 1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->ptr[3]);
		print_error(ptr);
		free(ptr);
		ult_free(pip, 0, 1);
	}
}

void    bonus_checker_fd(t_pip *pip)
{
    int     count;
    char    *ptr;

    count = access(pip->b_ptr[0], R_OK);
    if (count == - 1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->b_ptr[0]);
		print_error(ptr);
		free(ptr);
	}
    count = access(pip->b_ptr[pip->b_ac - 2], W_OK);
    if (pip->fd[1] == -1 || count == - 1)
	{
		ptr = merge_twoarray("permission non accordée: ", pip->b_ptr[pip->b_ac - 2]);
		print_error(ptr);
		free(ptr);
		bonus_ult_free(pip, 0, 1);
	}
}