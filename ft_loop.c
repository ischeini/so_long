/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:57:34 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/30 13:10:30 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_reload(t_malloc *tmp, int x, int y)
{
	if (tmp->scenary->map[y][x] == '0' || tmp->scenary->map[y][x] == 'C')
	{
		if (tmp->scenary->map[y][x] == 'C')
		{
			tmp->scenary->find += 1;
		}
		tmp->scenary->map[tmp->scenary->y][tmp->scenary->x] = '0';
		tmp->scenary->map[y][x] = 'P';
		tmp->scenary->x = x;
		tmp->scenary->y = y;
		tmp->scenary->moves += 1;
		printf("%i\n", tmp->scenary->moves);
	}
	if (tmp->scenary->map[y][x] == 'E')
	{
		if (tmp->scenary->find == tmp->scenary->objet)
		{
			mlx_close_window(tmp->mlx);
			return ;
		}
	}
	ft_free_map(tmp);
	ft_start_game(tmp);
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

int	ft_hooks_mlx(t_malloc *alloc)
{
	alloc->scenary->find = 0;
	mlx_key_hook(alloc->mlx, &ft_moves, (void *) alloc);
	mlx_loop(alloc->mlx);
	return (ft_free_alloc(alloc, 5));
}
