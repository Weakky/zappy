/*
** welcome.c for welcome in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:45:04 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:45:21 2017 Flavian DESVERNE
*/

#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include "client.h"
#include "client_functions.h"
#include "error.h"

static bool	client_not_connected(t_client *client)
{
  if (client->server_sockfd < 0)
    {
      print_error("Client is not connected yet");
      return (true);
    }

  return (false);
}

void		welcome(t_client *client)
{
  ssize_t	len;
  size_t 	size;
  char		*line;
  int		i;

  i = 0;
  if (client_not_connected(client))
    client->running = false;
  line = NULL;
  size = 0;
  signal(SIGPIPE, SIG_IGN);
  errno = 0;
  while (i < 3 && (len = getline(&line, &size, client->fs)) != -1)
    {
      line[len - 1] = '\0';
      if (!(strcmp("WELCOME", line)))
	send(client->server_sockfd, client->arg->name,
	     strlen(client->arg->name), 0);
      ++i;
      size = 0;
      free(line);
      line = NULL;
    }
  if (errno == EPIPE || i != 3)
    client->running = false;
}
