#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		main(int argc, char **argv)
{
		FILE *file;
	int	weght;
	int hight;
	char c;
	char r;
	float x;
	float y;
	float hh;
	float ww;
	char pixel; 
	int i;
	int j;
	char **arr;

	if (argc!=2)
	{
		ft_putstr("Error: argument\n");
		return (0);
	}
	else if (!(file = fopen(argv[1], "r")))
		ft_putstr("Error: Operation file corrupted\n");
	else
	{
		fscanf(file, "%d %d %c", &weght, &hight, &c);
		arr = malloc(sizeof(char*) * (hight + 1));
		i = 0;
		while (i < hight)
		{	
			arr[i] = malloc(sizeof(char) * (weght + 1));
			i++;
		}
		printf("qwe\n");
		i = 0;
		while (i < hight - 1)
		{
			j = 0;
			while (j < weght - 1)
			{
				arr[i][j] = c;
				j++;
			}
			i++;
			arr[i][j + 1] = '\0';
		}
		arr[i][0] = '\0';

		while (fscanf(file, "%c %f %f %f %f %c", &r, &x, &y, &hh, &ww, &pixel) > 0)
		{
			if (r == 'R')
			{
				i = 0;
				while (i < hight - 1)
				{
					j = 0;
					while (j < weght - 1)
					{
						if (j >= x && j <= x + hh && i >= y && i <= y + ww)
							arr[i][j] = pixel;
						else
							;
						j++;
					}
					i++;
				}
			
			}
			else
			{
				i = 0;
				while (i < hight - 1)
				{
					j = 0;
					while (j < weght - 1)
					{
						if (ww > 2 && hh > 2 && j >= x + 1 && j <= x + hh - 1 && i >= y + 1 && i <= y + ww - 1)
							;
						else if (j >= x && j <= x + hh && i >= y && i <= y + ww)
							arr[i][j] = pixel;
						else
							;
						j++;
					}
					i++;
				}
			}
		}
	}
		i = 0;
		while (arr[i])
		{
			printf("%s\n", arr[i]);
			i++;
		}
}