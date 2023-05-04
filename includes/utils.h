/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:48:53 by ekwak             #+#    #+#             */
/*   Updated: 2023/05/05 02:37:18 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h> // write, read, close
# include <stdlib.h> // malloc, free, exit
# include <fcntl.h> // open, close
# include <stdio.h> // perror
# include <string.h> // memset, bzero, memcpy, memccpy, memmove...
# include <limits.h> // INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ...
# include <math.h> // pow, sqrt, floor, ceil, ...
# include <sys/time.h> // gettimeofday, ...
# include "../minilibx_opengl_20191021/mlx.h" // mlx
# include "models.h" // models

void	init_board(void);

#endif
