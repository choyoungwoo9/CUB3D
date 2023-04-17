#include "cub3d.h"

//벽에 충돌했을떄 벽 뚫려 보이는 문제
//처음 시작할때도 마찬가지

void set_start_direction(char direction, t_info *info)
{
	if(direction == 'N')
	{
		info->dirX = -1.0;
		info->dirY = 0.0;
		info->planeX = 0.0;
		info->planeY = 0.66;
	}
	if(direction == 'S')
	{
		info->dirX = 1.0;
		info->dirY = 0.0;
		info->planeX = 0.0;
		info->planeY = -0.66;
	}
	if(direction == 'W')
	{
		info->dirX = 0.0;
		info->dirY = 1.0;
		info->planeX = 0.66;
		info->planeY = 0.0;
	}
	if(direction == 'E')
	{
		info->dirX = 0.0;
		info->dirY = -1.0;
		info->planeX = -0.66;
		info->planeY = 0.0;
	}
}

int main(int argc, char **argv)
{
	if(argc != 2)
		my_error();
	t_info info;
	get_file(argv[1], &info);

	info.mlx = mlx_init();
	//사용자의 방향 N S W E에 따라 아래 값 다르게 해 처음 처다보는 방향 다르게 함
	set_start_direction(info.map.start_direction, &info);

	info.moveSpeed = 0.15;
	info.rotSpeed = 0.1;
	for(int i = 0; i < HEIGHT; i ++)
	{
		for(int j = 0; j < WIDTH; j ++)
			info.buf[i][j] = 0;
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
