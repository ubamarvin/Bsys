//Author Marvin Uba

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    
    int x = 10;
    printf("main x = %d\n ", x);

    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) { //child gets zero
        x += 10;
        printf("child x = %d\n", x);

    } else { //parent rc=PiD child
        x += 10;
        printf("parent x = %d\n", x);
    }
    return 0;
}