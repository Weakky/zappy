/*
** server.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:14:58 2017 clément
** Last update Wed Jun 28 17:25:18 2017 clément
*/

#include	<string.h>
#include	<stdio.h>
#include	<sys/time.h>
#include	"argument.h"
#include	"server_functions.h"
#include	"socket.h"

t_server		*init_server(t_argument argument)
{
  t_server		*new;
  t_socket		*server_socket;
  static const t_server	templ = {NULL, NULL, NULL, NULL, NULL, 0, 0, {0, 0},
				 0, 0, 0, server_wait, server_update_time,
				 server_have_to_update, server_update};

  if (!(new = calloc(sizeof(t_server), 1)))
    return (NULL);
  memcpy(new, &templ, (sizeof(t_server)));
  if (!(server_socket = init_server_socket(argument.port, new))
      || !(new->argument = calloc(sizeof(t_argument), 1))
      || server_generate_map(new, argument) == -1)
    {
      free(new);
      return (NULL);
    }
  memcpy(new->argument, &argument, sizeof(t_argument));
  new->socks = list_create();
  new->eggs = list_create();
  gettimeofday(&new->last_update, NULL);
  server_socket->server = new;
  list_append(new->socks, server_socket);
  new->nfds = server_socket->sockfd + 1;
  new->update_to = UPDATE_TIME_UNIT / argument.frequency;
  return (new);
}

void			delete_server(t_server *server)
{
  if (server)
    {
      list_free(server->socks, delete_socket);
      list_free(server->eggs, free);
      free(server->map);
      free(server->argument->teams);
      free(server);
    }
}
