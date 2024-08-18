#include <stdio.h>

int main()
{
	FILE *read = fopen("InputFile.txt", "r");
	FILE *write = fopen("Part2.txt", "w"); 
	
	while(1)
	{	
		int temp = fgetc(read);
		
		if (temp == EOF)
			break;
			
		char c = (char)temp;
		
		if (temp >= 48 && temp <= 57)
		{
			fputc(c, write);
			fputc(' ', write);
		}
	}
	
	printf("Written to Part2.txt\n");
	
	fclose(read);
	fclose(write);
	return 0;
}
