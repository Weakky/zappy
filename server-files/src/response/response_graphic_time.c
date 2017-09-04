/*
** response_graphic_time.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:34:26 2017 clément
** Last update Tue Jun 27 12:34:27 2017 clément
*/

#include	<string.h>
#include	<limits.h>
#include	<stdio.h>
#include	"socket.h"

int	response_graphic_sgt(t_socket *graphic)
{
  char	buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "sgt %lu",
	   (unsigned long) graphic->server->argument->frequency);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
