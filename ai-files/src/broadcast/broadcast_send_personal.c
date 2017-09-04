/*
** broadcast_send_personal.c for send_personal in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:30:06 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:33:11 2017 Flavian DESVERNE
*/

#include <limits.h>
#include <string.h>
#include "broadcast.h"

void	broadcast_send_ping(t_client *client)
{
  char	buff[PIPE_BUF];

  sprintf(buff, "%d,%li,%s,%d", PING, client->uid,
	  client->arg->name, client->player->level);
  send_command_with_arg(client, BROADCAST, buff);
}

void	broadcast_send_pong(t_client *client)
{
  char	buff[PIPE_BUF];

  sprintf(buff, "%d,%li,%s,%d", PONG, client->uid,
	  client->arg->name, client->player->level);
  send_command_with_arg(client, BROADCAST, buff);
}

void	broadcast_send_going_to_evolve(t_client *client)
{
  char	buff[PIPE_BUF];
  char	temp[PIPE_BUF];
  char	friends[PIPE_BUF];
  int	i;

  bzero(friends, PIPE_BUF);
  i = -1;
  while (++i < client->player->l_data.nb_frds)
    {
      snprintf(temp, PIPE_BUF, ",%lu", client->player->l_data.friends[i]);
      strcat(friends, temp);
    }
  sprintf(buff, "%d%s", GOING_TO_EVOLVE, friends);
  send_command_with_arg(client, BROADCAST, buff);
}
