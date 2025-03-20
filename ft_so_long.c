/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:05:59 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/20 19:10:13 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_position	ft_resize(t_malloc *alloc, mlx_image_t *img, t_position	p)
{
	t_position	size;
	int32_t		height;
	int32_t		width;

	width = alloc->scenary->width * 128;
	height = alloc->scenary->height * 128;
	p.height = 128;
	p.width = 128;
	while (width > 3840)
	{
		p.width /= 1.5;
		width /= 1.5;
	}
	while (height >2160)
	{
		p.height /= 1.5;
		height /= 1.5;
	}
	mlx_resize_image(img, p.width, p.height);
	size.x = p.width;
	size.y = p.height;
	mlx_set_window_limit(alloc->mlx, 0, 0, width, height);
	return (size);
}

static int	ft_start_scenary(t_malloc *alloc, char texture, t_position p)
{
	if (texture == '1')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->wall, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->wall, p);
	}
	if (texture == 'C')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->obj, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->obj, p);
	}
	if (texture == 'E')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->exit, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->exit, p);
	}
	if (texture == 'P')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->charact, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->charact, p);
	}
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

int	ft_start_game(t_malloc *alloc)
{
	t_position	size;
	t_position	p;
	
	p.j = 0;
	p.y = 0;
	if (!ft_start_texture(alloc))
		return (0);
	while (alloc->scenary->map[p.j])
	{
		p.i = 0;
		p.x = 0;
		while (alloc->scenary->map[p.j][p.i] && alloc->scenary->map[p.j][p.i] != '\n')
		{
			if (mlx_image_to_window(alloc->mlx, alloc->map->spa, p.x, p.y) < 0)
				return (0);
			size = ft_resize(alloc, alloc->map->spa, p);
			if (!ft_start_scenary(alloc, alloc->scenary->map[p.j][p.i], p))
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
	if (!alloc->icon_texture )
		return (ft_free_alloc(alloc, 1));
	if (!ft_start_game(alloc))
		return (ft_free_alloc(alloc, 3));
	return (ft_hooks_mlx(alloc));
}