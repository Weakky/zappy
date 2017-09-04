/*
** event.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Mon Jun 26 12:51:00 2017 clément
** Last update Mon Jun 26 12:51:01 2017 clément
*/

#ifndef PSU_2016_ZAPPY_EVENT_H
#define PSU_2016_ZAPPY_EVENT_H

#include	"socket.h"

int	event_on_move(t_socket *, void *, void *);
int	event_on_take(t_socket *, void *, void *);
int	event_on_set(t_socket *, void *, void *);
int	event_on_connection(t_socket *, void *, void *);
int	event_on_new_monitor(t_socket *, void *, void *);
int	event_on_egg_connection(t_socket *, void *, void *);
int	event_on_eject(t_socket *, void *, void *);
int	event_on_broadcast(t_socket *, void *, void *);
int	event_on_incantation(t_socket *, void *, void *);
int	event_on_incantation_end(t_socket *, void *, void *);
int	event_on_fork(t_socket *, void *, void *);
int	event_on_fork_end(t_socket *, void *, void *);
int	event_on_hatch(t_socket *, void *, void *);
int	event_on_egg_die(t_socket *, void *, void *);
int	event_on_player_die(t_socket *, void *, void *);
int	event_on_end_of_game(t_socket *, void *, void *);
int	event_on_tile_update(t_socket *, void *, void *);
int	event_dispatch(t_server *, int (*)(t_socket *, void *, void *),
			  void *, void *);

#endif /* !PSU_2016_ZAPPY_EVENT_H */
