/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:27:07 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 15:23:03 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mini_paint.h"

void	draw_map(t_info *info)
{
	int	i = 0, j = 0;

	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			write(1, &info->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static float	distance(t_info *info, int i, int j)
{
	return(sqrtf(powf(info->x - j, 2) + powf(info->y - i, 2)));
}

static void	draw_empty(t_info *info)
{
	int	i = 0, j = 0;

	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (distance(info, i , j) <= info->radius && distance(info, i , j) > info->radius - 1)
				info->map[i][j] = info->c2;
			j++;
		}
		i++;
	}
}

static void	draw_filled(t_info *info)
{
	int	i = 0, j = 0;

	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (distance(info, i , j) <= info->radius)
				info->map[i][j] = info->c2;
			j++;
		}
		i++;
	}
}

int	save_circle(t_info *info, FILE *fd)
{
	int	i = 0, y = 0, sz = 0;

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
	while((sz = fscanf(fd, "%c %f %f %f %c\n", &info->c1, &info->x, &info->y, &info->radius, &info->c2)) == 5)
	{
		if (info->radius < 0 || (info->c1 != 'c' && info->c1 != 'C'))
			return (1);
		if (info->c1 == 'c')
			draw_empty(info);
		else if (info->c1 == 'C')
			draw_filled(info);
	}
	if (sz > 0)
		return (1);
	return (0);
}
