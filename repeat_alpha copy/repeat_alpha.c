#include <unistd.h>

int main(int vc, char **v)
{
	char *cpy;
	int i = 0;
	int idx;

	if (vc == 2 && *v[1])
	{
		cpy = v[1];
		while (cpy[i])
		{
			idx = 0 ;
			if (cpy[i] >= 'A' && cpy[i] <= 'Z')
				idx = cpy[i] - 'A' + 1;
			else if (cpy[i] >= 'a' && cpy[i] <= 'z')
				idx = cpy[i] - 'a' + 1;
			if (idx)
			{
				while (idx--)
					write (1, &cpy[i], 1);
			}
			else
				write (1, &cpy[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}