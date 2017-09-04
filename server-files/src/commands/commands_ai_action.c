/*
** commands_ai_action.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:09:47 2017 clément
** Last update Tue Jun 27 11:09:48 2017 clément
*/

#include	<string.h>
#include	"action.h"
#include	"utils.h"

int		commands_ai_eject(t_socket *socket,
				     char __attribute__((unused)) *arg)
{
  if (socket->server->map[socket->drone->pos.y
			  * socket->server->argument->width
			  + socket->drone->pos.x][PLAYER] <= 1)
    {
      socket->bwrite->push(socket->bwrite, "ko", 2);
      return (-1);
    }
  socket->drone->action.action = action_ai_eject;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}

int		commands_ai_take(t_socket *socket, char *arg)
{
  int		i;
  int		correspond;

  i = PLAYER;
  correspond = -1;
  if (!arg)
    return (0);
  my_trim(arg);
  while (++i <= THYSTAME)
    if (!(strcasecmp(arg, elm_names[i])))
      correspond = i;
  if (correspond <= 0
      || socket->server->map[socket->drone->pos.y
			     * socket->server->argument->width
			     + socket->drone->pos.x][correspond] <= 0)
      return (socket->bwrite->push(socket->bwrite, "ko", 2));
  socket->drone->action.action = action_ai_take;
  socket->drone->action.arg_int = correspond;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}

int		commands_ai_set(t_socket *socket, char *arg)
{
  int		i;
  int		correspond;

  i = PLAYER;
  correspond = -1;
  if (!arg)
    return (0);
  my_trim(arg);
  while (++i <= THYSTAME)
    if (!(strcasecmp(arg, elm_names[i])))
      correspond = i;
  if (correspond <= 0
      || socket->drone->inventory[correspond] <= 0)
    {
      socket->bwrite->push(socket->bwrite, "ko", 2);
      return (-1);
    }
  socket->drone->action.action = action_ai_set;
  socket->drone->action.arg_int = correspond;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}
