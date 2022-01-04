/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:54:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:01:38 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"micro_paint.h"

void leaks(void)
{
	system("leaks  -q a.out\n");
}

int	main(int argc, char **argv)
{
	FILE	*fd;
	t_info	info;

	atexit(leaks);
	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if (fscanf(fd, "%d %d %c\n", &info.width, &info.height, &info.bc) < 3)
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if ((info.width <= 0 || info.width > 300) || (info.height <= 0 || info.height > 300))
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if (save_rectangle(&info, fd) == 1)
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if (info.map[0][0] == 'r')
			draw_empty(&info);
		else if (info.map[0][0] == 'R')
			draw_filled(&info);
		free_all(&info);
	}
	return (0);
}
