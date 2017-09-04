/*
** server.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 13:14:15 2017 clément
** Last update Fri Jun  9 13:16:44 2017 clément
*/

#ifndef PSU_2016_ZAPPY_SERVER_H
#define PSU_2016_ZAPPY_SERVER_H

#include	"argument.h"
#include	"list.h"

#define UPDATE_TIME_UNIT (600.0f)

typedef enum		e_objects
{
  PLAYER = 0,
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME
}			e_objects;

typedef struct		s_server
{
  t_list		*socks;
  t_list		*eggs;
  t_argument		*argument;
  t_team		*winning_team;
  int			(*map)[8];
  double		time_unit;
  double 		update_to;
  struct timeval	last_update;
  int			nfds;
  int			drone_nid;
  int			egg_nid;
  int			(*const wait)(struct s_server *);
  int			(*const update_time)(struct s_server *);
  bool			(*const have_to_update)(struct s_server *);
  int			(*const update)(struct s_server *);
}			t_server;

t_server	*init_server(t_argument);
void		delete_server(t_server *);

#endif /* !PSU_2016_ZAPPY_SERVER_H */
