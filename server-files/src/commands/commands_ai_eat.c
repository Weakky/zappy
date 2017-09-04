/*
** commands_ai_eat.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:10 2017 clément
** Last update Tue Jun 27 11:10:11 2017 clément
*/

#include	"socket.h"

bool		commands_ai_have_to_eat(t_socket *socket)
{
  return (socket->server->time_unit >= socket->drone->eat_to);
}

int		commands_ai_eat(t_socket *socket)
{
  char		message[PIPE_BUF];
  t_drone	*drone;

  drone = socket->drone;
  if (drone->inventory[FOOD] <= 0)
    {
      while (socket->bwrite->pop(socket->bwrite, &message) == 0);
      socket->bwrite->push(socket->bwrite, "dead", 4);
      socket->to_delete = true;
    }
  drone->inventory[FOOD] -= 1;
  drone->eat_to = socket->server->time_unit
		  + 126.0f / socket->server->argument->frequency;
  return (0);
}
