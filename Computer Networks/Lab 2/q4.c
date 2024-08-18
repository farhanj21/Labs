#include <stdio.h>

int main()
{
	unsigned short temp = 0x3412;
	char *var = (char*) &temp;
	
	printf("Ordering: ");
	if (*var == 0x12)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
		
		
	for(int i = 0; i <sizeof(short);i++)
	{
		printf("Byte %d: 0x%02X\n", i+1, *(var+i));
	}
	
	return 0;
}
