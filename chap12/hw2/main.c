#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

#define MAXLINE 100

void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int pipefd[2];
    pid_t pid1, pid2;
    char buffer[MAXLINE];    
    pipe(pipefd);
    pid1 = fork();
    if (pid1 == 0) {
        close(pipefd[0]);
        printf("input string: ");
        memset(buffer, 0, sizeof(buffer));
        fflush(stdin);
        
        if (fgets(buffer, MAXLINE, stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            write(pipefd[1], buffer, strlen(buffer) + 1);
        }
        close(pipefd[1]);
        exit(0);
    }
    
    pid2 = fork();
    if (pid2 == 0) {
        close(pipefd[1]);
        read(pipefd[0], buffer, MAXLINE);
        close(pipefd[0]);
        to_uppercase(buffer);
        printf("%s\n", buffer);
        exit(0);
    }
    
    close(pipefd[0]);
    close(pipefd[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
    return 0;
}
