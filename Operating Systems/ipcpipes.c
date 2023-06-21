#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
// We use two pipes
// First pipe to send input string from parent
int fd1[2]; // Used to store two ends of first pipe
char str[50] = "Message Passing through pipes";
char input_str[100];
pid_t p;
if (pipe(fd1) == -1) {
fprintf(stderr, "Pipe Failed");
return 1;
}
// scanf("%s", input_str);
p = fork();
if (p < 0) {
fprintf(stderr, "fork Failed");
return 1;
}
// Parent process
else if (p > 0) {
// Read a string using first pipe
char concat_str[100];
close(fd1[1]);
printf("Parent:reading from the pipe\n");
read(fd1[0], concat_str, 100);
printf("Parent:Received Data is :%s", concat_str);
close(fd1[0]);
wait(NULL);
}
// child process
else {
// Write input string and close writing end of first pipe.
close(fd1[0]);
printf("child: Writing to the pipe\n");
write(fd1[1], str, strlen(str) + 1);
printf("child:Exiting");
close(fd1[1]);
exit(0);
}
}