#include <unistd.h>

int main (int ac, char **v)
{
	char *str;
	char c;
	int i =0;

	if (ac == 2)
	{
		str = v[1];
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (str[i] + 13 > 'Z')
					c = 'A' + ((str[i] + 13) - 'Z') - 1;
				else
					c = str[i] + 13;
				write(1, &c, 1);
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				if (str[i] + 13 > 'z')
					c = 'a' + ((str[i] + 13) - 'z') - 1;
				else
					c = str[i] + 13;
				write(1, &c, 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
