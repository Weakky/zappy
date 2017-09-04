/*
** client_socket_write.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:30:15 2017 clément
** Last update Fri Jun  9 14:31:09 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	<limits.h>
#include	<sys/socket.h>
#include	<signal.h>
#include	<errno.h>
#include	"socket.h"

int	client_socket_write(t_socket *socket)
{
  char	message[PIPE_BUF];
  int	i;
  int	nmsg;

  i = -1;
  nmsg = (int) socket->bwrite->count;
  signal(SIGPIPE, SIG_IGN);
  errno = 0;
  while (++i < nmsg && socket->bwrite->pop(socket->bwrite, &message) == 0)
    {
      strncat(message, "\n", PIPE_BUF);
      send(socket->sockfd, message,
	   strlen(message), 0);
      if (errno == EPIPE)
	  socket->to_delete = true;
    }
  return (0);
}
