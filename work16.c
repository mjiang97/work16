#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    printf("Begin Forking: \n");
    int f = fork();
    if (f) {
        f = fork();
    }
    if (!f) {
        printf("Child PID: %d\n", getpid());
        srand(time(NULL));
        int t = (rand() % 4) + 2;
        sleep(t);
        printf("End of child process %d\n", getpid());
        return t;
    }
    else {
        int status, t;
        t = wait(&status);
        printf("Child PID %d was asleep for %d seconds\n", t, WEXITSTATUS(status));
        printf("Parent program complete\n");
    }
    return 0;
}