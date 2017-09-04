/*
** server_list.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:56:03 2017 clément
** Last update Tue Jun 27 12:56:04 2017 clément
*/

#include	<sys/time.h>
#include	<sys/types.h>
#include	"server_functions.h"
#include	"event.h"


int		server_list_fd_set(void *data, void *arg1, void *arg2)
{
  fd_set	*readfd;
  fd_set	*writefd;
  t_socket	*socket;

  readfd = (fd_set *) arg1;
  writefd = (fd_set *) arg2;
  socket = (t_socket *) data;
  if (!socket->to_delete)
    FD_SET(socket->sockfd, readfd);
  FD_SET(socket->sockfd, writefd);
  return (0);
}

int		server_list_fd_isset(void *data, void *arg1, void *arg2)
{
  fd_set	*readfd;
  fd_set	*writefd;
  t_socket	*socket;

  readfd = (fd_set *) arg1;
  writefd = (fd_set *) arg2;
  socket = (t_socket *) data;
  if (FD_ISSET(socket->sockfd, readfd))
    if (socket->read(socket) == -1)
      socket->to_delete = true;
  if (FD_ISSET(socket->sockfd, writefd))
    if (socket->write(socket) == -1)
      socket->to_delete = true;
  if (!socket->to_delete && socket->execute)
    socket->execute(socket);
  return (0);
}

int		server_list_delete_errors(void *data,
					  void __attribute__ ((unused)) *arg1,
					  void __attribute__ ((unused)) *arg2)
{
  t_socket	*socket;
  int 		i;

  socket = (t_socket *) data;
  if (socket->to_delete && !socket->bwrite->count)
    {
      if (socket->type == AI)
	{
	  socket->server->map[socket->drone->pos.y
			      * socket->server->argument->width
			      + socket->drone->pos.x][PLAYER]--;
	  i = PLAYER;
	  while (++i <= THYSTAME)
	    socket->server->map[socket->drone->pos.y
				* socket->server->argument->width
				+ socket->drone->pos.x][i]
	     += socket->drone->inventory[i];
	  socket->drone->team->nmember--;
	  if (socket->drone->related_egg)
	    socket->drone->related_egg->related_socket = NULL;
	  event_dispatch(socket->server, event_on_player_die, socket, NULL);
	}
      server_delete_socket(socket->server, socket->sockfd);
    }
  return (0);
}

int		server_list_delete_eggs(void *data,
					void __attribute__ ((unused)) *arg1,
					void __attribute__ ((unused)) *arg2)
{
  t_egg		*egg;
  t_socket	*socket;

  egg = (t_egg *) data;
  if (egg->to_delete)
    {
      socket = (t_socket *) egg->related_socket;
      if (socket)
	socket->drone->related_egg = NULL;
      event_dispatch(egg->server, event_on_egg_die, egg, NULL);
      server_delete_egg(egg->server, egg->id);
    }
  return (0);
}

int		server_list_check_eggs(void *data,
				       void __attribute__ ((unused)) *arg1,
				       void __attribute__ ((unused)) *arg2)
{
  t_egg		*egg;

  egg = (t_egg *) data;
  if (egg->have_to_eat(egg))
    egg->eat(egg);
  if (egg->have_to_hatch(egg))
    egg->hatch(egg);
  return (0);
}
