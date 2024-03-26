//Author Marvin Uba

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    
    int fd = open("txt.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) { //child gets zero
        printf("child\n");
        const char *data = "Message from child!\n";
    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    printf("child data written.\n");

    } else { //parent rc=PiD child    
        printf("parent\n");

        const char *data = "Message from parent!\n";
    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    printf("parent data written.\n");
    }

    return 0;
}