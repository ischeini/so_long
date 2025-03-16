/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:14:09 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/16 14:41:51 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

void	ft_free_map(t_malloc *alloc)
{
	if (alloc->map->character)
		mlx_delete_image(alloc->mlx, alloc->map->character);
	if (alloc->map->object)
		mlx_delete_image(alloc->mlx, alloc->map->object);
	if (alloc->map->start)
		mlx_delete_image(alloc->mlx, alloc->map->start);
	if (alloc->map->walls)
		mlx_delete_image(alloc->mlx, alloc->map->walls);
	if (alloc->map->exit)
		mlx_delete_image(alloc->mlx, alloc->map->exit);
	free(alloc->map);
}

int	ft_free_alloc(t_malloc *alloc)
{
	if (alloc->icon_texture)
		mlx_delete_texture(alloc->icon_texture);
	if (alloc->scenary)
	{
		ft_free_char(alloc->scenary->map);
		free(alloc->scenary);
	}
	if (alloc->map)
		ft_free_map(alloc);
	if (alloc->mlx)
		mlx_terminate(alloc->mlx);
	free(alloc);
	return (1);
}