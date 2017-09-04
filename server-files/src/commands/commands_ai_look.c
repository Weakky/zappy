/*
** commands_ai_look.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:33 2017 clément
** Last update Tue Jun 27 11:10:34 2017 clément
*/

#include "action.h"

int	commands_ai_look(t_socket *socket, char __attribute__((unused)) *arg)
{
  socket->drone->action.action = action_ai_look;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}
