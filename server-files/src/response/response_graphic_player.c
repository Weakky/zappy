/*
** response_graphic_player.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:34:19 2017 clément
** Last update Tue Jun 27 12:34:20 2017 clément
*/

#include	<string.h>
#include	<stdio.h>
#include	<limits.h>
#include	"socket.h"

int	response_graphic_tna(t_socket *graphic, t_team *team)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "tna %s", team->name);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_ppo(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "ppo %d %d %d %d", socket->drone->id,
	   socket->drone->pos.x, socket->drone->pos.y,
	   socket->drone->direction + 1);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_plv(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "plv %d %d", socket->drone->id,
	   socket->drone->level);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_pin(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];
  int	(*inventory)[8];

  inventory = &(socket->drone->inventory);
  snprintf(buff, PIPE_BUF, "pin %d %d %d %d %d %d %d %d %d %d",
	   socket->drone->id, socket->drone->pos.x,
	   socket->drone->pos.y, (*inventory)[FOOD],
	   (*inventory)[LINEMATE],(*inventory)[DERAUMERE],
	   (*inventory)[SIBUR], (*inventory)[MENDIANE],
	   (*inventory)[PHIRAS], (*inventory)[THYSTAME]);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_pnw(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pnw %d %d %d %d %d %s",
	   socket->drone->id, socket->drone->pos.x,
	   socket->drone->pos.y, socket->drone->direction + 1,
	   socket->drone->level, socket->drone->team->name);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
