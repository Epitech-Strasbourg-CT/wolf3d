/*
** free_tab.c for free_tab in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 09:10:01 2016 Cédric Thomas
** Last update Mon Nov 21 08:20:33 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}
