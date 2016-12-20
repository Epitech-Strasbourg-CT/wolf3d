/*
** parse_wireframe.c for parse_wireframe.c in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 11:57:42 2016 Cédric Thomas
** Last update Sun Dec 18 21:50:34 2016 Cédric Thomas
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "wolf.h"

static int	check_str(char *str)
{
  int		i;
  int		bool;

  bool = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	bool = 0;
      else if (is_in(str[i], "0123456789"))
	bool = 1;
      i += 1;
    }
  return (bool);
}

static sfVector2i	getdim(char **tab)
{
  sfVector2i		dim;
  int			i;
  int			count;

  dim.x = 0;
  dim.y = 0;
  while (tab[dim.y])
    {
      i = 0;
      count = 0;
      while (tab[dim.y][i])
	{
	  if (is_in(tab[dim.y][i], "0123456789-") &&
	      (i == 0 || !is_in(tab[dim.y][i - 1], "0123456789-")))
	    count += 1;
	  i += 1;
	}
      if (dim.x <= count)
	dim.x = count;
      dim.y += 1;
    }
  return (dim);
}

static void	split_line(int *to_fill, char *str, int len)
{
  int		i;
  int		k;

  i = 0;
  k = 0;
  to_fill[k] = 0;
  while (str[i])
    {
      if (is_in(str[i], "-0123456789") && k < len)
	{
	  if (is_in(str[i], "0123456789"))
	    to_fill[k] = (to_fill[k] * 10 + str[i] - '0')
	      * (i > 0 && str[i - 1] == '-' ? -1 : 1);
	}
      else if (++k < len)
	to_fill[k] = 0;
      i += 1;
    }
  while (++k < len)
    to_fill[k] = 0;
}

static int	fill(char **split, t_map *m)
{
  int		i;

  i = 0;
  if ((m->map = malloc(sizeof(int *) * m->size.y)) == NULL)
    return (-1);
  while (split[i])
    {
      if ((m->map[i] = malloc(sizeof(int) * m->size.x)) == NULL)
	return (-1);
      split_line(m->map[i], split[i], m->size.x);
      i += 1;
    }
  return (1);
}

t_map	parse_wolf(char *path)
{
  char			**split;
  char			*readed;
  t_map			map;

  map.map = NULL;
  map.size.x = -1;
  map.size.y = -1;
  if ((readed = my_read(path)) == NULL)
    return (map);
  if (!check_str(readed))
    return (map);
  if ((split = my_split(readed, '\n')) == NULL)
    return (map);
  map.size = getdim(split);
  if (map.size.x == 0)
    return (map);
  if (fill(split, &map) == -1)
    map.map = NULL;
  free(readed);
  free_tab(split);
  return (map);
}
