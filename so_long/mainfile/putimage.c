/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:29:59 by beeren            #+#    #+#             */
/*   Updated: 2023/09/12 13:02:49 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"

void	load_xpm(t_data *data)
{
	int	tmp_x;
	int	tmp_y;

	data->character_ichigo = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/character_ichigo.xpm", &tmp_x, &tmp_y);
	data->character_ichigo_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/character_ichigo_left.xpm", &tmp_x, &tmp_y);
	data->mywall = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/mywall.xpm", &tmp_x, &tmp_y);
	data->hollowmask = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/hollowmask.xpm", &tmp_x, &tmp_y);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/exit.xpm", &tmp_x, &tmp_y);
	data->background_map = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/background_map.xpm", &tmp_x, &tmp_y);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map2[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->mywall, x * UNIT, y * UNIT);
			else if (data->map2[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->hollowmask, x * UNIT, y * UNIT);
			else if (data->map2[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->exit, x * UNIT, y * UNIT);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->background_map, 0, 0);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
		data->character_ichigo, data->player_x * UNIT, data->player_y * UNIT);
	return (0);
}
