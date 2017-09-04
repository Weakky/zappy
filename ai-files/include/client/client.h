/*
** client.h for  in PSU_2016_myirc
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Thu Jun  8 19:05:02 2017 clément
** Last update Thu Jun  8 19:19:24 2017 clément
*/

#ifndef PSU_2016_MYIRC_CLIENT_H
#define PSU_2016_MYIRC_CLIENT_H

#include	<stdbool.h>
#include	<stdio.h>
#include	"argument.h"
#include	"circular_buffer.h"
#include	"list.h"
#include	"player.h"

typedef enum	e_command
{
  LOOK = 0,
  FORWARD,
  RIGHT,
  LEFT,
  INVENTORY,
  BROADCAST,
  CONNECT,
  FORK,
  EJECT,
  TAKE,
  SET,
  INCANT,
  NOTHING,
}		e_command;

struct s_client;

typedef bool		(*t_exec_cmd)(struct s_client *, char *response, char *arg);

typedef struct		s_command
{
  e_command		name;
  t_exec_cmd 		exec_cmd;
  char 			*arg;
}			t_command;

typedef struct		s_client
{
  int			server_sockfd;
  FILE			*fs;
  t_circular_buffer	*buffer;
  t_argument		*arg;
  t_player		*player;
  t_command		command;
  long 			uid;
  bool			running;
  int			(*const write)(struct s_client *);
  int			(*const read)(struct s_client *);
}			t_client;

typedef struct		s_object
{
  char			*name;
  e_object		object;
}			t_object;

t_client		*init_client(char **);
t_player		*init_player(t_client *);
void			delete_client(t_client *);
void			delete_player(t_player *);
void			send_command(t_client *client, e_command cmd);
void			send_command_with_arg(t_client *client,
					      e_command command, char *arg);
t_requisite		get_requisite_for_level(t_client *);
t_team_player		*add_player_to_whitelist(t_client *client,
						 int level, long id);
void			remove_player_from_whitelist(t_client *client,
						     int level, long id);
bool			has_player_in_group(t_client *client, long id);
bool			am_i_part_of_group(t_client *, char **, int);
void			parse_received_inventory(t_client *, char **, long);
void			set_global_inventory(t_client *);
e_object		parse_object(char *object);
t_player_inventory	*inventory_by_id(t_client *, long);
void			handle_level_up(t_client *client);
bool			define_leader(t_client *client,
				      char **response, long leader_id);
void			join_leader(t_client *client, char direction);
bool			prepare_tile_to_evolve(t_client *client, t_requisite *req);

/*
extern char *object_to_string[NB_RESOURCES];

bool		client_execute_read(t_client *client, char **commands);
t_command	*init_command(Command command);
t_command	*init_handshake();
 */
/* ============== IA ============== */
/*
bool should_survive(t_client *client);
void survive(t_client *client);
Command *walk_towards_tile(t_client *client, int index);
t_requisite get_requisite_for_level(t_client *client);
int get_index_for_object(t_client *client, Object search);
int get_amount_for_index(t_client *client, int index, Object search);
void move_to_tile(t_client *client, int index);
bool can_evolve_with_friends(t_client *client, t_requisite requisite);
void remove_object_from_requisite(t_client *client, Object object);
void send_ping(t_client *client);
t_team_player *add_player_to_whitelist(t_client *client, int level, long id);
void remove_player_from_whitelist(t_client *client, int level, long id);
void parse_received_inventory(t_client *client, char **inventory,
 long player_id);
void send_ask_inventory_pong(t_client *client);
void create_valid_group(t_client *client);
bool find_resources_to_evolve(t_client *client, t_requisite requisite);
void set_global_inventory(t_client *client);
bool can_evolve(t_client *client, t_requisite requisite);
t_required *wanted_resources(t_client *client, t_requisite requisite);
t_player_inventory *inventory_by_id(t_client *client, long id);
void ask_for_needed_res(t_client *client, t_requisite requisite);
bool can_evolve_alone(t_client *client, t_requisite requisite);
t_required *res_to_set(t_client *client, t_requisite requisite);
bool handle_incant_from_speller(t_client *client, char *response);
void handle_level_up(t_client *client);
*/
#endif /* !PSU_2016_MYIRC_CLIENT_H */
