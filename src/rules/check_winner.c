/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:08:03 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/06 14:05:41 by ekwak            ###   ########.fr       */
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
static int	check_diagonal_left_to_right(t_mlx *mlx, int player)
{
	int	i;
	int	j;
	int	count;
	int	x;
	int	y;

	i = 0;
	j = 0;
	while (++i < BOARD_SIZE - 4)
	{
		count = 0;
		x = i;
		y = j;
		while (x < BOARD_SIZE - 4 && y < BOARD_SIZE - 4)
		{
			if (mlx->map[x][y] == player)
				count++;
			else
			{
				if (player == BLACKSTONE && count > 5)
					return (FOUL);
				else if (player == BLACKSTONE && count == 5)
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				count = 0;
			}
			x++;
			y++;
		}
	}
	i = 0;
	j = -1;
	while (++j < BOARD_SIZE - 4)
	{
		count = 0;
		x = i;
		y = j;
		while (x < BOARD_SIZE - 4 && y < BOARD_SIZE - 4)
		{
			if (mlx->map[x][y] == player)
				count++;
			else
			{
				if (player == BLACKSTONE && count > 5)
					return (FOUL);
				else if (player == BLACKSTONE && count == 5)
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				count = 0;
			}
			x++;
			y++;
		}
	}
	return (0);
}

static int	check_diagonal_right_to_left(t_mlx *mlx, int player)
{
	int	i;
	int	j;
	int	count;
	int	x;
	int	y;

	i = 0;
	j = BOARD_SIZE - 1;
	while (++i < BOARD_SIZE - 4)
	{
		count = 0;
		x = i;
		y = j;
		while (x < BOARD_SIZE - 4 && y > 3)
		{
			if (mlx->map[x][y] == player)
				count++;
			else
			{
				if (player == BLACKSTONE && count > 5)
					return (FOUL);
				else if (player == BLACKSTONE && count == 5)
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				count = 0;
			}
			x++;
			y--;
		}
	}
	i = 0;
	j = BOARD_SIZE;
	while (++j < BOARD_SIZE - 4)
	{
		count = 0;
		x = i;
		y = j;
		while (x < BOARD_SIZE - 4 && y > 3)
		{
			if (mlx->map[x][y] == player)
				count++;
			else
			{
				if (player == BLACKSTONE && count > 5)
					return (FOUL);
				else if (player == BLACKSTONE && count == 5)
					return (BLACKSTONE);
				else if (player == WHITESTONE && count >= 5)
					return (WHITESTONE);
				count = 0;
			}
			x++;
			y--;
		}
	}
	return (0);
}

int	check_winner(t_mlx *mlx)
{
	int	player;
	int	result;

	result = 0;
	player = (mlx->turn == BLACKSTONE) ? WHITESTONE : BLACKSTONE;
	result = check_horizontal(mlx, player);
	if (result)
		return (result);
	result = check_vertical(mlx, player);
	if (result)
		return (result);
	result = check_diagonal_left_to_right(mlx, player);
	if (result)
		return (result);
	result = check_diagonal_right_to_left(mlx, player);
	if (result)
		return (result);
	return (0);
}

