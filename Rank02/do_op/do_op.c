#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int check_int(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (!*str)
		return (1);
	else 
		return (0);
}

int check_op(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	if (i == 1)
	{
		if (str[0] == '*' || str[0] == '/' || str[0] == '+' || str[0] == '-'|| str[0] == '%')
			return (1);
	}
	return (0);
}

int main (int vc, char **v)
{
	int v1;
	int v3;

	if (vc == 4 && *v[1] && *v[2] && *v[3] )
	{
		if (check_int(v[1]) && check_int(v[3]) && check_op(v[2]))
		{
			v1 = atoi(v[1]);
			v3 = atoi(v[3]);
			
			if (*v[2] == '*')
				printf("%d", v1 * v3);
			else if(*v[2] == '+')
				printf("%d", v1 + v3);
			else if(*v[2] == '-')
				printf("%d", v1 - v3);
			else if (!v1 || !v3)
				printf("0");
			else if (*v[2]== '/')
				printf("%d", v1 / v3);
			else 
				printf("%d", v1 % v3);
		}
	}
	printf ("\n");
	return (0);
}