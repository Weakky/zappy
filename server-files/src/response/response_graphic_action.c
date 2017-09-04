/*
** response_graphic_action.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:33:39 2017 clément
** Last update Tue Jun 27 12:33:40 2017 clément
*/

#include	<string.h>
#include	<limits.h>
#include	<stdio.h>
#include	"socket.h"

int	response_graphic_pex(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pex %d", socket->drone->id);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_pbc(t_socket *graphic,
			     t_socket *socket, char *message)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pbc %d %s", socket->drone->id, message);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_pdr(t_socket *graphic, t_socket *socket,
			     e_objects resource)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pdr %d %d", socket->drone->id, resource - 1);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_pgt(t_socket *graphic, t_socket *socket,
			     e_objects resource)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pgt %d %d", socket->drone->id, resource - 1);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
