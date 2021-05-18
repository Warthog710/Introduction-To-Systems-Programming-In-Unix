#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    int status;

    /*Task 1 - Call execl to execute pwd*/
    printf("Running command \"pwd\" with execl().\n\n");
    pid = fork();

    if (pid == 0)
    {
        /*I am child*/
        execl("/bin/pwd", "pwd", NULL );
    }
    else
    {
        /*I am parent*/
        wait(&status);
        printf("\nTask 1 complete.\n");
    }

    /*Task 2 - Call execv to execute ls -l -a*/
    printf("\nRunning command \"ls -l -a\" with execv().\n\n");
    pid = fork();

    if (pid == 0)
    {
        char* args[] = { "ls", "-l", "-a", NULL};
        /*I am child*/
        execv("/bin/ls", args);
    }
    else
    {
        /*I am parent*/
        wait(&status);
        printf("\nTask 2 complete.\n");
    }

    /*Task 3 - Call execlp to execute ps -e -l -f*/
    printf("\nRunning command \"ps -e -l -f\" with execlp().\n\n");
    pid = fork();

    if (pid == 0)
    {
        /*I am child*/
        execlp("ps", "ps", "-e", "-l", "-f", NULL);
    }
    else
    {
        /*I am parent*/
        wait(&status);
        printf("\nTask 3 complete.\n");
    }

    /*Task 4 - Call execve to execute cal 4 1980*/
    printf("\nRunning command \"cal 4 1980\" with execve().\n\n");
    pid = fork();

    if (pid == 0)
    {
        /*I am child*/
        char* myArgs[] = {"cal", "4", "1980", NULL};
        char* myEnv[] = {"HOME=/usr/bin", NULL};
        execve("/usr/bin/cal", myArgs, myEnv);
    }
    else
    {
        /*I am parent*/
        wait(&status);
        printf("Task 4 complete.\n");
    }    
}