/*
** disp_game.c for disp_game.c in /home/cedric/delivery/MUL/proj_wolf/wolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 20 22:22:54 2016 Cédric Thomas
** Last update Fri Dec 23 10:42:35 2016 Cédric Thomas
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

void	draw_game(t_map *m, t_player *p, t_pixelbuff *buff)
{
  draw_background(buff);
  draw_wall(m, p, buff);
}
