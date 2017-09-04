/*
** action.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Mon Jun 26 12:50:27 2017 clément
** Last update Mon Jun 26 12:50:30 2017 clément
*/

#ifndef PSU_2016_ZAPPY_ACTION_H
#define PSU_2016_ZAPPY_ACTION_H

#include	"socket.h"

int		action_ai_eject(t_socket *);
int		action_ai_take(t_socket *);
int		action_ai_set(t_socket *);
int		action_ai_broadcast(t_socket *);
int		action_ai_elevation(t_socket *);
int		action_ai_elevation_speller(t_socket *);
int		action_ai_look(t_socket *);
int		action_ai_forward(t_socket *);
int		action_ai_left(t_socket *);
int		action_ai_right(t_socket *);
int		action_ai_inventory(t_socket *);
int		action_ai_fork(t_socket *);

#endif /* !PSU_2016_ZAPPY_ACTION_H */
