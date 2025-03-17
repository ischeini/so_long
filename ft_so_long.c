/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:05:59 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/17 19:26:47 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int	ft_start_scenary2(t_malloc *alloc, char texture, t_position p)
{
	if (texture == 'P')
	{
		alloc->map->charact = ft_init_text(alloc, "scenary/charact.png");
		if (!alloc->map->charact)
			return (ft_free_alloc(alloc, 0));
		if (mlx_image_to_window(alloc->mlx, alloc->map->charact, p.x, p.y) < 0)
			return (ft_free_alloc(alloc, 0));
	}
	return (0);
}

static int	ft_start_scenary(t_malloc *alloc, char texture, t_position p)
{
	if (texture == '1')
	{
		alloc->map->wall = ft_init_text(alloc, "scenary/wall.png");
		if (!alloc->map->wall)
			return (ft_free_alloc(alloc, 0));
		if (mlx_image_to_window(alloc->mlx, alloc->map->wall, p.x, p.y) < 0)
			return (ft_free_alloc(alloc, 0));
	}
	if (texture == 'C')
	{
		alloc->map->obj = ft_init_text(alloc, "scenary/obj.png");
		if (!alloc->map->obj)
			return (ft_free_alloc(alloc, 0));
		if (mlx_image_to_window(alloc->mlx, alloc->map->obj, p.x, p.y) < 0)
			return (ft_free_alloc(alloc, 0));
	}
	if (texture == 'E')
	{
		alloc->map->exit = ft_init_text(alloc, "scenary/exit.png");
		if (!alloc->map->exit)
			return (ft_free_alloc(alloc, 0));
		if (mlx_image_to_window(alloc->mlx, alloc->map->exit, p.x, p.y) < 0)
			return (ft_free_alloc(alloc, 0));
	}
	return (ft_start_scenary2(alloc, alloc->scenary->map[p.j][p.i], p));
}

static int	ft_start_game(t_malloc *alloc)
{
	t_position	p;
	
	p.i = 0;
	p.x = 0;
	p.j = 0;
	p.y = 0;
	while (alloc->scenary->map[p.j])
	{
		while (alloc->scenary->map[p.j][p.i])
		{
			alloc->map->spa = ft_init_text(alloc, "scenary/spa.png");
			if (!alloc->map->spa)
				return (ft_free_alloc(alloc, 0));
			if (mlx_image_to_window(alloc->mlx, alloc->map->spa, p.x, p.y) < 0)
						return (ft_free_alloc(alloc, 0));
			if (ft_start_scenary(alloc, alloc->scenary->map[p.j][p.i], p))
				return (0);
			p.x += 128;
			p.i++;
		}
		p.y += 128;
		p.i = 0;
		p.x = 0;
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
		return (1);
	alloc->map = (t_map *)malloc(sizeof (t_map));
	if (!alloc->map)
		return (ft_free_alloc(alloc, 0));
	alloc->scenary = ft_isscenary(argv, args);
	if (!alloc->scenary)
		return (ft_free_alloc(alloc, 2));
	fill = ft_flood_fill(alloc->scenary, alloc->scenary->x, alloc->scenary->y);
	if (fill != alloc->scenary->filled)
		return (ft_free_alloc(alloc, 2));
	alloc->mlx = ft_init_mlx(alloc);
	if (!alloc->mlx)
		return (ft_free_alloc(alloc, 3));
	alloc->icon_texture = ft_init_icon(alloc->mlx);
	if (!alloc->icon_texture)
		return (ft_free_alloc(alloc, 1));
	if (!ft_start_game(alloc))
		return (1);
	mlx_loop(alloc->mlx);
	//ft_free_alloc(alloc);
	return (0);
}