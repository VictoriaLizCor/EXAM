#include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

int main(int vc, char **v)
{
	char *cpy;
	int i = 0;

	if (vc == 2 && *v[1])
	{
		cpy = v[1];
		while (cpy[i])
		{
			if (cpy[i] >= 'A' && cpy[i] <= 'Z')
				cpy[i] = (cpy[i] - 'A') + 'a';
			if (cpy[i] == '_')
			{
				i++;
				if (cpy[i] >= 'a' && cpy[i] <= 'z')
					cpy[i] = (cpy[i] - 'a') + 'A';
			}
			write(1, &cpy[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
