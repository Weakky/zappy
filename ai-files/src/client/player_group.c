/*
** player_group.c for player_group in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:36:22 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:36:26 2017 Flavian DESVERNE
*/

#include "client.h"

bool		has_player_in_group(t_client *client, long id)
{
  t_list_node	*temp;
  t_team_player	*player;

  temp = client->player->players->first;
  while (temp)
    {
      player = (t_team_player *) temp->data;
      if (player->id == id)
	return (true);
      temp = temp->next;
    }
  return (false);
}

bool		am_i_part_of_group(t_client *client,
				   char **response,
				   int start)
{
  while (response[start])
    {
      if (client->uid == atol(response[start]))
	return (true);
      start++;
    }
  return (false);
}
