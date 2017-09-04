/*
** ia_recipes_group.c for recipes_group in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:50:50 2017 Flavian DESVERNE
** Last update Sun Jul  2 22:06:05 2017 Flavian DESVERNE
*/

#include "client.h"
#include "ia.h"
#include "broadcast.h"

static bool	can_evolve_with_friends(t_client *client,
					t_requisite requisite)
{
  int		i;

  i = -1;
  while (++i < NB_RESOURCES_NEEDED)
    {
      if (client->player->l_data.global_inv[i] < requisite.resources[i])
	return (false);
    }
  return (true);
}

bool		can_evolve_alone(t_client *client, t_requisite requisite)
{
  int		i;

  i = -1;
  while (++i < NB_RESOURCES_NEEDED)
    {
      if (client->player->inventory[i] < requisite.resources[i])
	return (false);
    }
  return (true);
}

static void	set_object_to_incant(t_client *client, t_requisite requisite)
{
  int		i;
  int		res_to_set;

  i = -1;
  while (++i < NB_RESOURCES_NEEDED)
    {
      res_to_set = requisite.resources[i];
      while (res_to_set > 0)
	{
	  send_command_with_arg(client, SET, object_to_string[i]);
	  res_to_set--;
	}
    }
}

void		ia_recipes_group(t_client *client, t_requisite requisite)
{
  set_global_inventory(client);
  if (!can_evolve_with_friends(client, requisite))
    {
      ia_find_resources_to_evolve(client, requisite);
      return ;
    }
  if (!prepare_tile_to_evolve(client, &requisite))
    return ;
  if (client->player->level > 1 &&
      client->player->is_small_leader &&
      client->player->l_data.frds_on_tile == client->player->l_data.nb_frds)
    {
      if (can_evolve_alone(client, requisite))
	{
	  set_object_to_incant(client, requisite);
	  broadcast_send_going_to_evolve(client);
	  send_command(client, INCANT);
	}
      else if (!(client->player->asked_player_for_res))
	{
	  printf("ENOUGH PLAYER ON TILE, PLEASE SET OBJECTS TO INCANT\n");
	  client->player->asked_player_for_res = true;
	  ia_ask_for_needed_res(client, requisite);
	}
    };
}
