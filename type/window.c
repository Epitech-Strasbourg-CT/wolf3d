/*
** window.c for mysf in /home/cedric/delivery/MUL/libmysf/type
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:59:55 2016 Cédric Thomas
** Last update Wed Dec 21 15:36:48 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include "wolf.h"

sfRenderWindow          *window_create(char *n, int w, int h)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = w;
  mode.height = h;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, n, sfResize | sfClose, NULL);
  return (window);
}

t_image		t_image_create(double x, double y)
{
  t_image	image;

  image.spri = sfSprite_create();
  image.tex = sfTexture_create(x, y);
  sfSprite_setTexture(image.spri, image.tex, sfTrue);
  return (image);
}
