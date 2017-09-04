/*
** broadcast_send_survive.c for send_survive in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:30:24 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:30:24 2017 Flavian DESVERNE
*/

#include <limits.h>
#include "client.h"
#include "broadcast.h"

void	broadcast_send_go_to_survive(t_client *client)
{
  char	buff[PIPE_BUF];

  client->player->l_data.frds_on_tile = 0;
  sprintf(buff, "%d,%lu", GO_TO_SURVIVE, client->uid);
  send_command_with_arg(client, BROADCAST, buff);
}
