#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
int main(int argc, char *argv[]){
    char **ptr;
    extern char **environ;
    char *env_ptr;

    if(strcmp(argv[1], "-e") == 0){
        if(argc > 2) {
            env_ptr = getenv(argv[2]);
            if (env_ptr != NULL) {
                printf("%s = %s\n", argv[2], env_ptr);
            }
        }
        else{
            for(ptr = environ; *ptr != 0; ptr++){
                printf("%s\n", *ptr);
            }
        }
    }
    else if(strcmp(argv[1], "-u") == 0){
        printf("My Realistic User ID : %d(%s)\n", getuid(),getpwuid(getuid())->pw_name);
        printf("My Valid User ID : %d(%s)\n",geteuid(),getpwuid(geteuid())->pw_name);
    }
    else if(strcmp(argv[1], "-g") == 0){
        printf("My Realistic Group ID : %d(%s)\n",getgid(),getgrgid(getgid())->gr_name);
        printf("My Valid Group ID : %d(%s)\n",getegid(),getgrgid(getegid())->gr_name);
    }
    else if(strcmp(argv[1], "-i") == 0){
        printf("my process number : [%d]\n", getpid());
    }
    else if(strcmp(argv[1], "-p") == 0){
        printf("my parent's process number : [%d]\n", getppid());
    }
    else{
        printf("error");
        return 1;
    }

    exit(0);
}
