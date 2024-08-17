#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(int argc,char *argv[])
 {

    
    pid_t child = fork();
    if(child==0)
    {
       char* array[]= {argv[1],NULL};
      
      execv("./fib",array);
      exit(0); 
    }
     
    return 0;
}
