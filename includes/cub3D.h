#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <math.h>

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_L			123
# define KEY_R			124

# define EA		0
# define WE		1
# define SO		2
# define NO		3

# define STEP	0.5
# define THETA	30
# define PI		3.14159265359
# define WALL_X	0
# define WALL_Y 1
# define WALLDIST	1.1
# define TEX_W	64
# define TEX_H	64

typedef struct s_node {
	int				*content;
	struct s_node	*next;
}			t_node;

typedef struct s_queue {
	t_node	*front;
	t_node	*back;
}			t_queue;

typedef struct key_interrupt {
	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;
}

typedef struct s_texture {
	int		**buffer;
	char	*walls[4];
	int		*walls_img[4];
	char	*item;
	int		*item_img;
	int		floor;
	int		ceil;

	int		*data;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
}			t_texture;

typedef struct s_dis_size {
	int	width;
	int	height;
}			t_dis_size;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;

}			t_player;

typedef struct s_ray {
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		start;
	int		end;
	int		line;
	int		tex_x;
	int		tex_y;
	double	ratio;
	double	texpos;

}			t_ray;

typedef struct s_map_info {
	t_dis_size	dis_size;
	t_texture	texture;
	t_player	player;
	t_ray		ray;
	void		*mlx;
	void		*win;
	int			*widths;
	int			height;
	char		**map;
	char		*map_line;
}			t_map_info;

//		utils

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		*new_arr(int a, int b);
char	*ft_strdup_except_nl(const char *s);

//		parse

void	init_map_info(t_map_info *map_info, int fd);
char	**ft_split(char const *s, char c);
char	**ft_split_nl(char const *s, char c);

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
void	*ft_memset(void *s, int c, size_t n);

//		parse_config
void	parse_dis_size(t_map_info *map_info, char *line, int idx);
void	parse_walls(t_texture *texture, int wall_type, char *line, int idx);
void	parse_F(t_map_info *map_info, char *line, int idx);
void	parse_C(t_map_info *map_info, char *line, int idx);
void	parse_S(t_map_info *map_info, char *line, int idx);

//		check_map

void	check_map(t_map_info *map_info);
int		q_empty(t_queue *q);
void	q_append(t_queue *q, int *e);
int*	q_pop(t_queue *q);
void	q_clear(t_queue *q);

//		key_press

int		key_press(int keycode, t_map_info *map_info);
int		exit_game(t_map_info *map_info);

//		move

void	move_w(t_map_info *map_info, t_player *player);
void	move_a(t_map_info *map_info, t_player *player);
void	move_s(t_map_info *map_info, t_player *player);
void	move_d(t_map_info *map_info, t_player *player);

//		rotate

void	rotate_l(t_map_info *map_info, t_player *player);
void	rotate_r(t_map_info *map_info, t_player *player);

//		parse_player

void	parse_player(t_map_info *map_info);

//		draw

void	draw_updown(t_dis_size dis_size, t_texture *texture);
void	draw_img(t_map_info *map_info, t_dis_size dis_size, t_texture *texture);

//		ray_init

void	ray_init(t_ray *ray, t_player *player, t_dis_size dis_size, int x);

//		raycast

void	dda(t_map_info *map_info, t_ray *ray);
void	raycast(t_map_info *map_info, t_dis_size dis_size);

//		parse_img

void	parse_img(t_map_info *map_info, t_texture *texture);

#endif
