/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:54:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 13:26:57 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mini_paint.h"

int	main(int argc, char **argv)
{
	FILE	*fd;
	t_info	info;

	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if (fscanf(fd, "%d %d %c\n", &info.width, &info.height, &info.bc) < 3)
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if ((info.width < 0 || info.width >= 300) || (info.height < 0 || info.height >= 300))
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		if (save_circle(&info, fd) == 1)
			return (print_error("Error: Operation file corrupted\n", fd, &info));
		draw_map(&info);
		free_all(&info);
		fclose(fd);
	}
	else if (argc != 2)
		return (print_error("Error: Operation file corrupted\n", fd, &info));
	
	return (0);
}
