/*
** player.c for player in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:35:29 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:35:30 2017 Flavian DESVERNE
*/

#include <string.h>
#include "client.h"

t_player		*init_player(t_client *client)
{
  const t_player	template = {NULL, {{NULL, 0}, {NULL, 0},
					   {NULL, 0}, {NULL, 0},
					   {NULL, 0}, {NULL, 0}, {NULL, 0}},
				    init_requisite(), list_create(),
				    list_create(), SURVIVING,
				    {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, 0, 0},
				    0, {0, 0, 0, 0, 0, 0}, 1, true, false,
				    false, -1, 0};
  t_player		*new;
  t_team_player		*team_player;
  int			i;

  if (!(new = calloc(1, sizeof(t_player))))
    return (NULL);
  memcpy(new, &template, sizeof(t_player));
  i = -1;
  while (++i < 7)
    new->drones[i].team_players = list_create();
  if (!(team_player = calloc(1, sizeof(t_team_player))))
    return (NULL);
  team_player->id = client->uid;
  list_append(new->players, team_player);
  return (new);
}

void			delete_player(t_player *player)
{
  int			i;

  i = -1;
  if (player)
    {
      while (++i < 7)
	list_free(player->drones[i].team_players, free);
      if (player->requisite)
	free(player->requisite);
      if (player->players)
	list_free(player->players, free);
      if (player->friends_inventories)
	list_free(player->friends_inventories, free);
      free(player);
    }
}
