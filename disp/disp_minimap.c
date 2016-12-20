/*
** disp_minimap.c for minimap in /home/cedric/delivery/MUL/proj_wolf/wolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sun Dec 18 19:38:08 2016 Cédric Thomas
** Last update Tue Dec 20 20:58:03 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

void		draw_view(t_map *m, t_player *p, t_pixelbuff *buff, float side)
{
  float		i;
  float		dist;
  sfVector2i	view;
  sfVector2i	player;

  player = myvector2i(p->pos.x * side, p->pos.y * side);
  i = p->angle - p->fov / 2;
  while (i < p->angle + p->fov / 2)
    {
      dist = raycast(p->pos, i, m->map, m->size);
      view = myvector2i(player.x + cosd(i) * dist + 1,
			player.y - sind(i) * dist + 1);
      my_draw_line(buff, player, view, sfGreen);
      i += 0.1F;
    }
}

void		draw_player(t_map *m, t_player *p, t_pixelbuff *buff, float side)
{
  sfVector2i	player;

  player = myvector2i(p->pos.x * side, p->pos.y * side);
  draw_view(m, p, buff, side);
  draw_circle(player, side / 10, buff, sfRed);
}

void		draw_minimap(t_map *m, t_player *p, t_pixelbuff *buff)
{
  float		sq;
  sfColor	color;
  int		i;
  int		j;

  sq = CASELEN;
  i = 0;
  while (i < m->size.y)
    {
      j = 0;
      while (j < m->size.x)
	{
	  if (!m->map[i][j])
	    color = sfWhite;
	  else
	    color = sfBlue;
	  draw_square(myvector2i(j * sq, i * sq), myvector2i(sq, sq), buff, color);
	  j += 1;
	}
      i += 1;
    }
  draw_player(m, p, buff, sq);
}
