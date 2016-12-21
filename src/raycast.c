/*
** raycast.c for raycast.c in /home/cedric/delivery/MUL/proj_wolf/bwolf3d/src
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 13 09:58:00 2016 Cédric Thomas
** Last update Wed Dec 21 21:54:48 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

static float	get_hori(sfVector2f player, int **map,
			 sfVector2i size, float direction)
{
  sfVector2f	current_h;
  sfVector2f	step_h;
  sfVector2i	tab;

  if (cosd(direction) == 1 || cosd(direction) == -1)
    return (-1);
  current_h.y = (int)(player.y / CASELEN) * CASELEN - player.y;
  if (sind(direction) < 0)
    current_h.y = (CASELEN + current_h.y);
  current_h.x = -current_h.y / tand(direction);
  step_h.y = (sind(direction) >= 0 ? -CASELEN : CASELEN);
  step_h.x = -step_h.y / tand(direction);
  tab.x = (current_h.x + player.x) / CASELEN;
  tab.y = (current_h.y + player.y + step_h.y / 10) / CASELEN;
  while (tab.x >= 0 && tab.x < size.x && tab.y >= 0 &&
	 tab.y < size.y && map[tab.y][tab.x] != 1)
    {
      current_h.x += step_h.x;
      current_h.y += step_h.y;
      tab.x = (current_h.x + player.x) / CASELEN;
      tab.y = (current_h.y + player.y + step_h.y / 10) / CASELEN;
      }
  return (sqrt(current_h.x * current_h.x + current_h.y * current_h.y));
}

static float	get_vert(sfVector2f player, int **map,
			 sfVector2i size, float direction)
{
  sfVector2f	current_v;
  sfVector2f	step_v;
  sfVector2i	tab;

  if (sind(direction) == 1 || sind(direction) == -1)
    return (-1);
  current_v.x = (int)(player.x / CASELEN) * CASELEN - player.x;
  if (cosd(direction) >= 0)
    current_v.x = CASELEN + current_v.x;
  current_v.y = -current_v.x * tand(direction);
  step_v.x = (cosd(direction) >= 0 ? CASELEN : -CASELEN);
  step_v.y = -step_v.x * tand(direction);
  tab.x = (current_v.x + player.x + step_v.x / 10) / CASELEN;
  tab.y = (current_v.y + player.y) / CASELEN;
  while (tab.x >= 0 && tab.x < size.x && tab.y >= 0 &&
  	 tab.y < size.y && map[tab.y][tab.x] != 1)
    {
      current_v.x += step_v.x;
      current_v.y += step_v.y;
      tab.x = (current_v.x + player.x + step_v.x / 10) / CASELEN;
      tab.y = (current_v.y + player.y) / CASELEN;
    }
  return (sqrt(current_v.x * current_v.x + current_v.y * current_v.y));
}

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i size)
{
  float		lenhori;
  float		lenvert;

  pos.x *= CASELEN;
  pos.y *= CASELEN;
  lenhori = get_hori(pos, map, size, direction);
  lenvert = get_vert(pos, map, size, direction);
  if (lenvert < 0 && lenhori)
    return (lenhori);
  else if (lenhori < 0 && lenvert)
    return (lenvert);
  if (lenvert <= lenhori)
    return (lenvert);
  else if (lenhori <= lenvert)
    return (lenhori);
  else
    return (0);
}

t_cast		adv_raycast(t_player p, t_map m, float angle)
{
  t_cast	my_cast;
  float		lenhori;
  float		lenvert;

  p.pos.x *= CASELEN;
  p.pos.y *= CASELEN;
  lenhori = get_hori(p.pos, m.map, m.size, angle);
  lenvert = get_vert(p.pos, m.map, m.size, angle);
  if (lenvert <= lenhori)
    my_cast.dist = lenvert;
  else if (lenhori <= lenvert)
    my_cast.dist = lenhori;
  else
    my_cast.dist = 0;
  if (lenvert < 0 && lenhori)
    my_cast.dist = lenhori;
  else if (lenhori < 0 && lenvert)
    my_cast.dist = lenvert;
  if (my_cast.dist == lenhori)
    my_cast.impact = 0;
  else if (my_cast.dist == lenvert)
    my_cast.impact = 1;
  else if (my_cast.dist == 0)
    my_cast.impact = 3;
  return (my_cast);
}
