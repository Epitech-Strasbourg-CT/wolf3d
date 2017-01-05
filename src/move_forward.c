/*
** move_forward.c for move_forward.c in /home/cedric/delivery/MUL/proj_wolf/bwolf3d/src
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Dec 13 09:33:56 2016 Cédric Thomas
** Last update Thu Jan  5 14:20:08 2017 
*/
#include <math.h>
#include <SFML/Graphics.h>
#include "wolf.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  float		angle;
  sfVector2f	next_pos;

  angle = direction * M_PI / 180;
  next_pos.x = pos .x + distance * cos(angle);
  next_pos.y = pos .y + distance * sin(angle);
  return (next_pos);
}
