#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/wait.h>

int main (int argc, char *argv[]) {

    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) { //child gets zero
        int rc_wait = wait(NULL);
        // -1 wenn es keine kinder hat
        printf("Waited for %d\n", rc_wait);
        printf("Hello\n");

    } else { //parent rc=PiD child
        
        printf("Tschau\n");
    }
    return 0;
}