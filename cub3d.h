#ifndef CUB3D_H
#define CUB3D_H

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

char	*worldMap[22];


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
	int		lineHeight;//벽의 높이
	int		wallStart;//벽의 시작점과 끝점
	int		wallEnd;
	int		texNum;//텍스쳐
	double	wallX;//벽의 X축부터 광선이 부딪힌 곳의 거리
	int		texX;//텍스쳐끝에서 광선까지의 픽셀 거리
	int		texY;
	double	texPos;//텍스쳐에서 어떤 색상을 가져올지에 대한 y좌표
	double	step;//텍스쳐의 원래 크기를 실제 벽의 크기로 나눈 값
}	t_camera;

typedef struct s_element
{
	char *east_path;
	char *west_path;
	char *south_path;
	char *north_path;
	int floor_color[3];
	int ceil_color[3];
}	t_element;

typedef struct s_map
{
	char **map;
	int start_x;
	int start_y;
}	t_map;

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
	t_element element;
	t_map map;
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

int main_loop(t_info *info);
int key_press(int key, t_info *info);
int redcross(int key_code, void *data);
void	set_camera(t_info *info, t_camera *cam, int x);
void	draw_camera(t_info *info, t_camera *cam, int x);
void load_texture(t_info *info);
void get_map(char *map_path);

#endif