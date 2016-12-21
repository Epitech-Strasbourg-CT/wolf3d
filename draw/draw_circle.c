/*
** draw_circle.c for circle in /home/cedric/delivery/MUL/proj_wolf/wolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sun Dec 18 20:02:03 2016 Cédric Thomas
** Last update Wed Dec 21 15:28:26 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

float norm(sfVector2f vec)
{
  return (sqrt(pow(vec.x, 2) + pow(vec.y, 2)));
}

int     draw_circle(sfVector2i pos, int rayon,
		    t_pixelbuff *buff, sfColor color)
{
  int   i;
  int   j;

  i = 0;
  if (pos.x - rayon < 0 || pos.x + rayon > buff->x - 1)
    return (-1);
  else   if (pos.y - rayon < 0 || pos.y + rayon > buff->y - 1)
    return (-1);
  while (i < rayon * 2)
    {
      j = 0;
      while (j < rayon * 2)
	{
	  if (norm(myvector2f(i - rayon, j - rayon)) <= rayon)
	    my_put_pixel(buff,  pos.x - rayon + i, pos.y - rayon + j, color);
	  j += 1;
	}
      i += 1;
    }
  return (1);
}
