/*
** events_egg.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:19:00 2017 clément
** Last update Tue Jun 27 12:19:02 2017 clément
*/

#include	"response.h"

int		event_on_fork(t_socket *graphic, void *arg1,
			      void __attribute__((unused)) *arg2)
{
  t_socket	*socket;

  socket = (t_socket *) arg1;
  response_graphic_pfk(graphic, socket);
  return (0);
}

int		event_on_fork_end(t_socket *graphic, void *arg1,
				  void __attribute__((unused)) *arg2)
{
  t_egg		*egg;

  egg = (t_egg *) arg1;
  response_graphic_enw(graphic, egg);
  return (0);
}

int		event_on_hatch(t_socket *graphic, void *arg1,
			       void __attribute__((unused)) *arg2)
{
  t_egg		*egg;

  egg = (t_egg *) arg1;
  response_graphic_eht(graphic, egg);
  return (0);
}

int		event_on_egg_die(t_socket *graphic, void *arg1,
				 void __attribute__((unused)) *arg2)
{
  t_egg		*egg;

  egg = (t_egg *) arg1;
  response_graphic_edi(graphic, egg);
  return (0);
}
