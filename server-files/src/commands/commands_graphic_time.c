/*
** commands_graphic_time.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:11:56 2017 clément
** Last update Tue Jun 27 11:11:57 2017 clément
*/

#include	<stdio.h>
#include	<ctype.h>
#include	"socket.h"
#include	"response.h"
#include	"utils.h"

int	commands_graphic_sgt(t_socket *socket,
				char __attribute__((unused)) *arg)
{
  response_graphic_sgt(socket);
  return (0);
}

int	commands_graphic_sst(t_socket *socket, char *arg)
{
  int	i;

  if (!arg)
    {
      socket->bwrite->push(socket->bwrite, "sbp", 3);
      return (-1);
    }
  my_trim(arg);
  i = -1;
  while (arg[++i])
    if (!isdigit(arg[i]))
      {
	socket->bwrite->push(socket->bwrite, "sbp", 3);
	return (-1);
      }
  socket->server->argument->frequency = atoi(arg);
  response_graphic_sgt(socket);
  return (0);
}
