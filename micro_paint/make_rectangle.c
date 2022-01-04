/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:27:07 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:00:19 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"micro_paint.h"

void draw_empty(t_info *info)
{
	
}

void	draw_filled(t_info *info)
{

}

int	save_rectangle(t_info *info, FILE *fd)
{
	int	i = 0, y = 0;

	info->map = malloc((info->height + 1) * sizeof(char *));
	if (info->map == NULL)
		return(1);
	info->map[info->height] = NULL;
	while (i < info->height)
	{
		info->map[i] = malloc((info->width + 1) * sizeof(char));
		if (info->map[i] == NULL)
			return (1);
		info->map[i][info->width] = '\0';
		y = 0;
		while (y < info->width)
		{
			info->map[i][y] = info->bc;
			y++;
		}
		i++;
	}
	while(fscanf(fd, "%c %f %f %f %f %c\n", &info->r, &info->x, &info->y, &info->r_height, &info->r_width, &info->c) == 6)
	{
		if (info->r_height <= 0 || info->r_width <= 0 || (info->r != 'r' && info->r != 'R'))
			return (1);
	}
	return (0);
}
