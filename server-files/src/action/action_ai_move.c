/*
** action_ai_move.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:25:39 2017 clément
** Last update Tue Jun 27 10:25:40 2017 clément
*/

#include	"event.h"

int	action_ai_forward(t_socket *socket)
{
  int	width;
  int	height;
  const	t_position available_pos[4] =
    {{socket->drone->pos.x, socket->drone->pos.y - 1},
     {socket->drone->pos.x + 1, socket->drone->pos.y},
     {socket->drone->pos.x, socket->drone->pos.y + 1},
     {socket->drone->pos.x - 1, socket->drone->pos.y}};

  width = socket->server->argument->width;
  height = socket->server->argument->height;
  socket->server->map[socket->drone->pos.y
		      * socket->server->argument->width
		      + socket->drone->pos.x][PLAYER] -= 1;
  socket->drone->pos = available_pos[socket->drone->direction];
  commands_ai_adjust_position(&(socket->drone->pos), width, height);
  socket->server->map[socket->drone->pos.y
		      * socket->server->argument->width
		      + socket->drone->pos.x][PLAYER] += 1;
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_move, socket, NULL);
  return (0);
}

int	action_ai_left(t_socket *socket)
{
  if (socket->drone->direction == UP)
    socket->drone->direction = LEFT;
  else
    socket->drone->direction--;
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_move, socket, NULL);
  return (0);
}

int	action_ai_right(t_socket *socket)
{
  if (socket->drone->direction == LEFT)
    socket->drone->direction = UP;
  else
    socket->drone->direction++;
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_move, socket, NULL);
  return (0);
}
