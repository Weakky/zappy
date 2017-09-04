/*
** client_socket_read.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:27:40 2017 clément
** Last update Fri Jun  9 14:30:04 2017 clément
*/

#include	<limits.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/socket.h>
#include	<signal.h>
#include	<errno.h>
#include	"utils.h"
#include	"socket.h"
#include	"socket_functions.h"

int		client_socket_read(t_socket *socket)
{
  char		res[PIPE_BUF];
  char		**lsplit;
  ssize_t	len;
  int		i;

  signal(SIGPIPE, SIG_IGN);

  if ((len = recv(socket->sockfd, res, PIPE_BUF, 0)) < 0)
    socket->to_delete = true;
  if (errno == EPIPE)
    socket->to_delete = true;
  if (socket->to_delete)
    return (-1);
  res[len] = '\0';
  if (!(lsplit = my_split(res, "\n")))
    return (-1);
  i = -1;
  while (lsplit[++i])
    {
      socket->bread->push(socket->bread, lsplit[i], strlen(lsplit[i]));
      free(lsplit[i]);
    }
  free(lsplit);
  return (0);
}
