/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scenary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:46:24 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/29 13:16:43 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	ft_check_objet(t_scenary *scenary, char *obj)
{
	int	i;

	if (++scenary->walls && obj[0] != '1')
		return (0);
	i = 0;
	while (++i && obj[i])
	{
		if (obj[i] == '1')
			scenary->walls++;
		else if (obj[i] == 'P' && ++scenary->start)
			scenary->x = i;
		else if (obj[i] == '0' || obj[i] == 'M')
			scenary->space++;
		else if (obj[i] == 'C')
			scenary->objet++;
		else if (obj[i] == 'E')
			scenary->exit++;
		else if (obj[i] == '\n')
			break ;
		else
			return (0);
	}
	if (obj[i - 1] != '1')
		return (0);
	return (i);
}

static int	ft_check_scenary(t_scenary *scenary)
{
	int	tmp_walls;
	int	right;
	int	i;

	ft_scenary(scenary);
	tmp_walls = ft_check_objet(scenary, scenary->map[0]);
	scenary->width = (ft_strlen(scenary->map[0]) - 1);
	if (scenary->width != tmp_walls || tmp_walls == 0)
		return (0);
	i = 0;
	while (++i && scenary->map[i])
	{
		right = ft_check_objet(scenary, scenary->map[i]);
		if (scenary->x != 0 && scenary->y == 0)
			scenary->y = i;
		if (!right || scenary->width != right)
			return (0);
	}
	if (scenary->width != tmp_walls || tmp_walls == 0 || scenary->width == i)
		return (0);
	scenary->height = i;
	if (scenary->objet < 1 || scenary->start != 1 || scenary->exit != 1)
		return (0);
	scenary->filled = scenary->objet;
	return (1);
}

static int	ft_check_map(char *arg, t_scenary *scenary)
{
	int		fd;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (0);
	scenary->map = malloc(100 * sizeof(char *));
	if (!scenary->map)
	{
		close(fd);
		return (0);
	}
	i = 0;
	while (1)
	{
		scenary->map[i] = get_next_line(fd);
		if (!scenary->map[i])
			break ;
		i++;
	}
	close (fd);
	if (!ft_check_scenary(scenary))
		return (ft_free_char(scenary->map));
	return (1);
}

static int	ft_is_point_ber(char *arg, t_scenary *scenary)
{
	int	point;
	int	size;

	size = ft_strlen(arg);
	if (size < 5)
		return (0);
	point = size - 4;
	if (ft_strncmp(&arg[point], ".ber", 4))
		return (0);
	if (!ft_check_map(arg, scenary))
		return (0);
	return (1);
}

t_scenary	*ft_isscenary(int argv, char **args)
{
	t_scenary	*scenary;

	if (argv != 2)
		return (NULL);
	scenary = malloc(sizeof(t_scenary));
	if (!scenary)
		return (NULL);
	if (!ft_is_point_ber(args[1], scenary))
	{
		free(scenary);
		return (NULL);
	}
	scenary->map_clone = (char **)ft_pstrdup((const char **)scenary->map);
	if (!scenary->map_clone)
		return (0);
	return (scenary);
}
