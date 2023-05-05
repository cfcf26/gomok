/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:01:52 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 11:27:21 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "utils.h"

void	init_graphics_context(t_mlx *mlx);
void	display_board(t_mlx *mlx);
void	mouse_events(t_mlx *mlx);

#endif
