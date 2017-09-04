/*
** response_graphic_die.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:33:45 2017 clément
** Last update Tue Jun 27 12:33:46 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	"socket.h"

int	response_graphic_pdi(t_socket *graphic, t_socket *socket)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pdi %d", socket->drone->id);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
