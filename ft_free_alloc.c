/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:14:09 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/30 15:54:21 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_position	ft_resize(t_malloc *alloc, mlx_image_t *img, t_position	p, int i)
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
	while (height > 2160)
	{
		p.height /= 1.5;
		height /= 1.5;
	}
	mlx_resize_image(img, (p.width + i), (p.height + i));
	size.x = (p.width + i);
	size.y = (p.height + i);
	mlx_set_window_limit(alloc->mlx, 0, 0, width, height);
	return (size);
}

void	ft_free_map(t_malloc *alloc)
{
	if (alloc->map->charact)
		mlx_delete_image(alloc->mlx, alloc->map->charact);
	if (alloc->map->obj)
		mlx_delete_image(alloc->mlx, alloc->map->obj);
	if (alloc->map->wall)
		mlx_delete_image(alloc->mlx, alloc->map->wall);
	if (alloc->map->exit)
		mlx_delete_image(alloc->mlx, alloc->map->exit);
	if (alloc->map->spa)
		mlx_delete_image(alloc->mlx, alloc->map->spa);
	if (alloc->map->moves)
		mlx_delete_image(alloc->mlx, alloc->map->moves);
	if (alloc->map->mob)
		mlx_delete_image(alloc->mlx, alloc->map->mob);
}

int	ft_free_alloc(t_malloc *alloc, int error)
{
	if (alloc->icon_texture)
		mlx_delete_texture(alloc->icon_texture);
	if (alloc->scenary)
	{
		if (alloc->scenary->map)
			ft_free_char(alloc->scenary->map);
		if (alloc->scenary->map_clone)
			ft_free_char(alloc->scenary->map_clone);
		free(alloc->scenary);
	}
	if (alloc->map)
	{
		ft_free_map(alloc);
		free(alloc->map);
	}
	if (alloc->mlx)
		mlx_terminate(alloc->mlx);
	if (error == 1)
		ft_printf("Error\nicon\n");
	if (error == 2)
		ft_printf("Error\nmap\n");
	if (error == 3)
		ft_printf("Error\nmlx\n");
	free(alloc);
	return (1);
}
