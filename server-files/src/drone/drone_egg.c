/*
** drone_egg.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:07:42 2017 clément
** Last update Wed Jun 28 17:22:49 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	"event.h"

static bool	have_to_eat(t_egg *egg)
{
  return (egg->state == HATCHED && egg->server->time_unit >= egg->eat_to);
}

static bool	have_to_hatch(t_egg *egg)
{
  return (egg->state == CLOSED && egg->server->time_unit >= egg->hatch_to);
}

static int	eat(t_egg *egg)
{
  if (egg->food == 0)
    {
      egg->to_delete = true;
      return (-1);
    }
  egg->food--;
  egg->eat_to = egg->server->time_unit
		+ 126.0f / egg->server->argument->frequency;
  return (0);
}

static int	hatch(t_egg *egg)
{
  t_socket	*socket;

  egg->state = HATCHED;
  egg->eat_to = egg->server->time_unit
		+ 126.0f / egg->server->argument->frequency;
  event_dispatch(egg->server, event_on_hatch, egg, NULL);
  if (egg->related_socket)
    {
      socket = (t_socket *) egg->related_socket;
      socket->drone->related_egg = NULL;
      egg->to_delete = true;
      commands_ai_send_first_message(socket);
      event_dispatch(socket->server, event_on_egg_connection, socket, egg);
    }
  return (0);
}

t_egg			*init_egg(t_socket *socket, t_team *team)
{
  t_egg			*egg;
  static const t_egg	template = {0, 0, NULL, NULL,
				    {0, 0}, 0, 0, CLOSED, 10, false,
				    NULL, have_to_eat,
				    have_to_hatch, eat, hatch};

  if (!(egg = calloc(sizeof(t_egg), 1)))
    return (NULL);
  memcpy(egg, &template, sizeof(t_egg));
  egg->server = socket->server;
  egg->team = team;
  egg->id = socket->server->egg_nid;
  egg->elid = socket->drone->id;
  egg->hatch_to = egg->server->time_unit
    + 600.0f / egg->server->argument->frequency;
  socket->server->egg_nid++;
  egg->pos.x = socket->drone->pos.x;
  egg->pos.y = socket->drone->pos.y;
  return (egg);
}
