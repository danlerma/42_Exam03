/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:48:57 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 11:05:26 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mini_paint.h"

void	free_all(t_info *info)
{
	int i = 0;
	if (info->map != NULL)
	{
		while (info->map[i] != NULL)
		{
			free(info->map[i]);
			i++;
		}
		free(info->map);
	}
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int print_error(char *msg, FILE *fd, t_info *info)
{
	if (info != NULL)
		free_all(info);
    fclose(fd);
	write(1, msg, ft_strlen(msg));
	return (1);
}
