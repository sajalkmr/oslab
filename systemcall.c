#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait()
#include <unistd.h>     // fork

int main(int argc, char **argv) {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        // Child process
        printf("It is the child process and pid is %d\n", getpid());
        int i;
        for (i = 0; i < 8; i++) {
            printf("%d\n", i);
        }
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("It is the parent process and pid is %d\n", getpid());
        int status;
        wait(&status);
        printf("Child is reaped\n");
    } else {
        // Error in forking
        printf("Error in forking..\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
