/*
** parse.c for wireframe_parse in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 19 10:32:09 2016 Cédric Thomas
** Last update Sat Dec 17 18:43:15 2016 Cédric Thomas
*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf.h"
#include "my.h"

static int	getfilesize(char *path)
{
  int		size;
  int		fd;
  char		buff[1000];
  int		len;

  size = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_puterror("invalid file.\n");
      return (-1);
    }
  while ((len = read(fd, buff, 1000)) > 0)
    size += len;
  close(fd);
  return (size);
}

char	*my_read(char *path)
{
  char  *buff;
  int	size;
  int   offset;
  int   len;
  int	fd;

  offset = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_puterror("invalid file.\n");
      return (NULL);
    }
  if ((size = getfilesize(path)) == -1)
    return (NULL);
  if ((buff = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while ((len = read(fd, buff + offset, size - offset)) > 0)
    offset += len;
  buff[offset] = '\0';
  if (len < 0)
    return (NULL);
  close(fd);
  return (buff);
}
