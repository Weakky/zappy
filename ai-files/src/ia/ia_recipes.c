/*
** ia_recipes.c for recipes in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:49:29 2017 Flavian DESVERNE
** Last update Sun Jul  2 22:03:53 2017 Flavian DESVERNE
*/

#include "client.h"
#include "ia.h"

char		*object_to_string[NB_RESOURCES] =
  {
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    "food",
  };

void		ia_empty_tile_to_evolve(t_client *client)
{
  int		j;
  e_object	*objects;

  j = -1;
  send_command(client, LOOK);
  objects = client->player->objects[0];
  while (objects[(++j)] != EMPTY)
    {
      if (objects[j] != PLAYER)
	send_command_with_arg(client, TAKE, object_to_string[objects[j]]);
    }
  send_command(client, LOOK);
}

void		ia_recipes(t_client *client)
{
  t_requisite	requisite;

  send_command(client, LOOK);
  send_command(client, INVENTORY);
  if (client->player->level == 1)
    ia_recipes_alone(client);
  else
    {
      requisite = get_requisite_for_level(client);
      ia_recipes_group(client, requisite);
    }
}
