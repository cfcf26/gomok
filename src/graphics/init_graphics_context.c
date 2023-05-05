/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics_context.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:01:16 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 12:12:31 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	init_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BOARD_SIZE)
	{
		j = -1;
		while (++j < BOARD_SIZE)
		{
			mlx->map[i][j] = EMPTY;
			mlx->selected[i][j] = EMPTY;
		}
	}
}

void	init_graphics_context(t_mlx *mlx)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "GAME_NAME");
	mlx->blackstone = mlx_xpm_file_to_image(mlx->mlx, BLACKSTONE_PATH, &w, &h);
	mlx->whitestone = mlx_xpm_file_to_image(mlx->mlx, WHITESTONE_PATH, &w, &h);
	mlx->board = mlx_xpm_file_to_image(mlx->mlx, BOARD_PATH, &w, &h);
	mlx->forbidden = mlx_xpm_file_to_image(mlx->mlx, FORBIDDEN_PATH, &w, &h);
	mlx->select = mlx_xpm_file_to_image(mlx->mlx, SELECT_PATH, &w, &h);
	mlx->turn = BLACKSTONE;
	init_map(mlx);
}
