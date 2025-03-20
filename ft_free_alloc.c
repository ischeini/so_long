/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:14:09 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/20 17:51:58 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

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
		ft_printf("Error\n icon\n");
	if (error == 2)
		ft_printf("Error\n map\n");
	if (error == 3)
		ft_printf("Error\n mlx\n");
	free(alloc);
	return (1);
}
