 #include <stdio.h>
 #include <unistd.h>
 int main() {
    printf("Before exec\n");
    execl("/bin/ls", "ls", "-l", NULL);
    printf("This won't print if exec is successful\n");
    return 0;
 }