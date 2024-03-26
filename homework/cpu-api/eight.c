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
        
        printf("Hello, i am child %d\n", getpid());

    } else { //parent rc=PiD child
        printf("Hello, i am Parent %d, cre new child\n", getpid());

        int rc2 = fork();
        if (rc2 < 0){
            fprintf(stderr, "fork failed\n");
        } else if (rc2 == 0) { //child gets zero

            printf("Hello, i am child %d\n", getpid());

        } else { //parent rc=PiD child
            printf("Hello, i am Parent %d, im done multiplying\n", getpid());
        }
    }

    return 0;
}