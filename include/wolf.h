/*
** wolf.h for wolf in /home/cedric/delivery/MUL/proj_wolf/bwolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 13 09:30:30 2016 Cédric Thomas
** Last update Tue Dec 20 21:52:23 2016 Cédric Thomas
*/
#ifndef WOLF_H_
# define WOLF_H_

#include <SFML/Graphics.h>

# define CASELEN 64.0
# define FOV 2
# define SCALE 2.0
# define WIDTH 1920
# define HEIGHT 1080

typedef struct		s_player
{
  float			angle;
  sfVector2f		pos;
  int			fov;
  float			distu;
  float			distd;
  float			distl;
  float			distr;
}			t_player;

typedef struct		s_framebuffer
{
  sfUint8		*pixels;
  int			x;
  int			y;
}			t_framebuffer;

typedef t_framebuffer t_pixelbuff;

typedef struct		s_image
{
  sfTexture             *tex;
  sfSprite              *spri;
}			t_image;

typedef struct          s_map
{
  sfVector2i		size;
  int			**map;
}                       t_map;

/*
**misc.c
*/
void	add_vec(sfVector2f *pos, float len, float alpha);

/*
**WOLF_DISP
*/

/*
**disp.c
*/
int	play(t_map *m, t_player *p);

/*
**disp_minimap.c
*/
void	draw_minimap(t_map *m,
		     t_player *p,
		     t_pixelbuff *buff);

/*
**WOLF_PARSE
*/

/*
**parse.c
*/
char	*my_read(char *path);

/*
**parse_wolf.c
*/
t_map	parse_wolf(char *path);

/*
**check.c
*/

/*
**WOLF_DRAW
*/
int	draw_square(sfVector2i pos, sfVector2i size,
		    t_pixelbuff *buff, sfColor color);
int	draw_circle(sfVector2i pos, int rayon,
		    t_pixelbuff *buff, sfColor color);

/*
**WOLF_TYPE
*/

/*
**pixelbuff.c
*/
t_pixelbuff	*pixelbuff_create(int width, int height);
void		free_pixelbuff(t_pixelbuff *buffer);
void		clean_buff(t_pixelbuff **buffer);

/*
**vector.c
*/
sfVector2f	myvector2f(double x, double y);
sfVector3f	myvector3f(double x, double y, double z);
sfVector2i	myvector2i(int x, int y);

/*
**window.c
*/
sfRenderWindow	*window_create(char *n, int w, int h);
t_image		t_image_create(double x, double y);

/*
**SRC
*/
void		my_put_pixel(t_pixelbuff *buffer,
			     int x,
			     int y,
			     sfColor color);
void		my_draw_line(t_pixelbuff *buff,
			     sfVector2i from,
			     sfVector2i to,
			     sfColor color);
float		raycast(sfVector2f pos,
			float direction,
			int **map,
			sfVector2i mapSize);
sfVector2f	move_forward(sfVector2f pos,
			     float direction,
			     float distance);
double		cosd(double angle);
double		sind(double angle);
double		tand(double angle);

#endif /* !WOLF_H_ */
