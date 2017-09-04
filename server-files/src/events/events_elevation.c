/*
** events_elevation.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:19:09 2017 clément
** Last update Tue Jun 27 12:19:10 2017 clément
*/

#include	"response.h"

int		event_on_incantation(t_socket *graphic,
				     void *arg1, void *arg2)
{
  t_socket	*speller;
  t_list	*sockets;

  speller = (t_socket *) arg1;
  sockets = (t_list *) arg2;
  response_graphic_pic(graphic, speller, sockets);
  return (0);
}

static int	incantation_end_plv(void *data, void *arg1,
				    void __attribute__((unused)) *arg2)
{
  t_socket	*socket;
  t_socket	*graphic;

  socket = (t_socket *) data;
  graphic = (t_socket *) arg1;
  response_graphic_plv(graphic, socket);
  return (0);
}

static int	incantation_end_bct(void *data, void *arg1,
				    void __attribute__((unused)) *arg2)
{
  t_socket	*socket;
  t_socket	*graphic;

  socket = (t_socket *) data;
  graphic = (t_socket *) arg1;
  response_graphic_bct(graphic, socket->drone->pos.x, socket->drone->pos.y);
  return (0);
}

int		event_on_incantation_end(t_socket *graphic,
					 void *arg1, void *arg2)
{
  t_list	*sockets;
  t_socket	*speller;
  bool		*succeeded;

  sockets = (t_list *) arg1;
  succeeded = (bool *) arg2;
  speller = (t_socket *) sockets->first->data;
  response_graphic_pie(graphic, speller, *succeeded);
  list_execute(sockets, graphic, NULL, incantation_end_plv);
  list_execute(sockets, graphic, NULL, incantation_end_bct);
  return (0);
}
