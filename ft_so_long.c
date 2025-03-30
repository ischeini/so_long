/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:05:59 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/30 17:45:14 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	ft_start_scenary2(t_malloc *alloc, char texture, t_position p)
{
	if (texture == 'P')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->charact, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->charact, p, 0);
	}
	if (texture == 'M')
		return (0);
	return (1);
}

static int	ft_start_scenary(t_malloc *alloc, char texture, t_position p)
{
	if (texture == '1')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->wall, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->wall, p, 0);
	}
	else if (texture == 'C')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->obj, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->obj, p, 0);
	}
	else if (texture == 'E')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->exit, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->exit, p, 0);
	}
	else
		return (ft_start_scenary2(alloc, texture, p));
	return (1);
}

int	ft_start_texture(t_malloc *alloc)
{
	alloc->map->wall = ft_init_text(alloc, "textures/wall.png");
	if (!alloc->map->wall)
		return (0);
	alloc->map->obj = ft_init_text(alloc, "textures/obj.png");
	if (!alloc->map->obj)
		return (0);
	alloc->map->exit = ft_init_text(alloc, "textures/exit.png");
	if (!alloc->map->exit)
		return (0);
	alloc->map->charact = ft_init_text(alloc, "textures/charact.png");
	if (!alloc->map->charact)
		return (0);
	alloc->map->spa = ft_init_text(alloc, "textures/spa.png");
	if (!alloc->map->spa)
		return (0);
	return (1);
}

int	ft_start_game(t_malloc *a)
{
	t_position	size;
	t_position	p;

	p.j = 0;
	p.y = 0;
	if (!ft_start_texture(a))
		return (0);
	while (a->scenary->map[p.j])
	{
		p.i = 0;
		p.x = 0;
		while (a->scenary->map[p.j][p.i] && a->scenary->map[p.j][p.i] != '\n')
		{
			if (mlx_image_to_window(a->mlx, a->map->spa, p.x, p.y) < 0)
				return (0);
			size = ft_resize(a, a->map->spa, p, 0);
			if (!ft_start_scenary(a, a->scenary->map[p.j][p.i], p))
				return (0);
			p.x += size.x;
			p.i++;
		}
		p.y += size.y;
		p.j++;
	}
	return (1);
}

int	main(int argv, char **args)
{
	t_malloc	*alloc;
	int			fill;

	alloc = (t_malloc *)malloc(sizeof(t_malloc));
	if (!alloc)
		return (ft_printf("Error\n malloc"));
	alloc->map = (t_map *)malloc(sizeof (t_map));
	if (!alloc->map)
		return (ft_free_alloc(alloc, 3));
	alloc->scenary = ft_isscenary(argv, args);
	if (!alloc->scenary)
		return (ft_free_alloc(alloc, 2));
	fill = ft_flood_fill(alloc->scenary, alloc->scenary->x, alloc->scenary->y);
	if ((fill != alloc->scenary->filled) || alloc->scenary->find == 0)
		return (ft_free_alloc(alloc, 2));
	alloc->mlx = ft_init_mlx(alloc);
	if (!alloc->mlx)
		return (ft_free_alloc(alloc, 3));
	alloc->icon_texture = ft_init_icon(alloc->mlx);
	if (!alloc->icon_texture)
		return (ft_free_alloc(alloc, 1));
	if (!ft_start_game(alloc))
		return (ft_free_alloc(alloc, 2));
	return (ft_hooks_mlx(alloc));
}
