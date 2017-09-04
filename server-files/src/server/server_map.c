/*
** server_map.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 16:24:59 2017 clément
** Last update Tue Jun 27 16:25:00 2017 clément
*/

#include	<string.h>
#include	"event.h"
#include	"server_functions.h"

static int 		update_tile(t_server *server, int x, int y, int width)
{
  static const int	probability[8] = {0, 50, 18, 16, 20, 10, 12, 2};
  static const int	num_max[8] = {0, 15, 2, 2, 2, 1, 1, 1};
  int			j;
  int 			k;

  j = PLAYER;
  while (++j <= THYSTAME)
    {
      k = -1;
      while (++k < num_max[j])
	server->map[x * width + y][j]
	 += ((rand() % 100) <= probability[j]);
    }
  return (0);
}

int			server_generate_map(t_server *new,
					       t_argument argument)
{
  int			i;

  if (!(new->map = calloc(sizeof(int[8]),
			  (size_t) (argument.width * argument.height))))
    return (-1);
  bzero(new->map, sizeof(int[8]) * argument.width * argument.height);
  i = -1;
  while (++i < argument.width * argument.height)
    update_tile(new, i / argument.width, i % argument.width, argument.width);
  return (0);
}

bool			server_have_to_update(t_server *server)
{
  return (server->time_unit >= server->update_to);
}

int			server_update(t_server *server)
{
  int 			i;
  int 			x;
  int 			y;

  i = -1;
  while (++i < (server->argument->width * server->argument->height) / 50)
    {
      x = rand() % server->argument->width;
      y = rand() % server->argument->height;
      update_tile(server, x, y, server->argument->width);
      event_dispatch(server, event_on_tile_update, &x, &y);
    }
  server->update_to = server->time_unit + UPDATE_TIME_UNIT
					  / server->argument->frequency;
  return (0);
}
