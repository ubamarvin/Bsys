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
        printf("Hello\n");

    } else { //parent rc=PiD child
        sleep(1);
        printf("Tschau\n");
    }
    return 0;
}