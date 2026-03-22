#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    pid_t childId;
    int status;
    childId = fork();
    if (childId < 0)
    {
        fprintf(stderr, "Error: fork() failed. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (childId == 0)
    {
        printf("Child process: Creating empty file 'abc'...\n");

        int fd = open("abc", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd == -1)
        {
            fprintf(stderr, "Child process error: Failed to create file 'abc'. %s\n",
                    strerror(errno));
            exit(EXIT_FAILURE);
        }

        close(fd);

        printf("Child process: File 'abc' created successfully. Terminating...\n");

        exit(EXIT_SUCCESS);
    }

    else
    {
        printf("Parent process: Waiting for child process (childId: %d) to terminate...\n", childId);

        if (wait(&status) == -1)
        {
            fprintf(stderr, "Parent process error: wait() failed. %s\n",
                    strerror(errno));
            exit(EXIT_FAILURE);
        }

        printf("Parent process: Child process terminated.\n");
        printf("Child Process Number (childId): %d\n", childId);

        if (WIFEXITED(status))
        {
            printf("Child exited normally with status: %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child was terminated by signal: %d\n", WTERMSIG(status));
        }

        exit(EXIT_SUCCESS);
    }

    return 0;
}
