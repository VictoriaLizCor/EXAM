// #include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int size;
	int *a;
	int i = 0;
	size = abs(end - start) + 1;
	a = (int *)malloc(sizeof(int) * size);
	while(i < size)
	{
		if (end > start)
			a[i]= end - i;
		else
			a[i]= end + i;
		i++;
	}
	return a;
}

// int main(void)
// {
	
// 	int i = 0;

	
// 	return (0);
// }
