/*
** commands_ai_elevation.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:17 2017 clément
** Last update Tue Jun 27 11:10:18 2017 clément
*/

#include	<stdio.h>
#include	"action.h"
#include	"event.h"

static bool	drone_is_valid(t_drone *tested, t_drone *speller)
{
  if (tested->level != speller->level
      || tested->pos.x != speller->pos.x
      || tested->pos.y != speller->pos.y
      || tested->id == speller->id)
    return (false);
  return (true);
}

static int	get_valid_drones(void *data, void *arg1, void *arg2)
{
  t_socket	*socket;
  t_socket	*speller;
  t_list	*drones;

  socket = (t_socket *) data;
  speller = (t_socket *) arg1;
  drones = (t_list *) arg2;
  if (socket->type == AI && drone_is_valid(socket->drone, speller->drone))
    list_append(drones, socket);
  return (0);
}

static int	elevate_drone(void *data,
			      void __attribute__((unused)) *arg1,
			      void __attribute__((unused)) *arg2)
{
  t_socket	*socket;

  socket = (t_socket *) data;
  socket->bwrite->push(socket->bwrite, "Elevation underway", 18);
  socket->drone->action.action = action_ai_elevation;
  socket->drone->set_waiting(socket->drone, 300);
  return (0);
}

static int	elevate_speller(t_socket *socket, t_list *sockets)
{
  socket->bwrite->push(socket->bwrite, "Elevation underway", 18);
  socket->drone->action.action = action_ai_elevation_speller;
  socket->drone->action.arg_ptr = sockets;
  socket->drone->set_waiting(socket->drone, 300);
  return (0);
}

int		commands_ai_incantation(t_socket *sock,
					char __attribute__((unused)) *arg)
{
  t_list	*drones;
  int		i;

  if (sock->drone->level >= 8)
    return (sock->bwrite->push(sock->bwrite, "ko", 2));
  i = -1;
  while (++i <= THYSTAME)
    {
      if (sock->server->map[sock->drone->pos.y * sock->server->argument->width
			    + sock->drone->pos.x][i]
	  < elms_needed[sock->drone->level - 1][i] && i != FOOD)
	return (sock->bwrite->push(sock->bwrite, "ko", 2));
    }
  drones = list_create();
  list_execute(sock->server->socks, sock, drones, get_valid_drones);
  elevate_speller(sock, drones);
  list_execute(drones, NULL, NULL, elevate_drone);
  list_insert(drones, sock);
  return (event_dispatch(sock->server, event_on_incantation, sock, drones));
}
