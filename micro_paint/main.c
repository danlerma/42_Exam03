#include"micro_paint.h"

int	main(int argc, char **argv)
{
	FILE	*fd;

	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (0);
		}
		printf("argumentos bien\n");
	}
	return (0);
}
