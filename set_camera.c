#include "cub3d.h"

static void	find_wall(t_info *info, t_camera *cam)
{
	(void)info;
	while (cam->hit == 0)// 처음 만나는 벽을 찾을때까지 계속 이동하면서 찾음
	{
		if (cam->sideDistX < cam->sideDistY)
		{
			cam->sideDistX += cam->deltaDistX;
			cam->mapX += cam->stepX;
			cam->side = 0;
		}
		else
		{
			cam->sideDistY += cam->deltaDistY;
			cam->mapY += cam->stepY;
			cam->side = 1;
		}
		if (worldMap[cam->mapX][cam->mapY] == '1')
			cam->hit = 1;
	}
}

static void	set_direction(t_info *info, t_camera *cam)
{
	if (cam->rayDirX < 0)
	{
		cam->stepX = -1;
		cam->sideDistX = (info->posX - cam->mapX) * cam->deltaDistX;
	}
	else
	{
		cam->stepX = 1;
		cam->sideDistX = (cam->mapX + 1.0 - info->posX) * cam->deltaDistX;
	}
	if (cam->rayDirY < 0)
	{
		cam->stepY = -1;
		cam->sideDistY = (info->posY - cam->mapY) * cam->deltaDistY;
	}
	else
	{
		cam->stepY = 1;
		cam->sideDistY = (cam->mapY + 1.0 - info->posY) * cam->deltaDistY;
	}
}

void	set_camera(t_info *info, t_camera *cam, int x)
{
	cam->cameraX = 2 * x / (double)width - 1;
	cam->rayDirX = info->dirX + info->planeX * cam->cameraX;
	cam->rayDirY = info->dirY + info->planeY * cam->cameraX;
	cam->mapX = (int)info->posX;
	cam->mapY = (int)info->posY;
	cam->deltaDistX = fabs(1 / cam->rayDirX);
	cam->deltaDistY = fabs(1 / cam->rayDirY);
	cam->hit = 0;
	set_direction(info, cam);
	find_wall(info, cam);
	if (cam->side == 0)
		cam->perWallDist = (cam->mapX - info->posX + (1 - cam->stepX) / 2) / cam->rayDirX;
	else
		cam->perWallDist = (cam->mapY - info->posY + (1 - cam->stepY) / 2) / cam->rayDirY;
}
