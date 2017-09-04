/*
** client_read.c for client_read in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:39:17 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:39:18 2017 Flavian DESVERNE
*/

#include	<stdio.h>
#include	<errno.h>
#include	<signal.h>
#include	<string.h>
#include	<utils.h>
#include	"broadcast.h"
#include	"client_functions.h"
#include 	"error.h"

static bool	client_not_connected(t_client *client)
{
  if (client->server_sockfd < 0)
    {
      print_error("Client is not connected yet");
      return (true);
    }

  return (false);
}

static void	handle_line(t_client *client, char *line, bool *keep_reading)
{
  if (!strcmp(line, "dead"))
    {
      client->running = false;
      *keep_reading = false;
      return ;
    }
  else if (!handle_broadcast(client, line, keep_reading))
    {
      client->command.exec_cmd(client, line, client->command.arg);
      if (client->command.arg)
	{
	  free(client->command.arg);
	  client->command.arg = NULL;
	}
      *keep_reading = false;
    }
}

static void		init_client_read(size_t *size,
					 char **line,
					 bool *keep_reading)
{
  (*line) = NULL;
  (*size) = 0;
  signal(SIGPIPE, SIG_IGN);
  errno = 0;
  (*keep_reading) = true;
}

int		client_read(t_client *client)
{
  ssize_t	len;
  size_t 	size;
  char		*line;
  bool		keep_reading;

  if (client_not_connected(client))
    return (0);
  init_client_read(&size, &line, &keep_reading);
  while (client->running && keep_reading &&
	 (len = getline(&line, &size, client->fs)) != -1)
    {
      line[len - 1] = '\0';
      handle_line(client, line, &keep_reading);
      free(line);
      line = NULL;
      size = 0;
      if (!client->command.exec_cmd)
	return (0);
    }
  if (errno == EPIPE)
    client->running = false;
  else if (line)
    free(line);
  return (0);
}
