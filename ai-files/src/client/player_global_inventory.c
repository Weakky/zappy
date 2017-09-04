/*
** player_global_inventory.c for global_inventory in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:36:04 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:36:05 2017 Flavian DESVERNE
*/

#include <string.h>
#include "client.h"
#include "ia.h"

void			set_global_inventory(t_client *client)
{
  t_list_node		*tmp;
  t_player_inventory	*tmp_inv;
  int			i;
  int			j;

  i = -1;
  bzero(client->player->l_data.global_inv, sizeof(int) * 6);
  while (++i < NB_RESOURCES_NEEDED)
    client->player->l_data.global_inv[i] += client->player->inventory[i];
  i = -1;
  while (++i < client->player->l_data.nb_frds)
    {
      tmp = client->player->friends_inventories->first;
      while (tmp)
	{
	  tmp_inv = tmp->data;
	  if (tmp_inv->id == client->player->l_data.friends[i])
	    {
	      j = -1;
	      while (++j < NB_RESOURCES_NEEDED)
		client->player->l_data.global_inv[j] += tmp_inv->inventory[j];
	    }
	  tmp = tmp->next;
	}
    }
}
