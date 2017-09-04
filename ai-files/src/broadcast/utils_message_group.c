/*
** utils_message_group.c for utils_message_group in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:30:41 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:30:42 2017 Flavian DESVERNE
*/

#include "client.h"
#include "broadcast.h"

bool	define_leader(t_client *client, char **response, long leader_id)
{
  if (leader_id == client->uid)
    {
      printf("I AM A SMALL LEADER\n");
      client->player->is_small_leader = true;
      client->player->state = RECIPES;
    }
  if (am_i_part_of_group(client, response, 3) &&
      !(client->player->is_small_leader))
    {
      printf("MY LEADER IS: %lu\n", leader_id);
      client->player->leader_uid = leader_id;
      client->player->state = RECIPES;
      broadcast_send_ask_inventory(client);
    }
  return (true);
}

void	join_leader(t_client *client, char direction)
{
  if ((direction == 1) || (direction == 2) || direction == 8)
    send_command(client, FORWARD);
  else if (direction == 4 || direction == 3)
    {
      send_command(client, LEFT);
      send_command(client, FORWARD);
    }
  else if (direction == 6 || direction == 7)
    {
      send_command(client, RIGHT);
      send_command(client, FORWARD);
    }
  else if (direction == 5)
    {
      send_command(client, LEFT);
      send_command(client, LEFT);
      send_command(client, FORWARD);
    }
}
