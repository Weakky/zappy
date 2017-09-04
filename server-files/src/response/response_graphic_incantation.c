/*
** response_graphic_incantation.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 12:34:00 2017 clément
** Last update Tue Jun 27 12:34:01 2017 clément
*/

#include	<string.h>
#include	<stdio.h>
#include	"socket.h"

int		response_graphic_pic(t_socket *graphic,
				     t_socket *speller, t_list *sockets)
{
  t_socket	*subjects;
  t_list_node	*temp;
  char		buff[PIPE_BUF];
  char		tmp[PIPE_BUF];

  if (!sockets || !sockets->first)
    return (-1);
  snprintf(buff, PIPE_BUF, "pic %d %d %d", speller->drone->pos.x,
	   speller->drone->pos.y, speller->drone->level + 1);
  temp = sockets->first;
  while (temp)
    {
      subjects = (t_socket *) temp->data;
      snprintf(tmp, PIPE_BUF,  " %d", subjects->drone->id);
      strncat(buff, tmp, PIPE_BUF);
      temp = temp->next;
    }
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}

int		response_graphic_pie(t_socket *graphic,
				     t_socket *speller, bool succeeded)
{
  char		buff[PIPE_BUF];

  snprintf(buff, PIPE_BUF, "pie %d %d %d",
	   speller->drone->pos.x, speller->drone->pos.y, succeeded);
  graphic->bwrite->push(graphic->bwrite, buff, strlen(buff));
  return (0);
}
