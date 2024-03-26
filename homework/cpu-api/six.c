#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/wait.h>

int main () {


    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) { //child gets zero
        
        printf("Hello, i am %d\n", getpid());

    } else { //parent rc=PiD child
        int status;
        int rc_wait = waitpid(-1, &status, 0);
        printf("Waited for %d\n status is %d\n", rc_wait, status);
        printf("Tschau\n");
    }
    return 0;
}