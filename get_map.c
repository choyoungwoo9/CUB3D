#include "cub3d.h"

//파싱시 지켜야 할 것들
//.cub형식
//0 1 N S E W만 맵에 들어올 수 있음
//맵은 1로 둘러써여야 함
//맵은 마지막에 와야 함
//요소의 각 타입은 순서가 상관없음
//요소에서 스페이스 하나 혹은 여러개로 요소 구분되어있음
//맵에서 space는 유효한 부분
//요소들의 첫번재는 식별자임
//NO So WE EA F C (RGB 0~255)
//에러 있을 시 Error\n출력후 종료

//다 받아가지고 str으로 나누고, split으로 개행을 기준으로 나누어 사용
//맵 나오는 부분 이전까지 찾아서 나눔
//시작이 1 이나 스페이스인 부분 -> 맵

void get_map(char *map_path, t_info *info)
{
	int fd = open(map_path, O_RDONLY);
	
	int i = 0;
	// while(1)
	// {
	// char *str;
	// }
	// while(1)
	// {
	// 	char *str;
	// }
	// i = 0;
	while(1)
	{
		char *str = get_next_line(fd);
		printf("%d : %s\n", i, str);
		info->map.map[i++] = str;
		if(str == NULL)
			break;
	}
	close(fd);
}