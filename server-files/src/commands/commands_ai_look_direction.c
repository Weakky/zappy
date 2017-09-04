/*
** commands_ai_look_direction.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:40 2017 clément
** Last update Tue Jun 27 11:10:41 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	"socket.h"

int		commands_ai_look_up(int (*dest)[8], t_socket *socket,
				    t_position init, int curent_level)
{
  int		i;
  int		j;
  t_position	current;

  if (curent_level > (int) socket->drone->level)
    return (-1);
  i = -1;
  j = MAX((curent_level -1) * 2 + 1, 0);
  current = init;
  while (++i < curent_level * 2 + 1)
    {
      memcpy(dest[j++],
	     socket->server->map[current.y * socket->server->argument->width
				 + current.x], sizeof(int[8]));
      current.x = (current.x + 1) % socket->server->argument->width;
    }
  init.x--;
  init.y--;
  commands_ai_adjust_position(
			      &init, socket->server->argument->width,
			      socket->server->argument->height);
  commands_ai_look_up(dest, socket, init, ++curent_level);
  return (0);
}

int		commands_ai_look_right(int (*dest)[8], t_socket *socket,
				       t_position init, int curent_level)
{
  int 		i;
  int 		j;
  t_position	current;

  if (curent_level > (int) socket->drone->level)
    return (-1);
  i = -1;
  j = MAX((curent_level -1) * 2 + 1, 0);
  current = init;
  while (++i < curent_level * 2 + 1)
    {
      memcpy(dest[j++],
	     socket->server->map[current.y * socket->server->argument->width
				 +  current.x], sizeof(int[8]));
      current.y = (current.y + 1) % socket->server->argument->height;
    }
  init.x++;
  init.y--;
  commands_ai_adjust_position(
			      &init, socket->server->argument->width,
			      socket->server->argument->height);
  commands_ai_look_right(dest, socket, init, ++curent_level);
  return (0);
}

int		commands_ai_look_down(int (*dest)[8], t_socket *socket,
				      t_position init, int curent_level)
{
  int		i;
  int 		j;
  t_position	current;

  if (curent_level > (int) socket->drone->level)
    return (-1);
  i = -1;
  j = MAX((curent_level -1) * 2 + 1, 0);
  current = init;
  while (++i < curent_level * 2 + 1)
    {
      memcpy(dest[j++],
	     socket->server->map[current.y * socket->server->argument->width
				 + current.x], sizeof(int[8]));
      current.x = (current.x == 0) ?
	(socket->server->argument->width - 1) : (current.x - 1);

    }
  init.x++;
  init.y++;
  commands_ai_adjust_position(
			      &init, socket->server->argument->width,
			      socket->server->argument->height);
  commands_ai_look_down(dest, socket, init, ++curent_level);
  return (0);
}

int 		commands_ai_look_left(int (*dest)[8], t_socket *socket,
				      t_position init, int curent_level)
{
  int		i;
  int		j;
  t_position	current;

  if (curent_level > (int) socket->drone->level)
    return (-1);
  i = -1;
  j = MAX((curent_level -1) * 2 + 1, 0);
  current = init;
  while (++i < curent_level * 2 + 1)
    {
      memcpy(dest[j++],
	     socket->server->map[current.y * socket->server->argument->width
				 + current.x],
	     sizeof(int[8]));
      current.y = (current.y == 0) ?
	(socket->server->argument->height - 1) : (current.y - 1);
    }
  init.x--;
  init.y++;
  commands_ai_adjust_position(
			      &init, socket->server->argument->width,
			      socket->server->argument->height);
  commands_ai_look_left(dest, socket, init, ++curent_level);
  return (0);
}
