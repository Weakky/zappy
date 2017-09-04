/*
** commands_ai_broadcast.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:09:55 2017 clément
** Last update Tue Jun 27 11:09:56 2017 clément
*/

#include	<string.h>
#include	"utils.h"
#include	"drone.h"
#include	"action.h"

int	commands_ai_broadcast(t_socket *socket, char *arg)
{
  my_trim(arg);
  socket->drone->action.arg_ptr = strdup(arg);
  socket->drone->action.action = action_ai_broadcast;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}
