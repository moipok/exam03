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
	float rad;
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
		arr = malloc(sizeof(char*) * (weght + 1));
		i = 0;
		while (i < hight)
		{	
			arr[i] = malloc(sizeof(char) * (hight + 1));
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

		while (fscanf(file, "%c %f %f %f %c", &r, &x, &y, &rad, &pixel) > 0)
		{
			if (r == 'C')
			{
				i = 0;
				while (i < hight - 1)
				{
					j = 0;
					while (j < weght - 1)
					{
						if (rad >= sqrt((x - j) * (x - j) + (y - i) * (y - i)))
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
						if (rad - 1 >= sqrt((x - j) * (x - j) + (y - i) * (y - i)))
							;
						else if (rad >= sqrt((x - j) * (x - j) + (y - i) * (y - i)))
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