/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:42:10 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/16 19:36:40 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_scenary(t_scenary *scenary)
{
	scenary->objet = 0;
	scenary->walls = 0;
	scenary->space = 0;
	scenary->start = 0;
	scenary->exit = 0;
}

mlx_image_t	*ft_init_texture(t_malloc *alloc, char *name)
{
	mlx_texture_t	*space;
	mlx_image_t		*img;

	space = mlx_load_png(name);
	space->height = 64;
	space->width = 64;
	if (!space)
		return (NULL);
	img = mlx_texture_to_image(alloc->mlx, space);
	mlx_delete_texture(space);
	if (!img)
		return (NULL);
	return (img);
}

mlx_texture_t	*ft_init_icon(mlx_t *mlx)
{
	mlx_texture_t	*icon_texture;
	
	icon_texture = mlx_load_png("car.png");
	if (!icon_texture)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	mlx_set_icon(mlx, icon_texture);
	return (icon_texture);
}

mlx_t	*ft_init_mlx(t_malloc *alloc)
{
	int32_t	height;
	int32_t	width;
	mlx_t	*mlx;
	char	*name;

	width = alloc->scenary->width * 64;
	height = alloc->scenary->height * 64;
	name = "Police scape";
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(width, height, name, false);
	if (!mlx)
		return (NULL);
	mlx_set_window_title(mlx, name);
	return (mlx);
}
