/*
** commands_ai_fork.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:25 2017 clément
** Last update Tue Jun 27 11:10:25 2017 clément
*/

#include	<string.h>
#include	"event.h"
#include	"action.h"

static t_egg	*find_egg_by_team(t_server *server, t_team team)
{
  t_list_node	*temp;
  t_egg		*egg;

  temp = server->eggs->first;
  while (temp)
    {
      egg = (t_egg *) temp->data;
      if (!strcmp(egg->team->name, team.name)
	  && !(egg->related_socket) && !(egg->to_delete))
	return (egg);
      temp = temp->next;
    }
  return (NULL);
}

int		commands_ai_create_drone_by_egg(t_socket *socket,
						t_team *team)
{
  t_egg		*egg;

  if (!(egg = find_egg_by_team(socket->server, *team)))
    return (-1);
  if (!(socket->drone = init_drone(team, socket->server)))
    return (-1);
  socket->drone->pos.x = egg->pos.x;
  socket->drone->pos.y = egg->pos.y;
  socket->drone->related_egg = egg;
  egg->related_socket = socket;
  if (egg->state == CLOSED)
    socket->drone->eat_to = egg->hatch_to
      + 126.0f / socket->server->argument->frequency;
  else
    {
      socket->drone->related_egg = NULL;
      egg->to_delete = true;
      commands_ai_send_first_message(socket);
      event_dispatch(socket->server, event_on_egg_connection, socket, egg);
    }
  return (0);
}

int		commands_ai_fork(t_socket *socket,
				 char __attribute__((unused)) *arg)
{
  socket->drone->action.action = action_ai_fork;
  socket->drone->set_waiting(socket->drone, 42);
  event_dispatch(socket->server, event_on_fork, socket, NULL);
  return (0);
}
