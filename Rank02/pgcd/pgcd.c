#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//-2147483647
int	main(int ac, char **v)
{
	int	n1;
	int	n2;
	int	tmp;
	int	i;

	if (ac == 3)
	{
		n1 = atoi(v[1]);
		n2 = atoi(v[2]);
		if ((n1 >= 0 && n1 <= INT_MAX) || (n2 >= 0 && n2 <= INT_MAX))
		{
			i = 1;
			while (i <= n1 && i <= n2)
			{
				if (n1 % i == 0 && n2 % i == 0)
					tmp = i;
				i++;
			}
			printf("%d", tmp);
		}
	}
	printf("\n");
}

// while (n2 != 0)
// {
// 	tmp = n2;
// 	printf("%d | %d\n", n1, n2);
// 	n2 = n1 % n2;
// 	n1 = tmp;
// 	printf("%d | %d | %d\n", tmp, n1, n2);
// }