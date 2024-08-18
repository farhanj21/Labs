#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void readCPUtime(long *totaltime, long *idletime) 
{
    FILE *file;
    char buffer[256];
    long user, nice, system, idle, iowait, irq, softirq, steal;

    file = fopen("/proc/stat", "r");

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    *totaltime = user + nice + system + idle + iowait + irq + softirq + steal;
    *idletime = idle + iowait;

    fclose(file);
}

int main() {
    long previousTime = 0, previousIdle = 0, totaltime, idletime;
    double utilization;
    int count = 0;

    while (count <= 10) 
    {
        readCPUtime(&totaltime, &idletime);

        long totalDifference = totaltime - previousTime;
        long idleDifference = idletime - previousIdle;
        utilization = 100.0 * (1 - (double)idleDifference / totalDifference);

        printf("Avg CPU Utilization= %.2f%%\n", utilization);

        previousTime = totaltime;
        previousIdle = idletime;
        count++;
        
        sleep(1);
        
    }

    return 0;
}
