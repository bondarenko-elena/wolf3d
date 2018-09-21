#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <time.h>

// size of screen
# define WIDTH 800
# define HEIGHT 600

// ESC: for MAC OS key_code == 53; for Debian key_code == 65307
# define KEY_ESC 65307
// W: for MAC OS key_code == 13; for Debian key_code == 119
# define KEY_UP 119
// S: for MAC OS key_code == 1; for Debian key_code == 115
# define KEY_DOWN 115
// A: for MAC OS key_code == 0; for Debian key_code == 97
# define KEY_LEFT 97
// D: for MAC OS key_code == 2; for Debian key_code == 100
# define KEY_RIGHT 100
// SPACE: for MAC OS key_code == 49; for Debian key_code == 32
# define KEY_JUMP 32
////////////////////////////////////////////////////////////////
// UP: for MAC OS key_code == 126; for Debian key_code == 65362
# define ARROW_UP 65362
// DOWN: for MAC OS key_code == 125; for Debian key_code == 65364
# define ARROW_DOWN 65364
// LEFT: for MAC OS key_code == 123; for Debian key_code == 65361
# define ARROW_LEFT 65361
// RIGHT: for MAC OS key_code == 124; for Debian key_code == 65363
# define ARROW_RIGHT 65363
////////////////////////////////////////////////////////////////






// for int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
// x_mask is ignored on macos
# define KEY_PRESS_MASK (1L<<0)
// x_event set as 2 and funct set as an int key_press(int keycode, void *param) for a key press
# define KEY_PRESS 2

typedef struct		s_i_xy
{
	int				x;
	int				y;
}					t_i_xy;

typedef struct		s_dir_xy
{
	double			x;
	double			y;
}					t_dir_xy;

typedef struct		s_player
{
	struct s_dir_xy	position;
	struct s_dir_xy	direction;
	struct s_dir_xy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_ray
{
	struct s_dir_xy	position;
	struct s_dir_xy	direction;
	struct s_i_xy	map;
	struct s_dir_xy	side;
	struct s_dir_xy	delta;
	struct s_i_xy	step;
	double			distance;
	double			camera;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx_init;
	void			*window;
	void			*image;
	char			*pixel;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	clock_t			last_frame;
	clock_t			next_frame;
}					t_mlx;

typedef struct		s_env
{
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	int				start_x;
	int				start_y;
}					t_env;

int					main(int argc, char **argv);
int 				check_file(char *filename);
t_env				*init_env(void);
void				init_player(t_env *e);
int					open_file(t_env *e, char *filename);
int					read_file(int fd, t_env *e);
void				read_line(char *line, int y, int **map, t_env *e);
void				get_position(int fd, t_env *e);
void				map_error(void);
void				event(t_env *env);
void				malloc_error(void);
int					loop_hook(t_env *env);
int					key_hook(int k, t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_jump(t_env *e);
void				ray_casting(t_env *env);
void				ray_draw(t_env *env, int x);
void				ray_calculate_distance(t_env *env);
void				ray_calculate_step_side(t_env *env);
void				ray_init(t_env *env, int x);
void				draw_line(t_env *e, int x, int start, int end);
void				put_pixel(t_env *env, int x, int y, unsigned int c);
unsigned int		get_color(t_env *env);
unsigned int		add_smog(unsigned int c, double d);


#endif
