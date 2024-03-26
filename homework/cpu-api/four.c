#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/wait.h>

int main () {

    const char* hi = "hello"; //hello program
    const char* c = "Child";
    const char* p = "Parent";
    char* const argv[] = {(char*)c,NULL};

    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");

    } else if (rc == 0) { 
        printf("Child process\n");
        //inherit env variable
        //execl(hi,c,NULL);
        //execv(hi,argv);
        //inherits env var, searches for exe in directories listed in Path
        //int ex = execlp(hi,c);
        //if (ex < 0) {
        //    fprintf(stderr, "exe failed\n");
        //}
        //
        //execvp(hi,argv);
        //int ex = execlp(hi,c);
        //if (ex < 0) {
        //    fprintf(stderr, "exe failed\n");
        //}

        //passing in environment variable
        execle(hi,c,__environ);
        //execvpe(hi,c,__environ);
    } else {
        printf("Parent process\n");
        execl(hi,p,NULL);

    }
return 0;
}   