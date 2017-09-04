/*
** client_socket.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:22:43 2017 clément
** Last update Fri Jun  9 14:24:32 2017 clément
*/

#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<string.h>
#include	<limits.h>
#include	"socket_functions.h"

t_socket		*init_client_socket(t_server *server,
					    t_socket *server_socket)
{
  t_socket		*new;
  struct sockaddr_in	csin;
  socklen_t		cslen;
  static const t_socket	template = {NULL, NULL, NULL, NULL, 0, false, NULL,
				    NULL, 0, UNKNOWN, client_socket_read,
				    client_socket_write,
				    client_socket_execute};

  cslen = sizeof(csin);
  if (!(new = calloc(1, sizeof(t_socket))))
    return (NULL);
  memcpy(new, &template, sizeof(t_socket));
  if (!(new->bwrite = init_circular_buffer(1000, PIPE_BUF))
      || !(new->bread = init_circular_buffer(10, PIPE_BUF)))
    return (NULL);
  if ((new->sockfd = accept(server_socket->sockfd,
			    (struct sockaddr *) &csin, &cslen)) == -1)
    {
      free(new);
      return (NULL);
    }
  commands_set_unknown(new);
  new->server = server;
  new->bwrite->push(new->bwrite, "WELCOME", 7);
  return (new);
}
