#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

bool checkPerfect(int N) {
    int factorsSum = 1;
    for (int i = 2; i <= N / 2; ++i) {
        if (N % i == 0) {
            factorsSum = factorsSum + i;
        }
    }
    return factorsSum == N;
}

void childProcess(int start, int end, int N, int pipe_fd[2]) {
    close(pipe_fd[0]);
    int sumFactors = 0;
    for (int num = start; num <= end; ++num) {
        if (N % num == 0) {
            sumFactors = sumFactors + num;
        }
    }
    write(pipe_fd[1], &sumFactors, sizeof(sumFactors));
    close(pipe_fd[1]);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <N>\n";
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 1) {
        cerr << "N should be greater than 1\n";
        return 1;
    }

    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid1 = fork();

    if (pid1 == 0)
    {
        close(pipe1[0]);
        childProcess(1, N / 4, N, pipe1);
        return 0;
    }
    else
    {
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
            close(pipe2[0]);
            childProcess(N / 4 + 1, N / 2, N, pipe2);
            return 0;
        }
        else
        {
            close(pipe1[1]);
            close(pipe2[1]);

            int sum1, sum2;
            read(pipe1[0], &sum1, sizeof(sum1));
            read(pipe2[0], &sum2, sizeof(sum2));

            int sumFactors = sum1 + sum2;

            if (checkPerfect(N))
            {
                cout << N << " is a perfect number\n";
            } else
            {
                cout << N << " is not a perfect number\n";
            }

            wait(NULL);
            wait(NULL);
           
           
          return 0;
        }
    }
}

