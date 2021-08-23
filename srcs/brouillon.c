#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
char **sendout=NULL;
int send_i=0;

void sender2(char* str_) {
    int fd[2];
    int fd1[2];
    int fd2[2];
    int pid;
    char* echo[] = {"echo", str_, NULL};
    char* sed[] = {"sed", "regex1", NULL};
    char* sed2[] = {"sed", "regex2", NULL};
    int status;

    if (pipe(fd) < 0) {
        exit(100);
    }

    pid = fork();
    if (pid == 0) {
        close(fd[0]);

        dup2(fd[1], 1);

        close(fd[1]);
        execvp(echo[0], echo);
        printf("Error in execvp1\n");
    }

    if (pipe(fd1) < 0) {
        exit(100);
    }

    pid = fork();
    if (pid == 0) {
        close(fd[1]);
        close(fd1[0]);

        dup2(fd[0], 0);
        dup2(fd1[1], 1);
        dup2(fd1[1], 2);

        close(fd[0]);
        close(fd1[1]);
        execvp(sed2[0], sed2);
        printf("Error in execvp2\n");
    }

    if (pipe(fd2) < 0) {
        exit(100);
    }

    pid = fork();
    if (pid == 0) {
        close(fd1[1]);
        close(fd2[0]);

        dup2(fd1[0], 0);
        dup2(fd2[1], 1);
        dup2(fd2[1], 2);

        close(fd2[1]);
        close(fd1[0]);
        execvp(sed[0], sed);
    }

    pid = fork();
    if (pid == 0) {
        close(fd2[1]);

        char* line = NULL;
        size_t len = 0;
        ssize_t read_;
        FILE* f_pipe;
        f_pipe = fdopen(fd2[0], "r");
        printf("1\n");
        while ((read_ = getline(&line, &len, f_pipe)) != -1) {
            printf("2\n");
            sendout = realloc(sendout, sizeof(char*) * (send_i + 1));
            sendout[send_i] = strdup(line);
            send_i++;
            printf("%s\n", line);
        }

        fclose(f_pipe);

        close(fd2[0]);
        return;
    }

    close(fd[1]);
    close(fd[0]);
    close(fd1[1]);
    close(fd1[0]);
    close(fd2[1]);
    close(fd2[0]);
    if (pid != 0) {
        wait(&status);
    }
}

int main() { 
sender2("hello"); 
}