static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(
		game->window_pointer,
		event,
		mask,
		f,
		game);
}

int	main(void)
{
	char *relative_path = "../img/bg.xmp";
	int img_width;
	int img_height;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Create Image");
	void *image = mlx_xpm_file_to_image(mlx, relative_path, &img_width,
			&img_height);

	init_hook(game, 12, 32768, mini_maker);
	mlx_put_image_to_window(mlx, win, image, 10, 10);
	mlx_loop(mlx);
}