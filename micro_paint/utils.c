/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:54:37 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/04 19:02:15 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"micro_paint.h"

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

static int	ft_strlen(char *str)
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
