/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:07:42 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/20 18:53:48 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_position
{
	int	height;
	int	width;
	int	x;
	int	y;
	int	i;
	int	j;
}	t_position;

/*Struct of the scenary														 */
typedef struct s_scenary
{
	int32_t	height;
	int32_t	width;
	char	**map_clone;
	char	**map;
	int		zoom_level;
	int		filled;
	int		objet;
	int		walls;
	int		space;
	int		start;
	int		moves;
	int		open;
	int		find;
	int		exit;
	int		x;
	int		y;
}	t_scenary;

typedef struct s_map
{
	mlx_image_t	*charact;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*spa;
	mlx_image_t	*obj;
}	t_map;

typedef struct s_malloc
{
	mlx_texture_t	*icon_texture;
	t_scenary		*scenary;
	t_map			*map;
	mlx_t			*mlx;
}	t_malloc;

/*Bring the colors Transparent, Red, Green and Blue							 */
unsigned char	ft_get_t(int trgb);
unsigned char	ft_get_r(int trgb);
unsigned char	ft_get_g(int trgb);
unsigned char	ft_get_b(int trgb);

/*initiate the icon of the game												 */
mlx_texture_t	*ft_init_icon(mlx_t *mlx);

/*initiate the texture of the scenary										 */
mlx_image_t		*ft_init_text(t_malloc *alloc, char *name);
/*check if the .ber is a real scenary for the game							 */
t_scenary		*ft_isscenary(int argv, char **args);

/*initiate the windows for the game											 */
mlx_t			*ft_init_mlx(t_malloc *alloc);

/*initiate the data from the escenary										 */
void			ft_scenary(t_scenary *scenary);

int				ft_hooks_mlx(t_malloc *alloc);

int				ft_start_game(t_malloc *alloc);

/*ft_dye get a combination color from Transparent, Red, Green and Blue		 */
int				ft_dye(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);

int				ft_start_texture(t_malloc *alloc);

/*free a char **										 					 */
int				ft_flood_fill(t_scenary *scenary, int x, int y);

void			ft_free_map(t_malloc *alloc);

int				ft_free_alloc(t_malloc *alloc, int error);

#endif