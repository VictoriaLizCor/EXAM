#include <unistd.h>

int main(int vc, char **v)
{
	char *cpy1;
	char *cpy2;
	int i = 0;
	int j = 0;

	if (vc == 3)
	{
		if (!*v[1] && !*v[2])
			write(1, "1", 1);
		else
		{
			cpy1 = v[1];
			cpy2 = v[2];
			while (cpy1[i])
			{
				while (cpy2[j])
				{
					if (cpy1[i] == cpy2[j] && cpy1[i])
						i++;
					j++;
				}
				if (!cpy2[j])
					break;
			}
			if (!cpy1[i] && !cpy2[j])
				write(1, "1", 1);
			else
				write(1, "0", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}