/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:52:37 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 12:10:06 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELS_H
# define MODELS_H

# define GAME_NAME "Gomoku"
# define TILE_SIZE 32
# define BOARD_SIZE 19
# define WIN_WIDTH (TILE_SIZE * BOARD_SIZE)
# define WIN_HEIGHT (TILE_SIZE * BOARD_SIZE)
# define BLACKSTONE_PATH "./img/blackstone.xpm"
# define WHITESTONE_PATH "./img/whitestone.xpm"
# define BOARD_PATH "./img/board.xpm"
# define FORBIDDEN_PATH "./img/forbidden.xpm"
# define SELECT_PATH "./img/select.xpm"
# define EMPTY 0
# define BLACKSTONE 1
# define WHITESTONE 2
# define FORBIDDEN 3
# define SELECTED 4

# define MOUSE_BUTTON_LEFT 1
# define MOTION_NOTIFY 8192

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*blackstone;
	void	*whitestone;
	void	*board;
	void	*forbidden;
	void	*select;
	int		map[BOARD_SIZE][BOARD_SIZE];
	int		selected[BOARD_SIZE][BOARD_SIZE];
	int		turn;
}	t_mlx;

#endif
