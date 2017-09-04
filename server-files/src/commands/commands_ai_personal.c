/*
** commands_ai_personal.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:57 2017 clément
** Last update Tue Jun 27 11:10:58 2017 clément
*/

#include	<limits.h>
#include	<stdio.h>
#include	<string.h>
#include	"action.h"

int	commands_ai_inventory(t_socket *socket,
			      char __attribute__((unused)) *arg)
{
  socket->drone->action.action = action_ai_inventory;
  socket->drone->set_waiting(socket->drone, 1);
  return (0);
}

int	commands_ai_connect_nbr(t_socket *socket,
				char __attribute__((unused)) *arg)
{
  char	buff[PIPE_BUF];

  sprintf(buff, "%d", socket->server->argument->nclients
	  - socket->drone->team->nmember);
  socket->bwrite->push(socket->bwrite, buff, strlen(buff));
  return (0);
}
