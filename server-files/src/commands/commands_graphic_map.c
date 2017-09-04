/*
** commands_graphic_map.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:11:38 2017 clément
** Last update Tue Jun 27 11:11:39 2017 clément
*/

#include	<ctype.h>
#include	"utils.h"
#include	"socket.h"
#include	"response.h"

static int	is_num(char const *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (!isdigit(str[i]))
      return (-1);
  return (0);
}

int		commands_graphic_msz(t_socket *socket,
				     char __attribute__((unused)) *arg)
{
  response_graphic_msz(socket);
  return (0);
}

int		commands_graphic_bct(t_socket *socket,
				     char __attribute__((unused)) *arg)
{
  char		**split_arg;
  int		i;
  int		x;
  int		y;

  if (!(split_arg = my_split(arg, " \t")))
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  i = -1;
  while (split_arg[++i]);
  if (i != 2 || is_num(split_arg[0]) == -1 || is_num(split_arg[1]) == -1)
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  x = atoi(split_arg[0]);
  y = atoi(split_arg[1]);
  if (x >= socket->server->argument->width ||
      y >= socket->server->argument->height)
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  response_graphic_bct(socket, x, y);
  return (0);
}

int		commands_graphic_mct(t_socket *socket,
				     char __attribute__((unused)) *arg)
{
  int		i;
  int		x;
  int		y;

  i = -1;
  while (++i < socket->server->argument->width
	 * socket->server->argument->height)
    {
      x = i % socket->server->argument->width;
      y = i / socket->server->argument->width;
      response_graphic_bct(socket, x, y);
    }
  return (0);
}
