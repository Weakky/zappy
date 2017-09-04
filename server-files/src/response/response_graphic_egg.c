/*
** response_graphic_egg.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:33:52 2017 clément
** Last update Tue Jun 27 12:33:53 2017 clément
*/

#include	<string.h>
#include	<stdio.h>
#include	"socket.h"

int	response_graphic_pfk(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pfk %d", socket->drone->id);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_enw(t_socket *graphic, t_egg *egg)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "enw %d %d %d %d", egg->id, egg->elid,
	   egg->pos.x, egg->pos.y);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_eht(t_socket *graphic, t_egg *egg)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "eht %d", egg->id);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_ebo(t_socket *graphic, t_egg *egg)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "ebo %d %d %d %d", egg->id, egg->elid,
	   egg->pos.x, egg->pos.y);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int	response_graphic_edi(t_socket *graphic, t_egg *egg)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "edi %d", egg->id);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
