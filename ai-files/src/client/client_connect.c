/*
** client_connect.c for client_connect in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:34:44 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:38:33 2017 Flavian DESVERNE
*/

#include	<stdio.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<arpa/inet.h>
#include	"client.h"
#include	"error.h"

int			socket_connect(t_client *client)
{
  struct sockaddr_in	csin;
  struct protoent	*pe;

  csin.sin_family = AF_INET;
  csin.sin_port = htons((uint16_t) client->arg->port);
  csin.sin_addr.s_addr = inet_addr(client->arg->machine_name);
  if (!(pe = getprotobyname("TCP"))
      || (client->server_sockfd = socket(AF_INET,
					 SOCK_STREAM, pe->p_proto)) == -1
      || connect(client->server_sockfd, (const struct sockaddr *) &csin,
		 sizeof(csin)) == -1)
    {
      print_error("failed to connect to server");
      return (-1);
    }
  return (0);
}

int			client_connect(t_client *client)
{
  if (client->server_sockfd > 0)
    {
      print_error("client is already connected");
      return (0);
    }
  if (socket_connect(client) == -1)
    return (-1);
  if (!(client->fs = fdopen(client->server_sockfd, "r")))
    return (-1);
  return (0);
}
