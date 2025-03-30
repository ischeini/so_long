/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:59:45 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/30 14:25:54 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static int	ft_start_mob(t_malloc *alloc, char texture, t_position p, int i)
{
	if (texture == '1')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->wall, p.x, p.y) < 0)
		return (0);
		ft_resize(alloc, alloc->map->wall, p, i);
	}
	if (i == 4)
	{
		p.x -= 8;
		p.y -= 8;
	}
	if (texture == 'M')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->mob, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->mob, p, (i * i + i));
	}
	if (i == 4)
	{
		p.x += 8;
		p.y += 8;
	}
	return (1);
}

static int	ft_start_scenary(t_malloc *alloc, char textur, t_position p, int i)
{
	if (textur == 'C')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->obj, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->obj, p, 0);
	}
	if (textur == 'E')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->exit, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->exit, p, 0);
	}
	if (textur == 'P')
	{
		if (mlx_image_to_window(alloc->mlx, alloc->map->charact, p.x, p.y) < 0)
			return (0);
		ft_resize(alloc, alloc->map->charact, p, 0);
	}
	return (ft_start_mob(alloc, textur , p, i));
}

int	ft_start_bonus_texture(t_malloc *alloc)
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
	alloc->map->mob = ft_init_text(alloc, "textures/mob.png");
	if (!alloc->map->mob)
		return (0);
	return (1);
}

int	ft_start_game_bonus(t_malloc *a, int i)
{
	t_position	size;
	t_position	p;

	p.j = 0;
	p.y = 0;
	if (!ft_start_bonus_texture(a))
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
			if (!ft_start_scenary(a, a->scenary->map[p.j][p.i], p, i))
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
	if (!ft_start_game_bonus(alloc, 0))
		return (ft_free_alloc(alloc, 3));
	return (ft_bonus_hooks_mlx(alloc));
}
