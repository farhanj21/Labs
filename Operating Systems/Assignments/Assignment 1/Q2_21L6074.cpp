#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

char gradeCalc(int marks)
{
    if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else
        return 'F';
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << "\n";;
        return 1;
    }

    const char *inFileName = argv[1];
    int inFile = open(inFileName, O_RDONLY);

    int outFile = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

   
    char buffer[1024];
    ssize_t bytesRead;
   
    while ((bytesRead = read(inFile, buffer, sizeof(buffer))) > 0)
    {
        char *line = buffer;
     
        while (line < buffer + bytesRead)
        {

            char rollno[256];
            int marks;
            char grade;
           
            if (sscanf(line, "%s %d %c", rollno, &marks, &grade) == 3) {
   
                char updatedGrade = gradeCalc(marks);

                dprintf(outFile, "Roll Number: %s\n", rollno);
                dprintf(outFile, "Marks: %d\n", marks);
                dprintf(outFile, "Updated Grade: %c\n", updatedGrade);
                dprintf(outFile, "\n");

            }

            line = strchr(line, '\n');
            if (!line) break;
            line++;
        }
    }


    close(inFile);
    close(outFile);

    return 0;
}
