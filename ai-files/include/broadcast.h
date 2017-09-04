/*
** broadcast.h for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#ifndef PSU_2016_ZAPPY_BROADCAST_H
#define PSU_2016_ZAPPY_BROADCAST_H

#include <stdbool.h>
#include "client.h"

typedef enum	e_message_type
{
  PING = 0,
  PONG,
  MAKE_GROUP,
  LVL_UP,
  ASK_INVENTORY,
  SET_OBJECT,
  JOIN_ME,
  I_AM_HERE,
  GOING_TO_EVOLVE,
  GO_BACK_TO_WHITELIST,
  GO_TO_SURVIVE,
}		e_message_type;

bool	handle_broadcast(t_client *client, char *line, bool *keep_reading);
/* !MESSAGE */
bool	broadcast_message_ping(t_client *, char **, char direction);
bool	broadcast_message_pong(t_client *, char **, char direction);
bool	broadcast_message_lvl_up(t_client *, char **, char direction);
bool	broadcast_message_evolve(t_client *, char **, char direction);
bool	broadcast_message_whitelist(t_client *, char **,
				 char direction);
bool	broadcast_message_make_group(t_client *, char **, char direction);
bool	broadcast_message_ask_inventory(t_client *, char **, char direction);
bool	broadcast_message_set_object(t_client *, char **, char direction);
bool	broadcast_message_join_me(t_client *, char **, char direction);
bool	broadcast_message_i_am_here(t_client *, char **, char direction);
bool	broadcast_message_go_to_survive(t_client *, char **, char direction);
/* !SEND */
void	broadcast_send_ping(t_client *);
void	broadcast_send_pong(t_client *);
void	broadcast_send_ask_inventory(t_client *);
void	broadcast_send_join_me(t_client *);
void	broadcast_send_i_am_here(t_client *);
void	broadcast_send_going_to_evolve(t_client *);
void	broadcast_send_go_to_survive(t_client *);
void	broadcast_send_set_object(t_client *, t_required *,
				      t_player_inventory *, long);
#endif /* PSU_2016_ZAPPY_BROADCAST_H */
