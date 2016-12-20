/*
** trigo.c for trio in /home/cedric/delivery/MUL/proj_wolf/bwolf3d
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Dec 16 21:06:26 2016 Cédric Thomas
** Last update Mon Dec 19 17:29:44 2016 Cédric Thomas
*/
#include <math.h>
#include "wolf.h"

double          cosd(double angle)
{
  return (cos(angle * M_PI / 180));
}

double          sind(double angle)
{
  return (sin(angle * M_PI / 180));
}

double          tand(double angle)
{
  return (tan(angle * M_PI / 180));
}
