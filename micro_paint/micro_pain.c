
#include <unistd.h>
#include <stdio.h>

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
	float rweght;
	float rhight;
	char pixel; 
	int i;
	int j;

	if (argc!=2)
	{
		ft_putstr("Error: argument\n");
		return (0);
	}
	else if (!(file = fopen(argv[1], "r")))
		ft_putstr("Error: Operation file corrupted\n");
	else
	{
		fscanf(file, "%d %d %c\n%c %f %f %f %f %c", &weght, &hight, &c, &r, &x, &y, &rweght, &rhight, &pixel);
	i = 0;
	while (i < hight)
	{
		j = 0;
		while (j < weght)
		{
			if (j >= x - 1 && j <= x + rweght && i >= y - 1 && i <= y + rweght)
				ft_putchar(pixel);
			else
				ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	}
	return (0);
}
