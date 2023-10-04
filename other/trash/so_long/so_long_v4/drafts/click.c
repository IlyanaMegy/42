#include "mlx.h"
#include "stdlib.h"
#include <stdio.h>
#include "unistd.h"

typedef struct  s_program
{
    void *mlx;
    void *win;
}               t_program;

int mouse_event(int button, int x, int y, void *param)
{
    t_program *tutorial = param;
    
    mlx_pixel_put(tutorial->mlx, tutorial->win, 640/2, 360/2, 0xFFFFFF);
    printf("button : %d\nx : %d, y : %d\n", button, x, y);
    return (0);
}

int	main(void)
{
	void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Event Parameters");

	t_program tutorial;
    tutorial.mlx = mlx;
    tutorial.win = win;

    mlx_mouse_hook(win, &mouse_event, &tutorial);
	mlx_loop(mlx);
}