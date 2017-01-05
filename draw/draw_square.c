/*
** draw_square.c for csfml.c in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:48:57 2016 Cédric Thomas
** Last update Mon Jan  2 14:30:26 2017 Cédric Thomas
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
