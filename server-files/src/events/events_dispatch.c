/*
** events_dispatch.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:18:52 2017 clément
** Last update Tue Jun 27 12:18:53 2017 clément
*/

#include	"event.h"

int 		event_dispatch(t_server *server,
			       int (*event)(t_socket *, void *, void *),
			       void *arg1, void *arg2)
{
  t_list_node	*temp;
  t_socket	*socket;

  temp = server->socks->first;
  while (temp)
    {
      socket = (t_socket *) temp->data;
      if (socket->type == GRAPHIC)
	event(socket, arg1, arg2);
      temp = temp->next;
    }
  return (0);
}
