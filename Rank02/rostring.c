#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int vc, char **v)
{
	// char	c;
	char	*cpy;
	char	**out;
	int		words;
	int 	i;
	int		len;

	if (vc >= 2)
	{
		words = 0;
		cpy = v[1];
		i = 0;
		while (cpy[i])
		{
			if(cpy[i] != ' ' && (cpy[i + 1] == '\0' || cpy[i + 1] == ' '))
				words++;
			i++;
		}
		if (words > 0)
		{
			out = malloc(sizeof(char *) * words + 1);
			if (!out)
				return NULL;
			out[words + 1] = NULL;
			i = 0;
			while (cpy[i])
			{
				if (cpy[i] != ' ' && (cpy[i + 1] == '\0' || cpy[i + 1] == ' '))
				{
					
				}
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return  (0);
}
