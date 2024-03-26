#include <stdio.h>  

int main (int argc, char *argv[]) {
    if (argc < 1) {
        printf("Usage: <string>\n");
        return 1;
    }
    
    char* origin = argv[0];

    printf("i was %s's process \n", origin);
    return 0;
}