/*
** drone.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:07:31 2017 clément
** Last update Wed Jun 28 17:22:14 2017 clément
*/

#include	<stdlib.h>
#include	<string.h>
#include	"argument.h"
#include	"drone.h"

static bool	drone_can_act(t_drone *drone)
{
  return (!drone->related_egg && drone->server->time_unit >= drone->wait_to);
}

static int	drone_set_waiting(t_drone *drone, const double time_unit)
{
  drone->wait_to = drone->server->time_unit +
		   time_unit / drone->server->argument->frequency;
  return (0);
}

t_drone			*init_drone(t_team *team, t_server *server)
{
  t_drone		*new;
  static const t_drone	template = {0, 0.0f, 0.0f, UP, 1,
				    {0, 10, 0, 0, 0, 0, 0, 0},
				    {NULL, 0, NULL}, {0, 0}, NULL,
				    NULL, NULL, drone_can_act,
				    drone_set_waiting};

  if (!(new = calloc(sizeof(t_drone), 1)))
    return (NULL);
  memcpy(new, &template, sizeof(t_drone));
  new->team = team;
  new->server = server;
  new->pos.x = rand() % server->argument->width;
  new->pos.y = rand() % server->argument->height;
  new->eat_to = server->time_unit + 126.0f / server->argument->frequency;
  new->id = server->drone_nid;
  server->drone_nid++;
  return (new);
}

void		delete_drone(t_drone *drone)
{
  if (drone)
    free(drone);
}
