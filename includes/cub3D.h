#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

# define KEY_RELEASE	3
# define KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define EA		0
# define WE		1
# define SO		2
# define NO		3

typedef struct s_texture {
	char	*walls[4];
	char	*item;
	int		floor[3];
	int		ceil[3];
}			t_texture;

typedef struct s_dis_size {
	int	width;
	int	height;
}			t_dis_size;

typedef struct player {
	int	x;
	int	y;
}			t_player;

typedef struct s_map_info {
	t_dis_size	dis_size;
	t_texture	texture;
	t_player	player;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	char	*map_line;
}			t_map_info;

//		utils

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//		parse

void	init_map_info(t_map_info *map_info, int fd);
char	**ft_split(char const *s, char c);

//		check & error

void	check_arg(int argc, char **argv);
void	check_fd(int fd);
void	exit_error(char *msg);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);


//		memory_utils

void	free_arr_2(char **arr);
void	free_arr(char *arr);

//		parse_utils

int		is_space(char c);
int		count_arr_2(char **arr);

//		parse_config
void	parse_dis_size(char *line, t_map_info *map_info);
void	parse_walls(t_texture *texture, int wall_type, char *line);
void	parse_F(t_map_info *map_info, char *line);
void	parse_C(t_map_info *map_info, char *line);
void	parse_S(t_map_info *map_info, char *line);

//		check_map

void	check_map(t_map_info *map_info);



#endif