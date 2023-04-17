#ifndef CLONE
#define CLONE

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key_macos.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480

typedef struct s_camera
{
	double	cameraX;//평면카메라
	double	rayDirX;//카메라 방향벡터
	double	rayDirY;
	int		mapX;//플레이어 좌표 (부딪힌 벽의 좌표를 저장할 때 사용)
	int		mapY;
	double	sideDistX;//처음 만나는 벽의 거리
	double	sideDistY;
	double	deltaDistX;//다음 만나는 벽의 거리
	double	deltaDistY;
	double	perWallDist;//어안렌즈 현상 보정
	int		stepX;//벽이 있는지 검사 할 방향 (광선의 방향에 따라 이동방향(음or양)을 담음)
	int		stepY;
	int		hit;//벽에 부딪히면 1, 아니면 0 flag
	int		side;//y축에 수직이면 1(-), x축에 수직이면 0(ㅣ) flag
	int		texNum;
}	t_camera;

typedef struct s_img
{
	void *img;
	int *data;
	int size_l;
	int bpp;
	int endian;
	int img_width;
	int img_height;
}	t_img;

typedef struct s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void *mlx;
	void *win;
	t_img img;
	int buf[height][width];
	int texture[4][64][64];
	double moveSpeed;
	double rotSpeed;
}	t_info;

char	*worldMap[22];

void draw(t_info *info);
void calc(t_info *info);
int main_loop(t_info *info);
int key_press(int key, t_info *info);
int redcross(int key_code, void *data);
void get_map(char *map_path);
void load_image(t_info *info, int texture[][64], char *path, t_img *img);
void load_texture(t_info *info);

#endif