#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/wait.h>

int main () {
    int pipefd[2];
    int rc, rc2;

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) { //child gets zero
        //Sender Pipe
        close(pipefd[0]); // Close the read end of the pipe

        // Redirect stdout to the write end of the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(pipefd[1]); // Close the original write end of the pipe

        printf("Hello, i am sending child %d\n", getpid());

    } else { //parent rc=PiD child
        printf("Hello, i am Parent %d, creating new child\n", getpid());

        rc2 = fork();
        if (rc2 < 0){
            fprintf(stderr, "fork failed\n");
        } else if (rc2 == 0) { //child gets zero
        //receiver pipe
            printf("Hello, i am receiving child %d\n", getpid());
             close(pipefd[1]); // Close the write end of the pipe

            // Redirect stdin to the read end of the pipe
            if (dup2(pipefd[0], STDIN_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(pipefd[0]); // Close the original read end of the pipe

            // Execute the receiver process
            printf("Hello, I am the receiver child %d\n", getpid());
            printf("Received message:\n");
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                printf("%s", buffer); // Print the message received from the pipe
            }

        } else { //parent rc=PiD child
            printf("Hello, i am Parent %d, im done multiplying\n", getpid());
        }
    }

    return 0;
}