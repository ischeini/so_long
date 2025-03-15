/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:07:42 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/15 19:00:43 by ischeini         ###   ########.fr       */
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
# ifndef WIDTH
#  define WIDTH 2000
# endif
# ifndef HEIGHT
#  define HEIGHT 1100
# endif

/*Struct of the character													 */
typedef struct s_character
{
	int			height;
	int			width;
	int			color;
	int			x;
	int			y;
}	t_character;

/*Struct of the scenary														 */
typedef struct s_scenary
{
	char		**map;
	int			height;
	int			width;
	int			objet;
	int			walls;
	int			space;
	int			start;
	int			exit;
}	t_scenary;

typedef struct s_map
{
	t_character	character;
	t_character	object;
	t_character	start;
	t_character	walls;
	t_character	exit;
}	t_map;


/*Bring the colors Transparent, Red, Green and Blue							 */
unsigned char	ft_get_t(int trgb);
unsigned char	ft_get_r(int trgb);
unsigned char	ft_get_g(int trgb);
unsigned char	ft_get_b(int trgb);

/*initiate the icon of the game												 */
mlx_texture_t	*ft_init_icon(mlx_t *mlx);

/*initiate the player int he game											 */
mlx_image_t		*ft_init_characters(mlx_t *mlx, mlx_texture_t *icon_texture);

/*check if the .ber is a real scenary for the game							 */
t_scenary		*ft_isscenary(int argv, char **args);

/*initiate the windows for the game											 */
mlx_t			*ft_init_mlx();

/*initiate the data from the escenary										 */
void			ft_scenary(t_scenary *scenary);

/*ft_dye get a combination color from Transparent), Red, Green and Blue		 */
int				ft_dye(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b);

/*free a char **										 					 */
int				ft_free_char(char **to_free);

#endif