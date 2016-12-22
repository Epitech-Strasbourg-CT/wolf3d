/*
** disp_game.c for disp_game.c in /home/cedric/delivery/MUL/proj_wolf/wolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 20 22:22:54 2016 Cédric Thomas
** Last update Thu Dec 22 16:00:33 2016 Cédric Thomas
*/
#include <math.h>
#include <SFML/Graphics.h>
#include "wolf.h"

void		draw_coldeg(t_pixelbuff *buff, sfVector2i point,
			    int len, sfColor col)
{
  int		i;
  sfColor	deg;

  i = -1;
  while (++i < len)
    {
      deg = col;
      deg.a = col.a - col.a * i / len;
      my_put_pixel(buff, point.x, point.y + i, deg);
    }
}

void	draw_col(t_pixelbuff *buff, sfVector2i point, int len, sfColor color)
{
  int	i;

  i = -1;
  while (++i < len)
    my_put_pixel(buff, point.x, point.y + i, color);
}

void	draw_background(t_pixelbuff *buff)
{
  int	i;

  i = 0;
  while (i < WIDTH)
    {
      draw_col(buff, myvector2i(i, 0), HEIGHT / 2, mycolor(255, 52, 152, 219));
      draw_coldeg(buff, myvector2i(i, HEIGHT / 2), HEIGHT / 2, sfBlack);
      i += 1;
    }
}

void		draw_wall(t_map *m, t_player *p, t_pixelbuff *buff)
{
  int		last;
  int		k;
  t_cast	info;
  float		distfov;
  sfColor	color;

  k = -1;
  last = 0;
  distfov = (float)(p->fov / WIDTH);
  while (++k <= WIDTH)
    {
      color = mycolor(255, 235, 149, 50);
      info = adv_raycast(*p, *m, (k * distfov) - p->fov / 2 + p->angle);
      info.dist *= 1 / CASELEN * cosd((-1 * p->fov / 2) + k * distfov);
      if (info.impact == 1)
	color.a = 235;
      if (last != info.impact)
	color.a = 0;
      last = info.impact;
      info.dist = (!info.dist ? HEIGHT : HEIGHT / info.dist);
      draw_col(buff, myvector2i(WIDTH - k,
				HEIGHT / 2 - info.dist / 2), info.dist, color);
      my_put_pixel(buff, WIDTH - k,
		   HEIGHT / 2 - info.dist / 2, mycolor(0, 0, 0, 0));
    }
}

void	draw_game(t_map *m, t_player *p, t_pixelbuff *buff)
{
  draw_background(buff);
  draw_wall(m, p, buff);
}
