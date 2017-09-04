/*
** events_move.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:19:16 2017 clément
** Last update Tue Jun 27 12:19:17 2017 clément
*/

#include	"response.h"

int		event_on_move(t_socket *graphic, void *arg1,
			      void __attribute__((unused)) *arg2)
{
  t_socket	*socket;

  socket = (t_socket *) arg1;
  response_graphic_ppo(graphic, socket);
  return (0);
}
