/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:11:55 by beeren            #+#    #+#             */
/*   Updated: 2023/09/12 12:59:40 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>

# define UNIT 82

typedef struct c_data {
	char			*map;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*character_ichigo;
	void			*character_ichigo_left;
	void			*enemy;
	int				x;
	int				y;
	int				player_x;
	int				player_y;
	void			*background_map;
	void			*hollowmask;
	void			*mywall;
	void			*exit;
	int				map_width;
	int				map_height;
	char			*line;
	char			**map2;
	int				hollow_counter;
	unsigned int	moves;
	int				exit_is_possible;
	int				ply;
	int				exitt;
	int				enemy_x;
	int				enemy_y;
	int				i;
	int				j;
}	t_data;

void	render_map(t_data *data);
void	free_map(char **map2, size_t height);
int		game_exit(t_data *data);
int		render(t_data *data);
int		key_down(int keycode, t_data *data);
void	start_data(char *map_name);
int		key_up(int keycode, t_data *data);
char	**map_constractor(t_data *data, int fd);
char	*ft_itoa(int number);
void	ft_reset(char *buffer);
void	load_xpm(t_data *data);
int		flood_fill(t_data *data);
int		map_validation(t_data *data);
int		ft_strlen(char *str);
int		enemymove(t_data *data);
int		anim_e(t_data *data);

#endif