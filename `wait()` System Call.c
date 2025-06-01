 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
 int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process\n");
    } else {
        wait(NULL);
        printf("Parent waited and finished\n");
    }
    return 0;
 }