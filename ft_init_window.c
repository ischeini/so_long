/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:42:10 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/29 12:48:08 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_flood_fill(t_scenary *scenary, int x, int y)
{
	int	filled;

	filled = 0;
	if (x < 0 || y < 0 || x >= scenary->width || y >= scenary->height)
		return (0);
	if (scenary->map_clone[y][x] == '1' || scenary->map_clone[y][x] == '*' ||
		scenary->map_clone[y][x] == 'M')
		return (0);
	if (scenary->map_clone[y][x] == 'E')
	{
		scenary->find = 1;
		return (0);
	}
	if (scenary->map_clone[y][x] == 'C')
		filled = 1;
	scenary->map_clone[y][x] = '*';
	filled += ft_flood_fill(scenary, x + 1, y);
	filled += ft_flood_fill(scenary, x - 1, y);
	filled += ft_flood_fill(scenary, x, y + 1);
	filled += ft_flood_fill(scenary, x, y - 1);
	return (filled);
}

void	ft_scenary(t_scenary *scenary)
{
	scenary->objet = 0;
	scenary->walls = 0;
	scenary->space = 0;
	scenary->start = 0;
	scenary->moves = 0;
	scenary->find = 0;
	scenary->exit = 0;
	scenary->x = 0;
	scenary->y = 0;
}

mlx_image_t	*ft_init_text(t_malloc *alloc, char *name)
{
	mlx_texture_t	*space;
	mlx_image_t		*img;

	space = mlx_load_png(name);
	if (!space)
		return (NULL);
	space->height = 128;
	space->width = 128;
	if (!space)
		return (NULL);
	img = (mlx_image_t *)malloc(sizeof(mlx_image_t));
	if (!img)
	{
		mlx_delete_texture(space);
		return (NULL);
	}
	img = mlx_texture_to_image(alloc->mlx, space);
	mlx_delete_texture(space);
	if (!img)
		return (NULL);
	return (img);
}

mlx_texture_t	*ft_init_icon(mlx_t *mlx)
{
	mlx_texture_t	*icon_texture;

	icon_texture = mlx_load_png("textures/icon.png");
	if (!icon_texture)
		return (NULL);
	mlx_set_icon(mlx, icon_texture);
	return (icon_texture);
}

mlx_t	*ft_init_mlx(t_malloc *alloc)
{
	int32_t	height;
	int32_t	width;
	mlx_t	*mlx;
	char	*name;

	width = alloc->scenary->width * 128;
	height = alloc->scenary->height * 128;
	while (width > 3840)
		width /= 1.5;
	while (height > 2160)
		height /= 1.5;
	name = "Mineshaft";
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(width, height, name, true);
	if (!mlx)
		return (NULL);
	mlx_set_window_title(mlx, name);
	return (mlx);
}
