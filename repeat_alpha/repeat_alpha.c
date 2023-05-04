#include <unistd.h>

static int	is_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (c - 'A' + 1);
	else if ((c >= 'a' && c <= 'z'))
		return (c - 'a' + 1);
	return (0);
}

void	repeat_alpha(char *str)
{
	int	char_val;
	int	cnt;

	while (*str)
	{
		cnt = 0;
		char_val = is_alpha(*str);
		if (!char_val)
			write(1, str, 1);
		else
		{
			while (cnt < char_val)
			{
				write(1, str, 1);
				cnt++;
			}
		}
		str++;
	}
	write(1, "\n", 1);
}

int	main(int arg, char *argv[1])
{
	if (arg >= 3 || argv[1] == NULL || *argv[1] == '\0')
		write(1, "\n", 1);
	else
		repeat_alpha(argv[1]);
	return (0);
}
