/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:08:03 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/06 02:15:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

//blackstone = 1, whitestone = 2
//Black stones are only won when there are exactly five.
//White stone is a victory when there are more than five.

static int	check_horizontal(t_mlx *mlx, int player)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	while (++i < BOARD_SIZE)
	{
		j = -1;
		count = 0;
		while (++j < BOARD_SIZE)
		{
			if (mlx->map[i][j] == player)
				count++;
			else
			{
				if (player == BLACKSTONE && count == 5)
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				count = 0;
			}
		}
	}
	return (0);
}

static int	check_vertical(t_mlx *mlx, int player)
{
	int		i;
	int		j;
	int		count;

	j = -1;
	while (++j < BOARD_SIZE)
	{
		i = -1;
		count = 0;
		while (++i < BOARD_SIZE)
		{
			if (mlx->map[i][j] == player)
				count++;
			else
			{
				if (player == BLACKSTONE && count == 5)
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				count = 0;
			}
		}
	}
	return (0);
}

static int check_diagonal_left_to_right(t_mlx *mlx, int player)
{
	int i = 0, j, count;

	while (i < BOARD_SIZE)
	{
		j = 0;
		while (j < BOARD_SIZE)
		{
			count = 0;
			int x = i;
			int y = j;
			while (x < BOARD_SIZE && y < BOARD_SIZE)
			{
				if (mlx->map[x][y] == player)
					count++;
				else
					count = 0;
				if (player == BLACKSTONE && count == 5 && (x == BOARD_SIZE - 1 || y == 0 || mlx->map[x + 1][y - 1] != BLACKSTONE))
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				x++;
				y++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int check_diagonal_right_to_left(t_mlx *mlx, int player)
{
	int i = 0, j, count;

	while (i < BOARD_SIZE)
	{
		j = 0;
		while (j < BOARD_SIZE)
		{
			count = 0;
			int x = i;
			int y = j;
			while (x < BOARD_SIZE && y >= 0)
			{
				if (mlx->map[x][y] == player)
					count++;
				else
					count = 0;
				if (player == BLACKSTONE && count == 5 && (x == BOARD_SIZE - 1 || y == 0 || mlx->map[x + 1][y - 1] != BLACKSTONE))
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				x++;
				y--;
			}
			j++;
		}
		i++;
	}
	return (0);
}



int	check_winner(t_mlx *mlx)
{
	int	player;

	player = (mlx->turn == BLACKSTONE) ? WHITESTONE : BLACKSTONE;
	if (check_horizontal(mlx, player) || \
		check_diagonal_left_to_right(mlx, player) || \
		check_diagonal_right_to_left(mlx, player) || \
		check_vertical(mlx, player))
		return (player);
	return (0);
}

