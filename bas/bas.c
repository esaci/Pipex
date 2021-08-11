#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[],char *envp[]) {
	pid_t           pid;
	int           status;

	if (argc > 1)
	{
		if ((pid = fork()) == -1)
		{
			perror("fork");
			return 1;
		}
	/* Si pid == 0, alors on est dans le process fils. */
		else if (pid == 0)
        {
			if (execve(argv[1], argv + 1, envp) == -1)
				perror("execve");
			return 1; /* On termine le fils même si execve fail parce qu'on veut voir que le pid du pere*/
        }
      /* Sinon, dans le pere. */
      else
        waitpid(pid); /* Oui, il faudrait vérifier la valeur de retour... */
    }
  	printf("My pid is: %d\n", getpid());
    return 0;
}
