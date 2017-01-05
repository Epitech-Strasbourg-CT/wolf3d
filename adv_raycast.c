/*
** raycast.c for raycast.c in /home/cedric/delivery/MUL/proj_wolf/bwolf3d/src
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 13 09:58:00 2016 Cédric Thomas
** Last update Mon Jan  2 16:45:47 2017 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

static t_cast	init_cast()
{
  t_cast	my_cast;

  my_cast.dist = 0;
  my_cast.disth = -1;
  my_cast.distv = -1;
  my_cast.impact = -1;
  my_cast.mcaseh.x = 0;
  my_cast.mcaseh.y = 0;
  my_cast.mcasev.x = 0;
  my_cast.mcasev.y = 0;
  return (my_cast);
}

static void	get_hori(sfVector2f player, t_map *m, float direction, t_cast *my_cast)
{
  sfVector2f	current_h;
  sfVector2f	step_h;
  sfVector2i	tab;

  if (cosd(direction) == 1 || cosd(direction) == -1)
    return ;
  current_h.y = (int)(player.y / CASELEN) * CASELEN - player.y;
  if (sind(direction) < 0)
    current_h.y = (CASELEN + current_h.y);
  current_h.x = -current_h.y / tand(direction);
  step_h.y = (sind(direction) >= 0 ? -CASELEN : CASELEN);
  step_h.x = -step_h.y / tand(direction);
  tab.x = (current_h.x + player.x) / CASELEN;
  tab.y = (current_h.y + player.y + step_h.y / 10) / CASELEN;
  while (tab.x >= 0 && tab.x < m->size.x && tab.y >= 0 &&
	 tab.y < m->size.y && m->map[tab.y][tab.x] != 1)
    {
      current_h.x += step_h.x;
      current_h.y += step_h.y;
      tab.x = (current_h.x + player.x) / CASELEN;
      tab.y = (current_h.y + player.y + step_h.y / 10) / CASELEN;
    }
  if (tab.x >= 0 && tab.x < m->size.x && tab.y >= 0 && tab.y < m->size.y)
    my_cast->mcaseh = myvector2i(tab.x, tab.y);
  my_cast->disth = sqrt(current_h.x * current_h.x + current_h.y * current_h.y);
}

static void	get_vert(sfVector2f player, t_map *m, float direction, t_cast *my_cast)
{
  sfVector2f	current_v;
  sfVector2f	step_v;
  sfVector2i	tab;

  if (sind(direction) == 1 || sind(direction) == -1)
    return ;
  current_v.x = (int)(player.x / CASELEN) * CASELEN - player.x;
  if (cosd(direction) >= 0)
    current_v.x = CASELEN + current_v.x;
  current_v.y = -current_v.x * tand(direction);
  step_v.x = (cosd(direction) >= 0 ? CASELEN : -CASELEN);
  step_v.y = -step_v.x * tand(direction);
  tab.x = (current_v.x + player.x + step_v.x / 10) / CASELEN;
  tab.y = (current_v.y + player.y) / CASELEN;
  while (tab.x >= 0 && tab.x < m->size.x && tab.y >= 0 &&
  	 tab.y < m->size.y && m->map[tab.y][tab.x] != 1)
    {
      current_v.x += step_v.x;
      current_v.y += step_v.y;
      tab.x = (current_v.x + player.x + step_v.x / 10) / CASELEN;
      tab.y = (current_v.y + player.y) / CASELEN;
    }
  if (tab.x >= 0 && tab.x < m->size.x && tab.y >= 0 && tab.y < m->size.y)
    my_cast->mcasev = myvector2i(tab.x, tab.y);
  my_cast->distv = sqrt(current_v.x * current_v.x + current_v.y * current_v.y);
}

t_cast		adv_raycast(t_player p, t_map m, float angle)
{
  t_cast	my_cast;

  p.pos.x *= CASELEN;
  p.pos.y *= CASELEN;
  my_cast = init_cast();
  get_hori(p.pos, &m, angle, &my_cast);
  get_vert(p.pos, &m, angle, &my_cast);
  if (my_cast.distv <= my_cast.disth)
    my_cast.dist = my_cast.distv;
  else if (my_cast.disth <= my_cast.distv)
    my_cast.dist = my_cast.disth;
  if (my_cast.distv < 0 && my_cast.disth)
    my_cast.dist = my_cast.disth;
  else if (my_cast.disth < 0 && my_cast.distv)
    my_cast.dist = my_cast.distv;
  if (my_cast.dist == my_cast.disth)
    my_cast.impact = 0 + (sind(angle) >= 0 ? 1 : 0);
  else if (my_cast.dist == my_cast.distv)
    my_cast.impact = 2 + (cosd(angle) >= 0 ? 1 : 0);
  if (my_cast.dist == my_cast.distv && (my_cast.mcase.x || my_cast.mcase.y))
    my_cast.mcase = my_cast.mcasev;
  else
    my_cast.mcase = my_cast.mcaseh;    
  return (my_cast);
}
