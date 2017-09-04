/*
** commands_ai_move.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:50 2017 clément
** Last update Tue Jun 27 11:10:50 2017 clément
*/

#include	"action.h"

int	commands_ai_adjust_position(t_position *pos, int width, int height)
{
  if (pos->x < 0)
    pos->x += width;
  else if (pos->x >= width)
    pos->x %= width;
  if (pos->y < 0)
    pos->y += height;
  else if (pos->y >= height)
    pos->y %= height;
  return (0);
}

int	commands_ai_forward(t_socket *socket,
			    char __attribute__((unused)) *arg)
{
  socket->drone->action.action = action_ai_forward;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}

int	commands_ai_left(t_socket *socket, char __attribute__((unused)) *arg)
{
  socket->drone->action.action = action_ai_left;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}


int	commands_ai_right(t_socket *socket, char __attribute__((unused)) *arg)
{
  socket->drone->action.action = action_ai_right;
  socket->drone->set_waiting(socket->drone, 7);
  return (0);
}
