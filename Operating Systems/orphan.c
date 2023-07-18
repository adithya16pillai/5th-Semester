#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process. PID: %d\n", getpid());
        sleep(5);
        printf("Child process finished.\n");
    } else {
        printf("Parent process. PID: %d\n", getpid());
        printf("Parent process finished\n");
    }
    return 0;
}