/*
** raycast.c for raycast.c in /home/cedric/delivery/MUL/proj_wolf/bwolf3d/src
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 13 09:58:00 2016 Cédric Thomas
** Last update Mon Dec 19 20:01:25 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

static float	get_hori(sfVector2f player, int **map, sfVector2i size, float direction)
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

static float	get_vert(sfVector2f player, int **map, sfVector2i size, float direction)
{
  sfVector2f	current_v;
  sfVector2f	step_v;

  if (sind(direction) == 1 || sind(direction) == -1)
    return (-1);
  if (cosd(direction) < 0)
    current_v.x = (int)(player.x / CASELEN) * CASELEN;
  else
    current_v.x = (int)(player.x / CASELEN) * CASELEN + CASELEN;
  step_v.x = CASELEN * (cosd(direction) < 0 ? -1 : 1);
  current_v.y = player.y + (player.x - current_v.x) * tand(direction);
  step_v.y = -step_v.x * tand(direction);
  while((int)(current_v.x + step_v.x / 2)/ CASELEN >= 0 && (int)current_v.y / CASELEN >= 0
  	&& (int)(current_v.x + step_v.x / 2)/ CASELEN < size.x && (int)current_v.y / CASELEN < size.y
  	&& map[(int)current_v.y / CASELEN][(int)(current_v.x + step_v.x / 2) / CASELEN] != 1)
    {
      current_v.x += step_v.x;
      current_v.y += step_v.y;
    }
  current_v.x =   current_v.x - player.x;
  current_v.y = current_v.y - player.y;
  return (sqrt(current_v.x * current_v.x + current_v.y * current_v.y));
}

float		raycast(sfVector2f pos, float direction, int **map, sfVector2i size)
{
  float		lenhori;
  float		lenvert;

  pos.x *= 64;
  pos.y *= 64;
  //  lenhori = get_hori(pos, map, size, direction);
  lenvert = get_vert(pos, map, size, direction);
  /* if (lenvert < 0 && lenhori) */
  /*   return (lenhori); */
  /* else if (lenhori < 0 && lenvert) */
  /*   return (lenvert); */
  /* if (lenvert <= lenhori) */
  return (lenvert);
  /* else */
  /* if (lenhori) */
  /*    return (lenhori); */
  /*  else */
  /*   return (0); */
}

