/*
** disp.c for disp in /home/cedric/delivery/MUL/proj_wolf/wolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sun Dec 18 18:21:41 2016 Cédric Thomas
** Last update Tue Dec 20 21:52:08 2016 Cédric Thomas
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "wolf.h"
#include "my.h"

static int      checkevent(sfRenderWindow *window,
			   sfEvent *event, t_map *m, t_player *p)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    sfRenderWindow_close(window);
  if (sfKeyboard_isKeyPressed(sfKeyZ) && p->distu > 7.5 / 100.0 * CASELEN)
    add_vec(&(p->pos), 3.0 / CASELEN, p->angle);
  if (sfKeyboard_isKeyPressed(sfKeyS) && p->distd > 7.5 / 100.0 * CASELEN)
    add_vec(&(p->pos), 3.0 / CASELEN, p->angle + 180);  
  if (sfKeyboard_isKeyPressed(sfKeyQ) && p->distl > 7.5 / 100.0 * CASELEN)
    add_vec(&(p->pos), 3.0 / CASELEN, p->angle + 90);
  if (sfKeyboard_isKeyPressed(sfKeyD) && p->distr > 7.5 / 100.0 * CASELEN)
    add_vec(&(p->pos), 3.0 / CASELEN, p->angle - 90);
  if (sfKeyboard_isKeyPressed(sfKeyA))
    p->angle += 2;
  if (sfKeyboard_isKeyPressed(sfKeyE))
    p->angle -= 2;
  return (1);
}

static	void	update_player(t_pixelbuff *buff, t_map *m, t_player *p)
{
  p->distu = raycast(p->pos, p->angle, m->map, m->size);
  p->distd = raycast(p->pos, p->angle + 180, m->map, m->size);
  p->distl = raycast(p->pos, p->angle + 90, m->map, m->size);
  p->distr = raycast(p->pos, p->angle - 90, m->map, m->size);
}

static int	draw_this(t_map *m, t_player *p, t_pixelbuff *buff)
{
  clean_buff(&buff);
  update_player(buff, m, p);
  draw_minimap(m, p, buff);
  return (1);
}

static void	init_player(t_player *p)
{
  p->angle = 0;
  p->fov = FOV;
}

int		play(t_map *m, t_player *p)
{ 
  sfRenderWindow        *window;
  sfEvent               event;
  t_image               image;
  t_pixelbuff           *buff;

  window = window_create("Wolf", WIDTH, HEIGHT);
  image = t_image_create(WIDTH, HEIGHT);
  buff = pixelbuff_create(WIDTH, HEIGHT);
  draw_this(m, p, buff);
  init_player(p);
  sfTexture_updateFromPixels(image.tex, buff->pixels, WIDTH, HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      if (checkevent(window, &event, m, p))
	{
	  draw_this(m, p, buff);
	  sfTexture_updateFromPixels(image.tex, buff->pixels, WIDTH, HEIGHT, 0, 0);
	}
      sfRenderWindow_drawSprite(window, image.spri, NULL);
      sfRenderWindow_display(window);
      sfRenderWindow_clear(window, sfBlack);
    }
  sfRenderWindow_destroy(window);
  free_pixelbuff(buff);
}
