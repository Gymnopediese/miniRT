

#include "header.h"

int	up(int k, char *keys)
{
	keys[k] = 0;
	return (0);
}

int	down(int k, char *keys)
{
	keys[k] = 1;
	return (0);
}

int	hook(char *keys)
{
	if (keys[KEYCODE_A])
		;//...
	if (keys[KEYCODE_S])
		;//...
	if (keys[KEYCODE_D])
		;//...
	if (keys[KEYCODE_W])
		;//...
}

int	main()
{
	// a metre dans sa turbo struct
	char keys[200];
	void *mlx;
	void *win;

	ft_bzero(keys, 200);
	//...
	mlx_hook(win, 2, 0, down, keys);
	mlx_hook(win, 3, 0, up, keys);
	mlx_loop_hook(mlx, hook, keys);
}