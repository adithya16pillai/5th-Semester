#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid=fork();
    if(pid<0) {
        perror("Fork failure");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("pid in child=%d and parent=%d\n", getpid(), getppid());
    } else {
        printf("pid in parent=%d and child id=%d\n", getpid(), pid);
    }
    return 0;
}