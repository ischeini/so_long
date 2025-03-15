/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:05:59 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/15 19:18:49 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_hook(void *param)
{
	const mlx_t *mlx;

	mlx = param;
}

int	main(int argv, char **args)
{
	mlx_texture_t	*icon_texture;
	mlx_image_t		*character;
	t_scenary		*scenary;
	mlx_t			*mlx;

	scenary = ft_isscenary(argv, args);
	if (!scenary)
		return (1);
	mlx = ft_init_mlx();
	if (!mlx)
		return (1);
	icon_texture = ft_init_icon(mlx);
	if (!icon_texture)
		return (1);
	character = ft_init_characters(mlx, icon_texture);
	if (!character)
		return (1);
	ft_start_game(mlx, icon_texture, character);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_texture(icon_texture);
	mlx_delete_image(mlx, character);
	ft_free_char(scenary->map);
	free(scenary);
	mlx_terminate(mlx);
	return (0);
}