/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Mon Dec 19 21:30:41 2016 Cédric Thomas
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "wolf.h"
#include "my.h"

int		main(int ac, char **av)
{
  t_map		map;
  t_player	p;

  if (ac != 4)
    return (84);
  if ((map = parse_wolf(av[1])).map == NULL)
    {
      my_puterror("Invalid map.\n");
      return (84);
    }
  p.pos.x = my_getnbr(av[2]) + 0.5;
  p.pos.y = my_getnbr(av[3]) + 0.5;
  if (!is_betw(1, (int)p.pos.x, map.size.x - 1)
      || !is_betw(1, (int)p.pos.y, map.size.y - 1)
      || map.map[(int)p.pos.y][(int)p.pos.x] != 0)
    {
      my_puterror("Invalid player.\n");
      return (84);
    }
  if (play(&map, &p) == -1)
    {
      my_puterror("Invalid map content.\n");
      return (84);
    }
  return (0);
}
