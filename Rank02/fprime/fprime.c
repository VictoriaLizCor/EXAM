#include <stdlib.h>
#include <stdio.h>

void ft_isprime(int prime)
{
	int cpy;
	int num;

	num = prime;
	cpy = 2;
	while (cpy <= num)
	{
		if (num %cpy ==0)
		{
				num = num/cpy;
				printf("%d", cpy);
				if (num > 1)
					printf("*");
				cpy = 1;
		}
		cpy++;
	}
}

int main(int vc, char **v)
{
	char *c;
	int i = 0;
	int num = 0;

	if (vc ==2 && *v[1])
	{
		c = v[1];
		while (c[i] >= '0' && c[i] <= '9')
			i++;
		if (!c[i])
		{
			num = atoi(c);
			if (num > 1)
				ft_isprime(num);
			else
				printf("%d", num);
		}
	}
	printf("\n");
	return (0);
}

// int		main(int ac, char **av)
// {
// 	int		n;
// 	int		nb;

// 	if (ac == 2)
// 	{
// 		if (av[1][0] == '\0')
// 		{
// 			printf("\n");
// 			return (0);
// 		}
// 		nb = atoi(av[1]);
// 		if (nb == 1)
// 		{
// 			printf("1\n");
// 			return (0);
// 		}
// 		while (1)
// 		{
// 			n = 1;
// 			while (++n <= nb)
// 			{
// 				if (nb % n == 0)
// 				{
// 					printf("%d", n);
// 					nb = nb / n;
// 					break ;
// 				}
// 			}
// 			if (nb == 1)
// 				break ;
// 			else
// 				printf("*");
// 		}
// 	}
// 	printf("\n");
// 	return (0);
// }