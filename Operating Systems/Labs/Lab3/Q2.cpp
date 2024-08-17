#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
    pid_t childID;
    int pos;


    childID = fork();
    if (childID == 0) 
    {
        execlp("mkdir", "mkdir", "demo_folder", NULL);

        exit(1);
    }
    wait(&pos);


    childID = fork();
    if (childID == 0) {
        execlp("touch", "touch", "demo_folder/file1.txt", "demo_folder/file2.txt", NULL);
       
   
        exit(1);
    }
    wait(&pos);

    childID = fork();
    if (childID == 0) {
        execlp("ls", "ls", NULL);
        exit(1);
    }
    wait(&pos);

    childID = fork();
    if (childID == 0) {
        execlp("ls", "ls", "demo_folder", NULL);
        exit(1);
    }
    wait(&pos);
   
    childID = fork();
    if (childID == 0) {
        execlp("rm", "rm","-rf" ,"demo_folder", NULL);
        exit(1);
    }
    wait(&pos);


 
    return 0;
}
