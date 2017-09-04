/*
** server_update_time.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:56:23 2017 clément
** Last update Tue Jun 27 12:56:23 2017 clément
*/

#include	<stdio.h>
#include	<sys/time.h>
#include	"server.h"

int			server_update_time(t_server *server)
{
  struct timeval	now;
  double		diff;
  long			now_to_int;
  long			last_to_int;

  gettimeofday(&now, NULL);
  now_to_int = now.tv_sec * 1000000 + now.tv_usec;
  last_to_int = server->last_update.tv_sec
		* 1000000 + server->last_update.tv_usec;
  diff = ((double) now_to_int - (double) last_to_int) / 1000000.0f;
  server->last_update = now;
  server->time_unit += diff;
  return (0);
}
