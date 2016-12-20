/*
** draw_pixel.c for draw_pixel.c in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:32:11 2016 Cédric Thomas
** Last update Sat Dec 17 18:29:37 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include "wolf.h"

void	my_put_pixel(t_framebuffer *buffer,
		     int x,
		     int y,
		     sfColor color)
{
  if (x >= 0 && y >= 0 && x < buffer->x && y < buffer->y)
    {
      buffer->pixels[(buffer->x * y + x) * 4] = color.r;
      buffer->pixels[(buffer->x * y + x) * 4 + 1] = color.g;
      buffer->pixels[(buffer->x * y + x) * 4 + 2] = color.b;
      buffer->pixels[(buffer->x * y + x) * 4 + 3] = color.a;
    }
}
