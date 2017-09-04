/*
** commands_default.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:11:31 2017 clément
** Last update Tue Jun 27 11:11:32 2017 clément
*/

#include	"socket.h"

int	commands_ai_default(t_socket *socket,
			    char __attribute__((unused)) *arg)
{
  socket->bwrite->push(socket->bwrite, "ko", 2);
  return (0);
}

int	commands_graphic_default(t_socket *socket,
				 char __attribute__((unused)) *arg)
{
  socket->bwrite->push(socket->bwrite, "suc", 3);
  return (0);
}
