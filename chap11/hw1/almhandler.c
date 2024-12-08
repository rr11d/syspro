#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}
int my_signal(int signum, void (*handler)(int)) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(signum, &sa, NULL) == -1) {
        return -1;
    }
    return 0;
}
int main() {
    my_signal(SIGALRM, alarmHandler);
    alarm(5);
    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }
    printf("end\n");
    return 0;
}
