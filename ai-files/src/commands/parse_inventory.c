/*
** parse_inventory.c for parse_inventory in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:44:11 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:44:18 2017 Flavian DESVERNE
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "client.h"
#include "ia.h"

void			parse_inventory(t_client *client, char *response)
{
  int			i;
  int			ind;

  i = 0;
  ind = -1;
  while (response[i])
    {
      if (isdigit(response[i]))
	{
	  if (ind < 0)
	    client->player->nb_food = atoi(&(response[i]));
	  else
	    client->player->inventory[ind] = atoi(&(response[i]));
	  ind++;
	  while (response[i] && isdigit(response[i]))
	    i++;
	  if (response[i])
	    i++;
	}
      else
	i++;
    }
}

t_player_inventory	*inventory_by_id(t_client *client, long id)
{
  t_list_node		*temp;
  t_player_inventory	*inventory;

  temp = client->player->friends_inventories->first;
  while (temp)
    {
      inventory = (t_player_inventory *) temp->data;
      if (inventory->id == id)
	return (inventory);
      temp = temp->next;
    }
  return (NULL);
}

void			parse_received_inventory(t_client *client,
						 char **inventory,
						 long player_id)
{
  int			i;
  int			index;
  int			tmp_inventory[6];
  t_player_inventory	*new_inventory;

  i = 2;
  index = 0;
  while (index < NB_RESOURCES_NEEDED)
    {
      tmp_inventory[index] = atoi(inventory[i]);
      index++;
      i++;
    }
  if ((new_inventory = inventory_by_id(client, player_id)) != NULL)
    memcpy(new_inventory->inventory, tmp_inventory, 6 * sizeof(int));
  else
    {
      new_inventory = calloc(1, sizeof(t_player_inventory));
      new_inventory->id = player_id;
      memcpy(new_inventory->inventory, tmp_inventory, 6 * sizeof(int));
      list_append(client->player->friends_inventories, new_inventory);
    }
}
