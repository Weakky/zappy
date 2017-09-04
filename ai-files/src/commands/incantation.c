/*
** incantation.c for incantation in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:43:06 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:43:34 2017 Flavian DESVERNE
*/

#include <string.h>
#include <values.h>
#include <stdio.h>
#include "broadcast.h"

static void	send_level_up(t_client *client)
{
  char		buff[PIPE_BUF];

  sprintf(buff, "%d,%s,%d,%li", LVL_UP,
	  client->arg->name, client->player->level, client->uid);
  send_command_with_arg(client, BROADCAST, buff);
}

void		handle_level_up(t_client *client)
{
  client->player->is_small_leader = false;
  bzero(client->player->l_data.friends, 5 * sizeof(int));
  client->player->l_data.nb_frds = 0;
  client->player->leader_uid = -1;
  bzero(client->player->l_data.global_inv, 6 * sizeof(int));
  client->player->l_data.frds_on_tile = 0;
  client->player->asked_player_for_res = false;
  client->player->state = SURVIVING;
  send_level_up(client);
  add_player_to_whitelist(client, client->player->level, client->uid);
}

bool		handle_incantation_second(t_client *client, char *response)
{
  size_t	skip;

  skip = strlen("Current level: ");
  printf("incantation: %s\n", response);
  if (strncmp(response, "Current level: ", skip) == 0)
    {
      client->player->level = atoi(response + skip);
      handle_level_up(client);
      printf("LEVEL UP %d\n", client->player->level);
      return (true);
    }
  return (false);
}

static int	send_go_back_to_whitelist(t_client *client)
{
  char		buff[PIPE_BUF];
  char		temp[PIPE_BUF];
  char		friends[PIPE_BUF];
  int		i;

  bzero(friends, PIPE_BUF);
  if (client->player->is_small_leader && client->player->level > 1)
    {
      i = -1;
      while (++i < client->player->l_data.nb_frds)
	{
	  snprintf(temp, PIPE_BUF, ",%lu", client->player->l_data.friends[i]);
	  strcat(friends, temp);
	}
      sprintf(buff, "%d%s", GO_BACK_TO_WHITELIST, friends);
      send_command_with_arg(client, BROADCAST, buff);
    }
  return (0);
}

bool		incantation(t_client *client, char *response, char *arg)
{
  (void)client;
  (void)arg;
  if (strcmp(response, "ko") == 0)
    {
      printf("INCANTATION FAILED\n");
      if (client->player->level > 1)
	{
	  send_go_back_to_whitelist(client);
	  handle_level_up(client);
	}
      else
	client->player->state = RECIPES;
    }
  else if (strcmp(response, "Elevation underway") == 0)
    {
      client->command.exec_cmd = incantation;
      client->command.arg = NULL;
      client->command.name = INCANT;
      client->player->state = WAITING_TO_EVOLVE;
      client->read(client);
    }
  else
    handle_incantation_second(client, response);
  return (true);
}
