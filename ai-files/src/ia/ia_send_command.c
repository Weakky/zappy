/*
** ia_send_command.c for send_command in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:51:23 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:51:41 2017 Flavian DESVERNE
*/

#include <string.h>
#include <stdio.h>
#include <values.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include "client.h"
#include "client_functions.h"

static const char	*command_to_string[13] =
  {
    "Look",
    "Forward",
    "Right",
    "Left",
    "Inventory",
    "Broadcast",
    "Connect_nbr",
    "Fork",
    "Eject",
    "Take",
    "Set",
    "Incantation",
  };

static const t_exec_cmd	command_to_function[13] = {
  look,
  check_ok,
  check_ok,
  check_ok,
  inventory,
  check_ok,
  connect_nbr,
  check_ok,
  check_ok,
  take_object,
  set_object,
  incantation,
};

void	set_command(t_client *client, e_command command, char *arg)
{
  client->command.name = command;
  client->command.arg = arg;
  client->command.exec_cmd = command_to_function[command];
}

void	send_command_with_arg(t_client *client, e_command command, char *arg)
{
  char	buff[PIPE_BUF];

  if (!client->running)
    return ;
  if (arg)
    sprintf(buff, "%s %s\n", command_to_string[command], arg);
  else
    sprintf(buff, "%s\n", command_to_string[command]);
  signal(SIGPIPE, SIG_IGN);
  send(client->server_sockfd, buff, strlen(buff), 0);
  set_command(client, command, arg);
  client->command.exec_cmd = command_to_function[command];
  if (arg)
    client->command.arg = strdup(arg);
  client->command.name = command;
  client->read(client);
}

void	send_command(t_client *client, e_command cmd)
{
  send_command_with_arg(client, cmd, NULL);
}
