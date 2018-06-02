#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double* arr = NULL;
	int base_size = 500000;
	while (1)
	{
		arr = (double*)malloc(sizeof(double) * base_size);
		
		if (arr == NULL)
		{
			base_size /= 2;
		}
	}
	return 0;
}