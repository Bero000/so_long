/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:12:33 by beeren            #+#    #+#             */
/*   Updated: 2023/09/12 13:19:57 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include <unistd.h>
#include <fcntl.h>

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return (0);
	}
	write(1, "ERRORfilename_check\n", 20);
	return (1);
}

static t_data	*game_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->hollow_counter = 0; 
	data->exitt = 0;
	data->ply = 0;
	data->moves = 0;
	return (data);
}

void	start_data(char *map_name)
{
	t_data	*data;
	int		fd;

	if (filename_check(map_name))
		return ;
	data = game_init();
	fd = open(map_name, O_RDONLY);
	data->map2 = map_constractor(data, fd);
	close(fd);
	if (map_validation(data))
	{
		write(1, "ERRORmap_validation\n", 20);
		free_map(data->map2, data->map_height);
		free(data);
		exit(1);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 
			UNIT * 15, UNIT * 10, "SoLong");
	load_xpm(data);
	mlx_hook(data->win_ptr, 2, 0, key_down, data);
	mlx_hook(data->win_ptr, 17, 0, game_exit, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop (data->mlx_ptr);
}
