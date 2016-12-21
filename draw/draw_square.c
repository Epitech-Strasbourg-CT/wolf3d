/*
** draw_square.c for csfml.c in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:48:57 2016 Cédric Thomas
** Last update Wed Dec 21 15:28:06 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

int     draw_square(sfVector2i pos, sfVector2f size,
		      t_pixelbuff *buff, sfColor color)
{
  int   i;
  int   j;

  i = 0;
  if (pos.x + size.x > buff->x)
    return (-1);
  else if (pos.y + size.y > buff->y)
    return (-1);
  while (i < size.x)
    {
      j = 0;
      while (j < size.y)
	{
	  my_put_pixel(buff,  pos.x + i, pos.y + j, color);
	  j += 1;
	}
      i += 1;
    }
  return (1);
}
