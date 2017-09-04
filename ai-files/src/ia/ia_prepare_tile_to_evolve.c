/*
** ia_prepare_tile_to_evolve.c for prepare_tile in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:48:43 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:48:55 2017 Flavian DESVERNE
*/

#include "client.h"
#include "ia.h"
#include "broadcast.h"

static bool	is_tile_empty(t_client *client)
{
  int		i;

  i = 0;
  while (client->player->objects[0][i] != EMPTY)
    {
      if (client->player->objects[0][i] != FOOD &&
	  client->player->objects[0][i] != PLAYER)
	return (false);
      i++;
    }
  return (true);
}

static bool	can_evolve_alone(t_client *client, t_requisite requisite)
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

bool		prepare_tile_to_evolve(t_client *client, t_requisite *req)
{
  if (client->player->level > 1 &&
      client->player->is_small_leader)
    {
      printf("Can evolve with friend !\n");
      if (!can_evolve_alone(client, (*req)))
	printf("But not alone.. %d\n", client->player->asked_player_for_res);
      if (client->player->l_data.frds_on_tile < client->player->l_data.nb_frds)
	{
	  printf("JOIN ME PLEASE\n");
	  broadcast_send_join_me(client);
	}
      if (!is_tile_empty(client))
	{
	  ia_empty_tile_to_evolve(client);
	  return (false);
	}
    }
  return (true);
}
