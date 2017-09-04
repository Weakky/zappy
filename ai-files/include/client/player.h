/*
** player.h for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#ifndef PSU_2016_ZAPPY_PLAYER_H
#define PSU_2016_ZAPPY_PLAYER_H

typedef enum	e_object
{
  LINEMATE = 0,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  FOOD,
  PLAYER,
  OTHER,
  EMPTY
}		e_object;

typedef struct	s_requisite
{
  char		nb_players;
  int		resources[6];
}		t_requisite;

typedef struct	s_required
{
  int		nb_needed;
  e_object	object;
}		t_required;

typedef struct	s_team_player
{
  long id;
}		t_team_player;

typedef struct	s_player_inventory
{
  long		id;
  int		inventory[6];
}		t_player_inventory;

typedef struct	s_drones_by_level
{
  t_list	*team_players;
  int		nb_ids;
}		t_drones_by_level;

typedef enum	s_ia_state
{
  SURVIVING = 0,
  RECIPES,
  JOIN_LEADER,
  WAITING_TO_EVOLVE
}		t_state;

typedef struct 		s_leader
{
  long 			friends[5];
  int 			global_inv[6];
  int			nb_frds;
  int			frds_on_tile;
}			t_leader;

typedef struct		s_player
{
  e_object		**objects;
  t_drones_by_level	drones[7];
  t_requisite		*requisite;
  t_list		*players;
  t_list		*friends_inventories;
  t_state		state;
  t_leader		l_data;
  int			nb_food;
  int			inventory[6];
  int			level;
  bool			is_leader;
  bool			is_small_leader;
  bool			asked_player_for_res;
  long 			leader_uid;
  size_t 		nb_players;
}			t_player;

t_requisite		*init_requisite();

#endif /* PSU_2016_ZAPPY_PLAYER_H */
