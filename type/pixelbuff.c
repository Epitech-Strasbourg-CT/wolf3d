/*
** pixelbuff.c for mysf in /home/cedric/delivery/MUL/libmysf/type
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 22:08:40 2016 Cédric Thomas
** Last update Sun Dec 18 16:38:52 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include "wolf.h"

t_pixelbuff		*pixelbuff_create(int width, int height)
{
  int			i;
  t_pixelbuff		*buffer;

  buffer = malloc(sizeof(t_pixelbuff));
  if (buffer == NULL)
    return (NULL);
  buffer->pixels = malloc(width * height * 4 * sizeof(buffer->pixels));
  if (buffer->pixels == NULL)
    return (NULL);
  i = 0;
  while (i < (width * height * 4))
    {
      buffer->pixels[i] = 0;
      i += 1;
    }
  buffer->y = height;
  buffer->x = width;
  return (buffer);
}

void    free_pixelbuff(t_pixelbuff *buffer)
{
  free(buffer->pixels);
  free(buffer);
}

void	clean_buff(t_pixelbuff **buff)
{
  int   i;

  i = 0;
  while (i < (*buff)->x * (*buff)->y * 4)
    {
      (*buff)->pixels[i] = 0;
      i += 1;
    }
}
