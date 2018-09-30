/*
mlx_do_key_autorepeatoff(env->mlx_init); --->  to switch off autorepeat (just 1 event for keypress and keyrelease)
mlx_loop_hook(env->mlx_init, loop_hook, env); ---> the given function will be called when no event occurs
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param); ---> the given function will be called when event occurs. The event and mask values will be taken from the X11 include file "X.h": x_event set as 2 and funct set as an int key_press(int keycode, void *param) for a key press 
mlx_hook(env->window, KEY_PRESS, KEY_PRESS_MASK, key_hook, env); ---> the given function will be called when event occurs
*/

#include "../includes/wolf3d.h"

void	event(t_env *env)
{
	mlx_do_key_autorepeatoff(env->mlx.mlx_init);
	mlx_loop_hook(env->mlx.mlx_init, loop_hook, env);
	mlx_hook(env->mlx.window, KEY_PRESS, KEY_PRESS_MASK, key_hook, env);
	// mlx_hook(env->mlx.window, CLOSE_PRGRM, CLOSE_PRGRM_MASK, close_program, env);
	mlx_key_hook(env->mlx.window, key_hook, env);
}