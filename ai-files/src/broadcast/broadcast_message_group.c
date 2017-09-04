/*
** broadcast_message_group.c for message_group in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:28:24 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:31:22 2017 Flavian DESVERNE
*/

#include <string.h>
#include "ia.h"
#include "broadcast.h"

bool	broadcast_message_make_group(t_client *client,
				     char **response,
				     char __attribute__((unused))
				     direction)
{
  int	i;
  char	*team_name;
  long	leader_id;
  int	level;

  i = -1;
  while (response[++i]);
  if (i < 3)
    return (false);
  team_name = response[0];
  level = atoi(response[1]);
  leader_id = atol(response[2]);
  i = 2;
  if (strcmp(team_name, client->arg->name) != 0)
    return (false);
  while (response[i])
    {
      if (leader_id == client->uid && client->uid != atol(response[i]))
	client->player->l_data.friends[(client->player->l_data.nb_frds++)]
	  = atol(response[i]);
      remove_player_from_whitelist(client, level, atol(response[i]));
      i++;
    }
  return (define_leader(client, response, leader_id));
}

bool	broadcast_message_ask_inventory(t_client *client,
					char **response,
					char __attribute__((unused))
					direction)
{
  long	player_id;
  int	i;

  i = -1;
  while (response[++i]);
  if (i < 8)
    return (false);
  player_id = atol(response[1]);
  if (strcmp(response[0], client->arg->name) != 0)
    return (false);
  parse_received_inventory(client, response, player_id);
  return (true);
}

bool	broadcast_message_set_object(t_client *client,
				     char **response,
				     char __attribute__((unused))
				     direction)
{
  long	player_id;
  int	i;

  player_id = atol(response[0]);
  if (player_id == client->uid)
    {
      i = 1;
      while (response[i])
	{
	  printf("SET %s\n", object_to_string[atoi(response[i])]);
	  send_command_with_arg(client,
				SET,
				object_to_string[atoi(response[i])]);
	  i++;
	}
    }
  return (true);
}

bool	broadcast_message_join_me(t_client *client, char **response,
				  char __attribute__((unused))
				  direction)
{
  if (strcmp(client->arg->name, response[0]) != 0)
    return (false);
  if (!am_i_part_of_group(client, response, 1))
    return (false);
  if (direction == 0 &&
      client->player->state != WAITING_TO_EVOLVE)
    {
      broadcast_send_i_am_here(client);
      client->player->state = WAITING_TO_EVOLVE;
      return (true);
    }
  if (client->player->state != JOIN_LEADER &&
      client->player->state != RECIPES)
    return (false);
  join_leader(client, direction);
  if (client->player->state != WAITING_TO_EVOLVE)
    client->player->state = JOIN_LEADER;
  return (true);
}

bool	broadcast_message_i_am_here(t_client *client,
				    char **response,
				    char __attribute__((unused))
				    direction)
{
  if (strcmp(client->arg->name, response[0]) != 0)
    return (false);
  if (client->uid == atol(response[1]) && client->player->is_small_leader)
    {
      client->player->l_data.frds_on_tile++;
    }
  return (true);
}
