/*
** broadcast_message_personal.c for message_personal in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:28:52 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:31:41 2017 Flavian DESVERNE
*/

#include <string.h>
#include "utils.h"
#include "broadcast.h"
#include "client_functions.h"

bool		broadcast_message_ping(t_client *client,
				       char **response,
				       char direction)
{
  broadcast_message_pong(client, response, direction);
  broadcast_send_pong(client);
  return (true);
}

bool		broadcast_message_pong(t_client *client,
				       char **response,
				       char __attribute__((unused))
				       direction)
{
  int		i;
  t_team_player	*player;

  i = -1;
  while (response[++i]);
  if (i != 3)
    return (false);
  if (!has_player_in_group(client, atol(response[0])) &&
      strcmp(client->arg->name, response[1]) == 0)
    {
      if (!(player = add_player_to_whitelist(client, atoi(response[2]),
					     atol(response[0]))))
	return (false);
      list_append(client->player->players, player);
      client->player->nb_players++;
      client->player->is_leader =
	(client->player->is_leader) && (client->uid < atol(response[0]));
      if (client->player->is_leader)
	printf("I AM SUPER LEADER!!!\n");
    }
  return (true);
}

bool		broadcast_message_lvl_up(t_client *client,
					 char **response,
					 char __attribute__((unused))
					 direction)
{
  char		*team_name;
  int		level;
  long		uid;
  int		i;

  i = -1;
  while (response[++i]);
  if (i != 3)
    {
      free_tab(response);
      return (false);
    }
  team_name = response[0];
  level = atoi(response[1]);
  uid = atol(response[2]);
  if (strcmp(client->arg->name, team_name) != 0)
    return (false);
  add_player_to_whitelist(client, level, uid);
  return (true);
}

bool		broadcast_message_evolve(t_client *client,
					 char **response,
					 char __attribute__((unused))
					 direction)
{
  if (am_i_part_of_group(client, response, 0))
    {
      client->command.exec_cmd = incantation;
      client->command.arg = NULL;
      client->command.name = INCANT;
      client->player->state = WAITING_TO_EVOLVE;
    }
  return (true);
}

bool		broadcast_message_whitelist(t_client *client,
					    char **response,
					    char __attribute__((unused))
					    direction)
{
  if (am_i_part_of_group(client, response, 0))
    {
      handle_level_up(client);
      return (true);
    }
  return (false);
}
