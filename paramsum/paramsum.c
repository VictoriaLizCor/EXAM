#include <unistd.h>
// #include <stdio.h>
// ft_itoa(int n)
// {
// 	int sign;
// 	int cpy_n = n;

// 	sign = 1;
// 	cpy_n = n;
// 	if (n < 0)
// 		sign = -1;
	
// 	return 
// }
void	ft_putnbr(int n)
{
	int c;

	// printf("%d\n", n);
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	// printf("\t \t %d\n", c - '0');
	write(1, &c , 1);
}
int main (int vc, char **v)
{

	if (vc >= 2)
	{
		(void)v;
		ft_putnbr(vc - 1);
	}
	else 
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}