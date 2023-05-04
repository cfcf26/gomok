/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:53:41 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 02:54:00 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	display_assets(t_mlx *mlx, void *asset, int x, int y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;

	mlx_put_image_to_window(mlx->mlx, mlx->win, asset, x, y);
}

void	display_board(t_mlx *mlx)
{
	int	i;
	int	j;

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->board, 0, 0);
	i = -1;
	while (++i < BOARD_SIZE)
	{
		j = -1;
		while (++j < BOARD_SIZE)
		{
			if (g_BOARD[i][j] == BLACKSTONE)
				display_assets(mlx, mlx->blackstone, j, i);
			else if (g_BOARD[i][j] == WHITESTONE)
				display_assets(mlx, mlx->whitestone, j, i);
			else if (g_BOARD[i][j] == FORBIDDEN)
				display_assets(mlx, mlx->forbidden, j, i);
		}
	}
}
