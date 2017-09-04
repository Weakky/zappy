/*
** action_ai_eject.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:25:06 2017 clément
** Last update Tue Jun 27 10:45:57 2017 clément
*/

#include	<limits.h>
#include	<string.h>
#include	<stdio.h>
#include	"event.h"

static void	update_position(t_socket *socket, t_socket *sender)
{
  if (sender->drone->direction == UP)
    socket->drone->pos.y--;
  else if (sender->drone->direction == RIGHT)
    socket->drone->pos.x++;
  else if (sender->drone->direction == DOWN)
    socket->drone->pos.y++;
  else
    socket->drone->pos.x--;
  commands_ai_adjust_position(&(socket->drone->pos),
			      socket->server->argument->width,
			      socket->server->argument->height);
}

static int	eject_socket(void *data, void *arg1,
			     void __attribute__((unused)) *arg2)
{
  t_socket	*socket;
  t_socket	*sender;
  static char	*direction_string[] = {"Down", "Left", "Up", "Right"};
  char		buff[PIPE_BUF];

  socket = (t_socket *) data;
  sender = (t_socket *) arg1;
  update_position(socket, sender);
  sprintf(buff, "eject: %s\n", direction_string[socket->drone->direction]);
  socket->bwrite->push(socket->bwrite, buff, strlen(buff));
  return (0);
}

static int	add_socket_to_eject(void *data, void *arg1, void *arg2)
{
  t_socket	*socket;
  t_socket	*sender;
  t_list	*target;

  socket = (t_socket *) data;
  sender = (t_socket *) arg1;
  target = (t_list *) arg2;
  if (socket->type != AI || socket->drone->related_egg)
    return (0);
  if (socket->drone->pos.x == sender->drone->pos.x
      && socket->drone->pos.y == sender->drone->pos.y
      && socket->drone->id != sender->drone->id)
    list_append(target, socket);
  return (0);
}

int		action_ai_eject(t_socket *socket)
{
  t_list	*targets;

  targets = list_create();
  list_execute(socket->server->socks, socket, targets, add_socket_to_eject);
  if (!(targets->first))
    {
      socket->bwrite->push(socket->bwrite, "ko", 2);
      list_free(targets, NULL);
    }
  list_execute(targets, socket, NULL, eject_socket);
  socket->bwrite->push(socket->bwrite, "ok", 2);
  event_dispatch(socket->server, event_on_eject, socket, targets);
  list_free(targets, NULL);
  return (0);
}
