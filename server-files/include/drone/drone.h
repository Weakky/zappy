/*
** drone.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Mon Jun 26 12:35:15 2017 clément
** Last update Mon Jun 26 12:35:21 2017 clément
*/

#ifndef PSU_2016_ZAPPY_DRONE_H
#define PSU_2016_ZAPPY_DRONE_H

#include	<stdlib.h>
#include	<limits.h>
#include	"server.h"
#include	"argument.h"

typedef struct	s_socket t_socket;

typedef enum	e_direction
{
  UP = 0,
  RIGHT,
  DOWN,
  LEFT
}		e_direction;

typedef enum	e_egg_state
{
  CLOSED = 0,
  HATCHED
}		e_egg_state;

typedef struct	s_position
{
  int		x;
  int		y;
}		t_position;

typedef struct	s_dist
{
  double	dist;
  int		diff_x;
  int		diff_y;
}		t_dist;

typedef struct	s_action
{
  int		(*action)(t_socket *);
  int		arg_int;
  void		*arg_ptr;
}		t_action;

typedef struct	s_egg
{
  int		id;
  int		elid;
  t_server	*server;
  t_team	*team;
  t_position	pos;
  double	hatch_to;
  double	eat_to;
  e_egg_state	state;
  int		food;
  bool		to_delete;
  void		*related_socket;
  bool		(*const have_to_eat)(struct s_egg *);
  bool		(*const have_to_hatch)(struct s_egg *);
  int		(*const eat)(struct s_egg *);
  int		(*const hatch)(struct s_egg *);
}		t_egg;

typedef struct	s_drone
{
  int		id;
  double	wait_to;
  double	eat_to;
  e_direction	direction;
  unsigned int	level;
  int		inventory[8];
  t_action	action;
  t_position	pos;
  t_team	*team;
  t_server	*server;
  t_egg		*related_egg;
  bool		(*const can_act)(struct s_drone *);
  int		(*const set_waiting)(struct s_drone *, const double);
}		t_drone;

t_drone	*init_drone(t_team *, t_server *);
t_egg	*init_egg(t_socket *, t_team *);
void	delete_drone(t_drone *);

#endif /* !PSU_2016_ZAPPY_DRONE_H */
