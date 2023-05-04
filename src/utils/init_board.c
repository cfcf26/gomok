/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:21:53 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 02:42:12 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	g_BOARD[BOARD_SIZE][BOARD_SIZE];

void	init_board(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BOARD_SIZE)
	{
		j = -1;
		while (++j < BOARD_SIZE)
			g_BOARD[i][j] = EMPTY;
	}
}
