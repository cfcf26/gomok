/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:38:47 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 12:12:49 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	setup(t_mlx *mlx)
{
	init_graphics_context(mlx);
}

void	routines(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mouse_events(mlx);
	display_board(mlx);
	mlx_loop(mlx->mlx);
}

int	main(void)
{
	t_mlx	mlx;

	setup(&mlx);
	display_board(&mlx);
	routines(&mlx);
	return (0);
}

