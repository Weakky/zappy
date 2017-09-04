/*
** action_ai_elevation.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:25:14 2017 clément
** Last update Tue Jun 27 10:25:15 2017 clément
*/

#include	<string.h>
#include	<stdio.h>
#include	"socket.h"
#include	"event.h"

int		action_ai_elevation(t_socket *socket)
{
  int		i;
  bool		has_still_enough;
  char		buff[PIPE_BUF];

  i = -1;
  has_still_enough = true;
  while (++i <= THYSTAME)
    if (socket->server->map[socket->drone->pos.y
			    * socket->server->argument->width
			    + socket->drone->pos.x][i]
	!= elms_needed[socket->drone->level -1][i] && i != FOOD)
      has_still_enough = false;
  if (has_still_enough)
    socket->drone->level++;
  if (has_still_enough)
    {
      sprintf(buff, "Current level: %d", socket->drone->level);
      socket->bwrite->push(socket->bwrite, buff, strlen(buff));
    }
  else
    socket->bwrite->push(socket->bwrite, "ko", 2);
  return (0);
}

static void	send_speller_message(t_socket *socket, bool *has_still_enough)
{
  char		buff[PIPE_BUF];

  if (*has_still_enough)
    {
      sprintf(buff, "Current level: %d", socket->drone->level);
      socket->bwrite->push(socket->bwrite, buff, strlen(buff));
    }
  else
    socket->bwrite->push(socket->bwrite, "ko", 2);
  event_dispatch(socket->server, event_on_incantation_end,
		 socket->drone->action.arg_ptr, has_still_enough);
  list_free(socket->drone->action.arg_ptr, NULL);
}

int		action_ai_elevation_speller(t_socket *socket)
{
  int		i;
  bool		has_still_enough;

  i = -1;
  has_still_enough = true;
  while (++i <= THYSTAME)
    if (socket->server->map[socket->drone->pos.y
			    * socket->server->argument->width
			    + socket->drone->pos.x][i]
	< elms_needed[socket->drone->level -1][i] && i != FOOD)
      has_still_enough = false;
  if (has_still_enough)
    socket->drone->level++;
  send_speller_message(socket, &has_still_enough);
  if (socket->drone->level == 8)
    socket->server->winning_team = socket->drone->team;
  return (0);
}
