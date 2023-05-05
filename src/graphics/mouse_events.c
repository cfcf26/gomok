/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:58:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 17:27:46 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int	button_press(int button, int x, int y, void *parms)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)parms;
	if (button == MOUSE_BUTTON_LEFT && \
		mlx->map[y / TILE_SIZE][x / TILE_SIZE] == EMPTY)
	{
		if (mlx->turn == BLACKSTONE)
			mlx->map[y / TILE_SIZE][x / TILE_SIZE] = BLACKSTONE;
		else
			mlx->map[y / TILE_SIZE][x / TILE_SIZE] = WHITESTONE;
		mlx->turn = (mlx->turn == BLACKSTONE) ? WHITESTONE : BLACKSTONE;
	}
	return (0);
}

void	mouse_events(t_mlx *mlx)
{
	mlx_mouse_hook(mlx->win, button_press, mlx);
}
