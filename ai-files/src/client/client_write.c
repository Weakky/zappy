/*
** client_write.c for client_write in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:35:46 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:38:38 2017 Flavian DESVERNE
*/

#include	<limits.h>
#include	<unistd.h>
#include	<string.h>
#include	<errno.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<signal.h>
#include	"client.h"

int	client_write(t_client *client)
{
  int	nb;
  char	buff[PIPE_BUF];

  nb = 0;
  bzero(buff, PIPE_BUF);
  errno = 0;
  signal(SIGPIPE, SIG_IGN);
  while (client->buffer->pop(client->buffer, buff) != -1)
    {
      write(client->server_sockfd, buff, strlen(buff));
      if (errno == EPIPE)
	return (-1);
      ++nb;
    }
  if (errno == EPIPE)
    client->running = false;
  return (0);
}
