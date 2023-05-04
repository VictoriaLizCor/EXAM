#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	*ar;
	int	size;
	int	i;

	i = 0;
	size = abs(end - start) + 1;
	ar = (int *)malloc(sizeof(int)*size);
	while (i < size)
	{
		if (end < start)
			ar[i] = start - i;
		else
			ar[i] = start + i;
		i++;
	}
	return (ar);
}

int	main(void)
{
	int	*ar;
	int	size;
	int	i;
	int	start;
	int	end;

	start = -3;
	end = 3;
	i = 0;
	size = abs(end - start) + 1;
	ar = ft_range(start, end);
	while (i < size)
	{
		printf("%d | ", ar[i]);
		i++;
	}
	printf("\n");
	return (0);
}
