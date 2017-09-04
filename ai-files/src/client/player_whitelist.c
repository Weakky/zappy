/*
** player_whitelist.c for player_whitelist in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:36:39 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:36:44 2017 Flavian DESVERNE
*/

#include "client.h"

t_team_player	*add_player_to_whitelist(t_client *client, int level, long id)
{
  t_team_player	*player;

  if (!(player = calloc(sizeof(t_team_player), 1)))
    return (NULL);
  player->id = id;
  if (level > 1)
    {
      list_append(client->player->drones[(level - 1)].team_players, player);
      client->player->drones[(level - 1)].nb_ids++;
    }
  return (player);
}

void		remove_player_from_whitelist(t_client *client,
					     int level,
					     long id)
{
  t_list	*list;
  t_list_node	*tmp;
  t_team_player	*tmp_player;

  list = client->player->drones[level - 1].team_players;
  tmp = list->first;
  while (tmp)
    {
      tmp_player = tmp->data;
      if (tmp_player->id == id)
	{
	  list->node = tmp;
	  list_delete_node(list, free, list->first);
	  client->player->drones[level - 1].nb_ids--;
	  return ;
	}
      tmp = tmp->next;
    }
}
