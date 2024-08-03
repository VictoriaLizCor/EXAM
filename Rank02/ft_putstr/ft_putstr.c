#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*str1;

	str1 = str;
	while (*str1)
	{
		write(1, str1, 1);
		str1++;
	}
}

// int main (int c, char **v)
// {
// 	if (c == 2)
// 	{
// 		ft_putstr(v[1]);
// 		ft_putstr(v[1]);
// 		ft_putstr(v[1]);
// 	}
// 	return (0);
// }