/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:54:42 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:00:10 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H

# define MICRO_PAINT_H
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>

typedef struct	s_info
{
	int height;
	int width;
	char bc;
	char **map;
	char r;
	char c;
	float r_height;
	float r_width;
	float x;
	float y;
}	t_info;

//utils
int print_error(char *msg, FILE *fd, t_info  *info);
void	free_all(t_info *info);
//make rectangle
int		save_rectangle(t_info *info, FILE *fd);
void	draw_filled(t_info *info);
void	draw_empty(t_info *info);

#endif
