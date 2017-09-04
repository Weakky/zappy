/*
** broadcast_message_survive.c for message_survive in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:29:20 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:29:25 2017 Flavian DESVERNE
*/

#include "client.h"
#include "broadcast.h"

bool	broadcast_message_go_to_survive(t_client *client,
					char **response,
					char __attribute__((unused))
					direction)
{
  long	leader_uid;

  if (!response || !(*response))
    return (false);
  leader_uid = atol(*response);
  if (leader_uid != client->player->leader_uid ||
      client->player->is_leader)
    return (false);
  if (client->player->state == JOIN_LEADER ||
      client->player->state == WAITING_TO_EVOLVE)
    client->player->state = SURVIVING;
  broadcast_send_ask_inventory(client);
  return (true);
}
