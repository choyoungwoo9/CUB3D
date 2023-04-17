#include "cub3d.h"

static void draw_texture(t_info *info, t_camera *cam, int x)
{
	int	color;

	if (cam->side == 0)
		cam->wallX = info->posY + cam->perWallDist * cam->rayDirY;
	else
		cam->wallX = info->posX + cam->perWallDist * cam->rayDirX;
	cam->wallX -= floor(cam->wallX);
	cam->texX = (int)(cam->wallX * (double)TEXWIDTH);
	if (cam->side == 0 && cam->rayDirX > 0)
		cam->texX = TEXWIDTH - cam->texX - 1;
	if (cam->side == 1 && cam->rayDirY < 0)
		cam->texX = TEXWIDTH - cam->texX - 1;
	cam->step = 1.0 * TEXHEIGHT / cam->lineHeight;
	cam->texPos = (cam->wallStart - HEIGHT / 2 + cam->lineHeight / 2) * cam->step;
	while (cam->wallStart < cam->wallEnd)
	{
		cam->texY = (int)cam->texPos & (TEXHEIGHT - 1);
		cam->texPos += cam->step;
		color = info->texture[cam->texNum][cam->texY][cam->texX];
		info->buf[cam->wallStart][x] = color;
		cam->wallStart++;
	}
}

static void	sel_texture(t_camera *cam)
{
	cam->texNum = 0;
	if (cam->side == 0)
	{
		if (cam->rayDirX < 0)
			cam->texNum = 2;
		else
			cam->texNum = 3;
	}
	else
	{
		if (cam->rayDirY < 0)
			cam->texNum = 0;
		else
			cam->texNum = 1;
	}
}

static void	set_wallpos(t_camera *cam)
{
	cam->lineHeight = (int)(HEIGHT / cam->perWallDist);
	cam->wallStart = -cam->lineHeight / 2 + HEIGHT / 2;
	if (cam->wallStart < 0)
		cam->wallStart = 0;
	cam->wallEnd = cam->lineHeight / 2 + HEIGHT / 2;
	if (cam->wallEnd >= HEIGHT)
		cam->wallEnd = HEIGHT - 1;
}

void	draw_camera(t_info *info, t_camera *cam, int x)
{
	set_wallpos(cam);
	sel_texture(cam);
	draw_texture(info, cam, x);
}
