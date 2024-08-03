#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int	div = 128;

	printf("%d\n", (int)octet);
	while (div > 0)
	{
		if (octet >= div)
		{
			write(1, "1", 1);
			octet = octet - div;
		}
		else
			write(1, "0", 1);
		printf("| %d | %d\n", div, octet);
		div = div / 2;
	}
}

int	main (void)
{
	print_bits();
}
