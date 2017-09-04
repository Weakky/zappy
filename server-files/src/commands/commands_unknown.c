/*
** commands_unknown.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:12:12 2017 clément
** Last update Tue Jun 27 11:12:13 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"event.h"
#include	"socket_functions.h"

void		commands_ai_send_first_message(t_socket *socket)
{
  char		num_to_s[PIPE_BUF];

  snprintf(num_to_s, PIPE_BUF, "%d\n%d %d",
	   socket->server->argument->nclients
	   - socket->drone->team->nmember,
	   socket->server->argument->width,
	   socket->server->argument->height);
  socket->bwrite->push(socket->bwrite, num_to_s, strlen(num_to_s));
}

static int	create_drone(t_socket *sock, t_argument *arg, int i)
{
  if (sock->to_delete)
    return (-1);
  if (arg->nclients - arg->teams[i].nmember <= 0)
    {
      sock->bwrite->push(sock->bwrite, "ko", 2);
      sock->to_delete = true;
      return (-1);
    }
  if (!(sock->drone = init_drone(&(arg->teams[i]), sock->server)))
    {
      sock->to_delete = true;
      return (-1);
    }
  event_dispatch(sock->server, event_on_connection, sock, NULL);
  sock->drone->team->nmember++;
  commands_ai_send_first_message(sock);
  return (0);
}

int		commands_unknown_ai(t_socket *sock, char *args)
{
  t_argument	*arg;
  int		i;

  i = -1;
  arg = sock->server->argument;
  if (!args)
    return (-1);
  while (++i < arg->nteam)
    if (!(strcmp(arg->teams[i].name, args)))
      {
	if (commands_ai_create_drone_by_egg(sock, &(arg->teams[i])))
	  if (create_drone(sock, arg, i) == -1)
	    return (-1);
	sock->type = AI;
	sock->execute = ai_socket_execute;
	commands_set_ai(sock);
	sock->server->map[sock->drone->pos.y
			  * sock->server->argument->width
			  + sock->drone->pos.x][PLAYER] += 1;
	return (0);
      }
  sock->to_delete = true;
  sock->bwrite->push(sock->bwrite, "ko", 2);
  return (-1);
}

int		commands_unknown_graphic(t_socket *socket,
					    char __attribute__((unused)) *arg)
{

  socket->type = GRAPHIC;
  event_on_new_monitor(socket, NULL, NULL);
  return (0);
}
