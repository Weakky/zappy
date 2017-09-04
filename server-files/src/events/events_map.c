/*
** events_map.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 18:44:25 2017 clément
** Last update Tue Jun 27 18:44:31 2017 clément
*/

#include	"socket.h"
#include	"response.h"

int		event_on_tile_update(t_socket *graphic,
					void *arg1, void *arg2)
{
  int		*x;
  int 		*y;

  x = (int *) arg1;
  y = (int *) arg2;
  response_graphic_bct(graphic, *x, *y);
  return (0);
}
