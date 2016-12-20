/*
** misc.c for misc in /home/cedric/delivery/MUL/proj_wolf/wolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sun Dec 18 18:25:57 2016 Cédric Thomas
** Last update Mon Dec 19 15:20:54 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

void		add_vec(sfVector2f *pos, float len, float alpha)
{
  pos->x += len * cosd(alpha);
  pos->y -= len * sind(alpha);
}
