/*
** ia_recipes_alone.c for recipes_alone in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:49:14 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:49:15 2017 Flavian DESVERNE
*/

#include "client.h"
#include "ia.h"

static bool	can_evolve_alone(t_client *client)
{
  return (client->player->inventory[LINEMATE] >= 1);
}

static bool	is_tile_empty(t_client *client)
{
  int		i;

  i = 1;
  while (client->player->objects[0][i] != EMPTY)
    {
      if (client->player->objects[0][i] != FOOD)
	return (false);
      i++;
    }
  return (true);
}

void		ia_recipes_alone(t_client *client)
{
  t_requisite	requisite;

  if (can_evolve_alone(client))
    {
      ia_empty_tile_to_evolve(client);
      if (is_tile_empty(client))
	{
	  send_command_with_arg(client, SET, "linemate");
	  send_command(client, INCANT);
	  send_command(client, LOOK);
	  send_command(client, INVENTORY);
	}
      else
	{
	  send_command(client, (rand() % 10 > 5) ? (LEFT) : (RIGHT));
	  send_command(client, FORWARD);
	}
      return ;
    }
  requisite = get_requisite_for_level(client);
  ia_find_resources_to_evolve(client, requisite);
}
