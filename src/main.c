/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:38:47 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/06 01:44:22 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	exit_program(void)
{
	exit(0);
}

void	setup(t_mlx *mlx)
{
	init_graphics_context(mlx);
}

int	routines(t_mlx *mlx)
{
	int	winner;

	mlx_clear_window(mlx->mlx, mlx->win);
	mouse_events(mlx);
	display_board(mlx);
	winner = check_winner(mlx);
	if (winner != EMPTY)
	{
		if (winner == BLACKSTONE)
			printf("BLACKSTONE wins!\n");
		else
			printf("WHITESTONE wins!\n");
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	setup(&mlx);
	display_board(&mlx);
	mlx_loop_hook(mlx.mlx, routines, &mlx);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, exit_program, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

