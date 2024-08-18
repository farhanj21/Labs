#include <stdio.h>
#include <string.h>

void invert(int c1, int c2, char* str)
{
	if (c1 >= c2)
		return;
	else
	{
		invert(c1+1, c2-1, str);
		char temp = str[c1];
		str[c1] = str[c2];
		str[c2] = temp;
	}
	
}


int main()
{
	FILE *inFile = fopen("InputFile.txt", "r");
	FILE *outFile = fopen("Part4.txt", "w"); 
	
	while(1)
	{
		char buff[200];
		int temp = fscanf(inFile, "%s", buff);
		
		if (temp == EOF)
			break;
			
		int flag = 0;
		for(int i = 0; buff[i] != '\0'; i++)
		{
			if ((buff[i] == 'a') || (buff[i] == 'e') ||
			 (buff[i] == 'i') || (buff[i] == 'o') || (buff[i] == 'u') || 
			 (buff[i] == 'A') || (buff[i] == 'E') ||
			 (buff[i] == 'I') || (buff[i] == 'O') || (buff[i] == 'U'))
				flag = 1;
		}
		
		if (flag)
		{
			int stringSize = strlen(buff) - 1;
			invert(0, stringSize, buff);
		}
		fputs(buff, outFile);
		fputc(' ', outFile);
	}
	
	printf("Written to Part4.txt\n");
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}



