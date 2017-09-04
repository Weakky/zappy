/*
** action_ai_action.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:24:04 2017 clément
** Last update Tue Jun 27 10:24:06 2017 clément
*/

#include	<string.h>
#include	"event.h"

int	action_ai_take(t_socket *socket)
{
  if (socket->server->map[socket->drone->pos.y
			  * socket->server->argument->width
			  + socket->drone->pos.x][socket->drone
   ->action.arg_int] <= 0)
    return (socket->bwrite->push(socket->bwrite, "ok", 2));
  socket->server->map[socket->drone->pos.y
		      * socket->server->argument->width
		      + socket->drone->pos.x][socket->drone
   ->action.arg_int]--;
  socket->drone->inventory[socket->drone->action.arg_int]++;
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_take,
		 socket, &(socket->drone->action.arg_int));
  return (0);
}

int	action_ai_set(t_socket *socket)
{
  socket->server->map[socket->drone->pos.y
		      * socket->server->argument->width
		      + socket->drone->pos.x][socket->drone
   ->action.arg_int]++;
  socket->drone->inventory[socket->drone->action.arg_int]--;
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_set,
		 socket, &(socket->drone->action.arg_int));
  return (0);
}
