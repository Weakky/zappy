/*
** events_new_monitor.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:19:23 2017 clément
** Last update Tue Jun 27 12:19:24 2017 clément
*/

#include	"response.h"

static int	display_drones(void *data, void *arg1,
			       void __attribute__((unused)) *arg2)
{
  t_socket	*socket;
  t_socket	*graphic;

  graphic = (t_socket *) arg1;
  socket = (t_socket *) data;
  if (socket->type == AI)
    response_graphic_pnw(graphic, socket);
  return (0);
}

static int	display_eggs(void *data, void *arg1,
			     void __attribute__((unused)) *arg2)
{
  t_egg		*egg;
  t_socket	*graphic;

  graphic = (t_socket *) arg1;
  egg = (t_egg *) data;
  response_graphic_enw(graphic, egg);
  return (0);
}

int		event_on_new_monitor(t_socket *graphic,
				     void __attribute__((unused)) *arg1,
				     void __attribute__((unused)) *arg2)
{
  commands_set_graphic(graphic);
  commands_graphic_msz(graphic, NULL);
  commands_graphic_sgt(graphic, NULL);
  commands_graphic_mct(graphic, NULL);
  commands_graphic_tna(graphic, NULL);
  list_execute(graphic->server->socks, graphic, NULL, display_drones);
  list_execute(graphic->server->eggs, graphic, NULL, display_eggs);
  return (0);
}
