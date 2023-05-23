#include <unistd.h>

int main(int vc, char **v)
{
	char c;

	if (vc == 2)
	{
		while (*v[1])
		{
			c = *v[1];
			if ((c >= 'A' && c <= 'Z')|| (c >= 'a' && c <= 'z'))
			{
				c += 1;
				if (c == 'z' + 1 || c == 'Z' + 1)
					c = c - 26;
			}
			write (1, &c, 1);
			v[1]++;
		}
	}
	write(1, "\n", 1);
	return  (0);
}