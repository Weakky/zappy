/*
** events_action.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:18:45 2017 clément
** Last update Tue Jun 27 12:18:46 2017 clément
*/

#include	"response.h"

int		event_on_take(t_socket *graphic, void *arg1, void *arg2)
{
  t_socket	*socket;
  e_objects	*resource;

  socket = (t_socket *) arg1;
  resource = (e_objects *) arg2;
  response_graphic_pgt(graphic, socket, *resource);
  response_graphic_pin(graphic, socket);
  response_graphic_bct(graphic, socket->drone->pos.x, socket->drone->pos.y);
  return (0);
}

int		event_on_set(t_socket *graphic, void *arg1, void *arg2)
{
  t_socket	*socket;
  e_objects	*resource;

  socket = (t_socket *) arg1;
  resource = (e_objects *) arg2;
  response_graphic_pdr(graphic, socket, *resource);
  response_graphic_pin(graphic, socket);
  response_graphic_bct(graphic, socket->drone->pos.x, socket->drone->pos.y);
  return (0);
}

int		event_on_eject(t_socket *graphic, void *arg1, void *arg2)
{
  t_socket	*socket;
  t_list	*targets;
  t_list_node	*temp;

  socket = (t_socket *) arg1;
  targets = (t_list *) arg2;
  response_graphic_pex(graphic, socket);
  temp = targets->first;
  while (temp)
    {
      socket = (t_socket *) temp->data;
      response_graphic_ppo(graphic, socket);
      temp = temp->next;
    }
  return (0);
}

int		event_on_broadcast(t_socket *graphic, void *arg1, void *arg2)
{
  t_socket	*socket;
  char		*message;

  socket = (t_socket *) arg1;
  message = (char *) arg2;
  response_graphic_pbc(graphic, socket, message);
  return (0);
}
