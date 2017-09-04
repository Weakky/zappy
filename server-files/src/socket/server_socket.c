/*
** server_socket.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:48:20 2017 clément
** Last update Wed Jun 28 13:39:58 2017 clément
*/

#include	<sys/socket.h>
#include	<netdb.h>
#include	<string.h>
#include	"socket.h"

static int		server_socket_read(t_socket *socket)
{
  t_socket		*new_client;
  t_socket		*server_socket;

  server_socket = socket->server->socks->first->data;
  if (!server_socket)
    return (-1);
  if (!(new_client = init_client_socket(socket->server, server_socket)))
    return (-1);
  list_append(socket->server->socks, new_client);
  if (new_client->sockfd >= socket->server->nfds)
    socket->server->nfds = new_client->sockfd + 1;
  return (0);
}

static int		enable_reuse_addr(t_socket *server)
{
  int			enable;

  enable = 1;
  if (setsockopt(server->sockfd, SOL_SOCKET, SO_REUSEADDR,
		 &enable, sizeof(int)) == -1)
    return (-1);
  return (0);
}

t_socket		*init_server_socket(const int port, t_server *server)
{
  t_socket		*new;
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  static const t_socket	template = {NULL, NULL, NULL, NULL, 0,
				    false, NULL, NULL, 0,
				    SERVER, server_socket_read, NULL, NULL};

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons((uint16_t) port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (!(pe = getprotobyname("TCP"))
      || !(new = calloc(sizeof(t_socket), 1)))
    return (NULL);
  memcpy(new, &template, sizeof(t_socket));
  if ((new->sockfd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1
      || enable_reuse_addr(new) == -1
      || bind(new->sockfd, (const struct sockaddr *) &s_in, sizeof(s_in)) == -1
      || listen(new->sockfd, 100) == -1)
    {
      free(new);
      return (NULL);
    }
  new->server = server;
  return (new);
}
