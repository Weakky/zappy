/*
** events_player.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:19:30 2017 clément
** Last update Tue Jun 27 12:19:31 2017 clément
*/

#include	"response.h"

int		event_on_connection(t_socket *graphic, void *arg1,
				    void __attribute__((unused)) *arg2)
{
  t_socket	*socket;

  socket = (t_socket *) arg1;
  response_graphic_pnw(graphic, socket);
  return (0);
}

int		event_on_egg_connection(t_socket *graphic,
					void *arg1, void *arg2)
{
  t_socket	*socket;
  t_egg		*egg;

  socket = (t_socket *) arg1;
  egg = (t_egg *) arg2;
  response_graphic_ebo(graphic, egg);
  response_graphic_pnw(graphic, socket);
  return (0);
}

int		event_on_player_die(t_socket *graphic, void *arg1,
				    void __attribute__((unused)) *arg2)
{
  t_socket	*socket;

  socket = (t_socket *) arg1;
  response_graphic_pdi(graphic, socket);
  response_graphic_bct(graphic, socket->drone->pos.x, socket->drone->pos.y);
  return (0);
}

int		event_on_end_of_game(t_socket *graphic, void *arg1,
				     void __attribute__((unused)) *arg2)
{
  t_server	*server;

  server = (t_server *) arg1;
  response_graphic_seg(graphic, server);
  return (0);
}
