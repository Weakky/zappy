/*
** commands_graphic_player.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:11:46 2017 clément
** Last update Tue Jun 27 11:11:47 2017 clément
*/

#include	<stdio.h>
#include	<ctype.h>
#include	"response.h"
#include	"utils.h"

static t_socket	*find_socket_by_id(t_list *socks, int id)
{
  t_list_node	*temp;
  t_socket	*socket;

  temp = socks->first;
  while (temp)
    {
      socket = (t_socket *) temp->data;
      if (socket->type == AI && socket->drone->id == id)
	return (socket);
      temp = temp->next;
    }
  return (NULL);
}

int		commands_graphic_tna(t_socket *socket,
				     char __attribute__((unused)) *arg)
{
  int		i;

  i = -1;
  while (++i < socket->server->argument->nteam)
    response_graphic_tna(socket, &(socket->server->argument->teams[i]));
  return (0);
}

int		commands_graphic_ppo(t_socket *socket, char *arg)
{
  int		i;
  int		id;
  t_socket	*searched;

  i = -1;
  if (!arg)
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  my_trim(arg);
  id = atoi(arg);
  while (arg[++i])
    if (!isdigit(arg[i]))
      return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  if (!(searched = find_socket_by_id(socket->server->socks, id)))
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  response_graphic_ppo(socket, searched);
  return (0);
}

int		commands_graphic_plv(t_socket *socket, char *arg)
{
  int		i;
  int		id;
  t_socket	*searched;

  i = -1;
  if (!arg)
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  my_trim(arg);
  id = atoi(arg);
  while (arg[++i])
    if (!isdigit(arg[i]))
      return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  if (!(searched = find_socket_by_id(socket->server->socks, id)))
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  response_graphic_plv(socket, searched);
  return (0);
}


int		commands_graphic_pin(t_socket *socket, char *arg)
{
  int		i;
  int		id;
  t_socket	*searched;

  i = -1;
  if (!arg)
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  my_trim(arg);
  id = atoi(arg);
  while (arg[++i])
    if (!isdigit(arg[i]))
      return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  if (!(searched = find_socket_by_id(socket->server->socks, id)))
    return (socket->bwrite->push(socket->bwrite, "sbp", 3));
  response_graphic_pin(socket, searched);
  return (0);
}
