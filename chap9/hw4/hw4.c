#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXLINE 1024
#define MAXARG 64

int main() {
    char command[MAXLINE];
    char *args[MAXARG];
    char *token;
    int status;
    pid_t pid;

    while (1) {
        printf("Pls input cmd : ");
        fgets(command, MAXLINE, stdin);
        command[strlen(command)-1] = '\0';
        token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAXARG) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        pid = fork();
        
        if (pid < 0) {
            printf("Fork failed\n");
            exit(1);
        }
        else if (pid == 0) {
            printf("[%d] Parent process start\n", getpid());
            execvp(args[0], args);
            printf("Parent process end\n");
            exit(1);
        }
        else {
            wait(&status);
            printf("SUCCESS\n");
        }
    }

    return 0;
}






