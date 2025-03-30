/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:21:24 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/30 13:52:49 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static void	ft_print_moves(t_malloc *tmp, int moves)
{
	char	*str;
	int		intlen;
	int		nbr;

	nbr = moves;
	intlen = 1;
	while (nbr >= 10 && intlen++)
		nbr /= 10;
	str = malloc((intlen + 1) * sizeof(char));
	if (!str)
		return ;
	nbr = moves;
	str[intlen] = '\0';
	while (intlen > 0)
	{
		str[--intlen] = (nbr % 10) + '0';
		nbr /= 10;
	}
	tmp->map->moves = mlx_put_string(tmp->mlx, str, 100, 75);
	mlx_resize_image(tmp->map->moves, 70, 90);
	free(str);
}

static void	ft_reload(t_malloc *tmp, int x, int y)
{
	if (tmp->scenary->map[y][x] == '0' || tmp->scenary->map[y][x] == 'C')
	{
		if (tmp->scenary->map[y][x] == 'C')
			tmp->scenary->find += 1;
		tmp->scenary->map[tmp->scenary->y][tmp->scenary->x] = '0';
		tmp->scenary->map[y][x] = 'P';
		tmp->scenary->x = x;
		tmp->scenary->y = y;
		tmp->scenary->moves += 1;
	}
	if (tmp->scenary->map[y][x] == 'E' || tmp->scenary->map[y][x] == 'M')
	{
		if (tmp->scenary->find == tmp->scenary->objet
			|| tmp->scenary->map[y][x] == 'M')
		{
			mlx_close_window(tmp->mlx);
			return ;
		}
	}
	ft_free_map(tmp);
	if ((tmp->scenary->moves % 2) == 1)
		ft_start_game_bonus(tmp, 4);
	else
		ft_start_game_bonus(tmp, 0);
	ft_print_moves(tmp, tmp->scenary->moves);
}

static void	ft_moves(mlx_key_data_t keydata, void *alloc)
{
	t_malloc	*tmp;

	tmp = alloc;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_reload(tmp, tmp->scenary->x, (tmp->scenary->y - 1));
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_reload(tmp, tmp->scenary->x, (tmp->scenary->y + 1));
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_reload(tmp, (tmp->scenary->x - 1), tmp->scenary->y);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_reload(tmp, (tmp->scenary->x + 1), tmp->scenary->y);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_reload(tmp, tmp->scenary->x, (tmp->scenary->y - 1));
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_reload(tmp, tmp->scenary->x, (tmp->scenary->y + 1));
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_reload(tmp, (tmp->scenary->x - 1), tmp->scenary->y);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_reload(tmp, (tmp->scenary->x + 1), tmp->scenary->y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(tmp->mlx);
}

int	ft_bonus_hooks_mlx(t_malloc *alloc)
{
	alloc->scenary->find = 0;
	mlx_key_hook(alloc->mlx, &ft_moves, (void *) alloc);
	mlx_loop(alloc->mlx);
	return (ft_free_alloc(alloc, 5));
}
