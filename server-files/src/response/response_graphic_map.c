/*
** response_graphic_map.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:34:12 2017 clément
** Last update Tue Jun 27 12:34:13 2017 clément
*/

#include	<limits.h>
#include	<string.h>
#include	<stdio.h>
#include	"server.h"
#include	"socket.h"

int	response_graphic_msz(t_socket *graphic)
{
  char	buff[PIPE_BUF];

  sprintf(buff, "msz %d %d",
	  graphic->server->argument->width,
	  graphic->server->argument->height);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_bct(t_socket *graphic, int x, int y)
{
  char	buff[PIPE_BUF];
  int	(*elms)[8];

  elms = &(graphic->server->map[y * graphic->server->argument->width + x]);
  sprintf(buff, "bct %d %d %d %d %d %d %d %d %d", x, y,
	  (*elms)[FOOD], (*elms)[LINEMATE], (*elms)[DERAUMERE],
	  (*elms)[SIBUR], (*elms)[MENDIANE], (*elms)[PHIRAS],
	  (*elms)[THYSTAME]);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_seg(t_socket *graphic, t_server *server)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF,
	   "seg %s", server->winning_team->name);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
