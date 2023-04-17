#include "cub3d.h"

int main()
{
	t_info info;
	get_map("map.cub", &info);

	info.mlx = mlx_init();
	info.posX = 11.0;
	info.posY = 27.0;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;

	info.moveSpeed = 0.15;
	info.rotSpeed = 0.1;
	for(int i = 0; i < HEIGHT; i ++)
	{
		for(int j = 0; j < WIDTH; j ++)
			info.buf[i][j] = 1;
	}
	//texture을 불러와 2차원배열 형태로 저장함
	load_texture(&info);

	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "mlx");
	info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, 17, 0, redcross, NULL);
	mlx_loop(info.mlx);
}
