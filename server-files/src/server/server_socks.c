/*
** server_socks.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:16:12 2017 clément
** Last update Fri Jun  9 14:17:29 2017 clément
*/

#include	"list.h"
#include	"server.h"
#include	"socket.h"

int		server_delete_socket(t_server *server, const int sockfd)
{
  t_socket	*socket;

  while (server->socks->node)
    {
      socket = server->socks->node->data;
      if (socket->sockfd == sockfd)
	{
	  list_delete_node(server->socks, delete_socket,
			   server->socks->first);
	  server->socks->node = server->socks->first;
	  return (0);
	}
      server->socks->node = server->socks->node->next;
    }
  server->socks->node = server->socks->first;
  return (-1);
}

int		server_delete_egg(t_server *server, const int id)
{
  t_egg		*egg;

  while (server->eggs->node)
    {
      egg = server->eggs->node->data;
      if (egg->id == id)
	{
	  list_delete_node(server->eggs, free, server->eggs->first);
	  server->eggs->node = server->eggs->first;
	  return (0);
	}
      server->eggs->node = server->eggs->node->next;
    }
  server->eggs->node = server->eggs->first;
  return (-1);
}