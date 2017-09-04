/*
** action_ai_fork.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:25:22 2017 clément
** Last update Tue Jun 27 10:25:23 2017 clément
*/

#include	<stdio.h>
#include	"event.h"

int 	action_ai_fork(t_socket *socket)
{
  t_egg	*egg;

  if (!(egg = init_egg(socket, socket->drone->team)))
    {
      socket->bwrite->push(socket->bwrite, "ko", 2);
      return (-1);
    }
  event_dispatch(socket->server, event_on_fork_end, egg, NULL);
  list_append(socket->server->eggs, egg);
  socket->bwrite->push(socket->bwrite, "ok", 2);
  return (0);
}
