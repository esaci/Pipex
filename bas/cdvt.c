#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int	fd[2];

	if (pipe(fd) == -1)
		printf("Error pipe -1");
	int	id = fork();
	return 0;
}
