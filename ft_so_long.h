/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:07:42 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/16 19:37:19 by ischeini         ###   ########.fr       */
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

/*Struct of the character													 */
typedef struct s_character
{
	int	height;
	int	width;
	int	color;
	int	x;
	int	y;
}	t_character;

/*Struct of the scenary														 */
typedef struct s_scenary
{
	int32_t	height;
	int32_t	width;
	char	**map;
	char	*objet_name;
	char	*walls_name;
	char	*space_name;
	char	*start_name;
	char	*exit_name;
	int		objet;
	int		walls;
	int		space;
	int		start;
	int		exit;
}	t_scenary;

typedef struct s_map
{
	mlx_image_t	*character;
	mlx_image_t	*object;
	mlx_image_t	*space;
	mlx_image_t	*start;
	mlx_image_t	*walls;
	mlx_image_t	*exit;
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
mlx_image_t		*ft_init_texture(t_malloc *alloc, char *name);
/*check if the .ber is a real scenary for the game							 */
t_scenary		*ft_isscenary(int argv, char **args);

/*initiate the windows for the game											 */
mlx_t			*ft_init_mlx(t_malloc *alloc);

/*initiate the data from the escenary										 */
void			ft_scenary(t_scenary *scenary);

/*ft_dye get a combination color from Transparent), Red, Green and Blue		 */
int				ft_dye(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b);

/*free a char **										 					 */
int				ft_free_alloc(t_malloc *alloc);

#endif