/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:48:50 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 13:29:29 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H

# define MINI_PAINT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_info
{
	int height;
	int width;
	char bc;
	char **map;
	char c1;
	char c2;
	float radius;
	float x;
	float y;
}	t_info;

//utils
int print_error(char *msg, FILE *fd, t_info  *info);
void	free_all(t_info *info);
int	ft_strlen(char *str);
//make circle
int		save_circle(t_info *info, FILE *fd);
void	draw_map(t_info *info);

#endif
