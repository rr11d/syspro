#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("failed");
        exit(1);
    }
    if (pid == 0) {
        printf("Send: [%d] Hello from PID = %d\n", getpid(), getppid());
    } else {
        printf("Recv: [%d] Hello from PID = %d\n", getpid(), pid);
    }
    return 0;
}

