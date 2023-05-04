#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

int	wdmatch(char *s1, char *s2)
{
	char	*t1;
	char	*t2;

	t1 = s1;
	t2 = s2;
	if (ft_strlen(s1) <= ft_strlen(s2))
	{
		while (*t1)
		{
			while (*t2)
			{
				if (*t1 == *t2)
					break ;
				t2++;
			}
			if (!*t2)
				return (0);
			t1++;
		}
		if (!*t1 && *t2)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	main(int arg, char **argv)
{
	if (arg == 3)
	{
		if (wdmatch(argv[1], argv[2]) == 1)
			write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
