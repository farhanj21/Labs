#include <stdio.h>

int main()
{
	FILE *inFile = fopen("InputFile.txt", "r");
	FILE *outFile = fopen("Part3.txt", "w"); 
	
	while(1)
	{
		char buff[200];
		int temp = fscanf(inFile, "%s", buff);
		
		if (temp == EOF)
			break;
		
		int flag = 1;
		for(int i = 0; buff[i] != '\0'; i++)
		{
			if ((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))
				flag = 0;
		}
		if(flag)
		{
				fputs(buff, outFile);
				fputc(' ', outFile);
		}
		
	}	
	
	printf("Written to Part3.txt\n");
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
