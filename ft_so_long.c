/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:05:59 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/16 19:49:48 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_start_game(t_malloc *alloc)
{
	alloc->map->character = ft_init_texture(alloc, "character.png");
	if (!alloc->map->character)
		return (ft_free_alloc(alloc));
	if (mlx_image_to_window(alloc->mlx, alloc->map->character, 64, 64) < 0)
		return (ft_free_alloc(alloc));
	alloc->map->object = ft_init_texture(alloc, "object.png");
	if (!alloc->map->object)
		return (ft_free_alloc(alloc));
	if (mlx_image_to_window(alloc->mlx, alloc->map->object, 128, 128) < 0)
		return (ft_free_alloc(alloc));
	alloc->map->walls = ft_init_texture(alloc, "walls.png");
	if (!alloc->map->walls)
		return (ft_free_alloc(alloc));
	if (mlx_image_to_window(alloc->mlx, alloc->map->walls, 192, 192) < 0)
		return (ft_free_alloc(alloc));
	alloc->map->start = ft_init_texture(alloc, "start.png");
	if (!alloc->map->start)
		return (ft_free_alloc(alloc));
	if (mlx_image_to_window(alloc->mlx, alloc->map->start, 256, 256) < 0)
		return (ft_free_alloc(alloc));
	alloc->map->exit = ft_init_texture(alloc, "exit.png");
	if (!alloc->map->exit)
		return (ft_free_alloc(alloc));
	if (mlx_image_to_window(alloc->mlx, alloc->map->exit, 320, 320) < 0)
		return (ft_free_alloc(alloc));
	alloc->map->space = ft_init_texture(alloc, "space.png");
	if (!alloc->map->space)
		return (ft_free_alloc(alloc));
	if (mlx_image_to_window(alloc->mlx, alloc->map->space, 384, 384) < 0)
				return (ft_free_alloc(alloc));
	return (1);
}

int	main(int argv, char **args)
{
	t_malloc	*alloc;

	alloc = (t_malloc *)malloc(sizeof(t_malloc));
	if (!alloc)
		return (1);
	alloc->map = (t_map *)malloc(sizeof (t_map));
	if (!alloc->map)
		return (ft_free_alloc(alloc));
	alloc->scenary = ft_isscenary(argv, args);
	if (!alloc->scenary)
		return (ft_free_alloc(alloc));
	alloc->mlx = ft_init_mlx(alloc);
	if (!alloc->mlx)
		return (ft_free_alloc(alloc));
	alloc->icon_texture = ft_init_icon(alloc->mlx);
	if (!alloc->icon_texture)
		return (ft_free_alloc(alloc));
	ft_start_game(alloc);
	mlx_loop(alloc->mlx);
	//ft_free_alloc(alloc);
	return (0);
}