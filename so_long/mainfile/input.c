/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:51:14 by beeren            #+#    #+#             */
/*   Updated: 2023/09/12 13:06:52 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include <unistd.h>

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

static void	ft_unsigned(unsigned int a)
{
	if (a >= 10)
		ft_unsigned(a / 10);
	write(1, &"0123456789"[a % 10], 1);
}

static int	player_register_event(int movement, t_data *data)
{
	if (!movement)
		return (0);
	if (data->map2[data->player_y][data->player_x] == 'C')
	{
		data->map2[data->player_y][data->player_x] = '0';
		data->hollow_counter--;
	}
	if (data->hollow_counter == 0 
		&& data->map2[data->player_y][data->player_x] == 'E')
		game_exit(data);
	data->moves++;
	ft_unsigned(data->moves);
	write(1, "\n", 1);
	return (0);
}

static int	player_register_movement(int key, t_data *data)
{
	if (key == KEY_W)
		data->player_y--;
	else if (key == KEY_A)
	{
		data->character_ichigo = mlx_xpm_file_to_image(data->mlx_ptr,
				"images/character_ichigo_left.xpm", &data->x, &data->y);
		data->player_x--;
	}
	else if (key == KEY_S)
		data->player_y++;
	else if (key == KEY_D)
	{
		data->character_ichigo = mlx_xpm_file_to_image(data->mlx_ptr,
				"images/character_ichigo.xpm", &data->x, &data->y);
		data->player_x++;
	}
	return (1);
}

int	key_down(int keycode, t_data *data)
{
	int	movement;

	movement = 0;
	if (keycode == KEY_ESC)
		game_exit(data);
	else if (keycode == KEY_W
		&&data->map2[data->player_y - 1][data->player_x] != '1')
		movement = player_register_movement(KEY_W, data);
	else if (keycode == KEY_S
		&& data->map2[data->player_y + 1][data->player_x] != '1')
		movement = player_register_movement(KEY_S, data);
	else if (keycode == KEY_A
		&& data->map2[data->player_y][data->player_x - 1] != '1')
		movement = player_register_movement(KEY_A, data);
	else if (keycode == KEY_D
		&& data->map2[data->player_y][data->player_x + 1] != '1')
		movement = player_register_movement(KEY_D, data);
	player_register_event(movement, data);
	return (0);
}

int	game_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map_height)
		free(data->map2[i]);
	free(data->map2);
	mlx_destroy_image(data->mlx_ptr, data->character_ichigo);
	mlx_destroy_image(data->mlx_ptr, data->character_ichigo_left);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->hollowmask);
	mlx_destroy_image(data->mlx_ptr, data->mywall);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(0);
}
