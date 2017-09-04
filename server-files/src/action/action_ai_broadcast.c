/*
** action_ai_broadcast.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:24:13 2017 clément
** Last update Tue Jun 27 10:24:47 2017 clément
*/

#include	<stdio.h>
#include	"event.h"

static int	broadcast_to_client(void *data, void *arg1, void *arg2)
{
  t_socket	*socket;
  t_socket	*dest;
  t_argument	*argument;
  char		buff[PIPE_BUF];
  int		direction;

  socket = (t_socket *) arg1;
  dest = (t_socket *) data;
  if (dest->type != AI || socket->sockfd == dest->sockfd)
    return (0);
  argument = socket->server->argument;
  direction = commands_ai_find_directon(socket, dest, argument);
  snprintf(buff, PIPE_BUF, "message %d, %s", direction, (char *) arg2);
  dest->bwrite->push(dest->bwrite, buff, PIPE_BUF);
  return (0);
}

int		action_ai_broadcast(t_socket *socket)
{
  list_execute(socket->server->socks, socket,
	       socket->drone->action.arg_ptr, broadcast_to_client);
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_broadcast, socket,
		 socket->drone->action.arg_ptr);
  free(socket->drone->action.arg_ptr);
  return (0);
}
