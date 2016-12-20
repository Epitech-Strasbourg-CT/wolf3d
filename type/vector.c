/*
** vectorf.c for mmysf in /home/cedric/delivery/MUL/libmysf/type
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 21:17:53 2016 Cédric Thomas
** Last update Sat Dec 17 18:22:26 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include "wolf.h"

sfVector2f      myvector2f(double x, double y)
{
  sfVector2f    vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfVector3f      myvector3f(double x, double y, double z)
{
  sfVector3f    vec;

  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}

sfVector2i	myvector2i(int x, int y)
{
  sfVector2i	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}
