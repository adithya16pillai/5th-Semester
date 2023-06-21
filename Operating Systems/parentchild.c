#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid=fork();
    if(pid<0) {
        perror("fork failure");
        exit(EXIT_FAILURE);
    } else if(pid==0){
        printf("2.Child:my pidis %d,parent pid is %d\n",getpid(),getppid());
        // sleep(10); OR wait(NULL); 
        // printf("2.Child:my pidis %d,parent pid is %d\n",getpid(),getppid());
    } else {
        printf("1.Parent: my pid is %d,parent pid is %d,my child pid is %d\n", getpid(),getppid(),pid);
    }
    return 0;
}