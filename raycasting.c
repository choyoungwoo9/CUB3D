#include "cub3d.h"

static void draw(t_info *info)
{
	for(int y = 0; y < HEIGHT; y ++)
	{
		for(int x = 0; x < WIDTH; x ++)
			info->img.data[y * WIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static void	floor_ceiling(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 480)
	{
		while (j < 640)
		{
			if(i < 240)
				info->buf[i][j] = (255 << 8);
			else
				info->buf[i][j] = 255;
			j++;
		}
		i++;
	}
}

static void cal_raycasting(t_info *info)
{
	t_camera	cam;
	int			x;

	x = 0;
	floor_ceiling(info);
	while (x < WIDTH)
	{
		set_camera(info, &cam, x);
		draw_camera(info, &cam, x);
		x++;
	}
}

int main_loop(t_info *info)
{
	cal_raycasting(info);
	draw(info);
	return 0;
}
