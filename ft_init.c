/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:42:10 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/15 19:16:32 by ischeini         ###   ########.fr       */
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

mlx_image_t	*ft_init_characters(mlx_t *mlx, mlx_texture_t *icon_texture)
{
	mlx_image_t	*character;
	int			color;

	character = mlx_new_image(mlx, 50, 50);
	if (!character || mlx_image_to_window(mlx, character, 0, 0) < 0)
	{
		mlx_delete_texture(icon_texture);
		mlx_terminate(mlx);
		return (NULL);
	}
	color = ft_dye(200, 200, 100, 50);
	mlx_put_pixel(character, 0, 0, color);
	return (character);
}

mlx_texture_t	*ft_init_icon(mlx_t *mlx)
{
	mlx_texture_t	*icon_texture;
	const char		*icon;
	
	icon = "car.png";
	icon_texture = mlx_load_png(icon);
	if (!icon_texture)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	mlx_set_icon(mlx, icon_texture);
	return (icon_texture);
}

mlx_t	*ft_init_mlx()
{
	mlx_t			*mlx;
	char			*name;

	name = "Police scape";
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, name, true);
	if (!mlx)
		return (NULL);
	mlx_set_window_title(mlx, name);
	return (mlx);
}
