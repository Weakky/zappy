/*
** action_ai_look.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:25:30 2017 clément
** Last update Tue Jun 27 10:25:31 2017 clément
*/

#include	<string.h>
#include	"socket.h"

static int	display_infos(int (*elms)[8], char *buff, int nelms, int i)
{
  int 		j;
  int		n;
  static char	*elm_names[] = {"player", "food", "linemate",
				"deraumere", "sibur", "mendiane",
				"phiras", "thystame"};

  i = -1;
  strncpy(buff, "[", PIPE_BUF);
  while (++i < nelms)
    {
      j = -1;
      while (++j < 8)
	{
	  n = -1;
	  while (++n <  elms[i][j])
	    {
	      strncat(buff, " ", PIPE_BUF);
	      strncat(buff, elm_names[j], PIPE_BUF);
	    }
	}
      if (i < nelms - 1)
	strncat(buff, ",", PIPE_BUF);
    }
  strncat(buff, " ]", PIPE_BUF);
  return (0);
}

int		action_ai_look(t_socket *socket)
{
  int		nelms;
  int		i;
  int		(*elms)[8];
  t_position	pos;
  char		buff[PIPE_BUF];
  int		(*dir_func[4])(int (*)[8], t_socket *, t_position, int) =
    {commands_ai_look_up, commands_ai_look_right,
     commands_ai_look_down, commands_ai_look_left};

  nelms = 0;
  i = -1;
  while (++i <= (int) socket->drone->level)
    nelms += i * 2 + 1;
  if (!(elms = calloc(sizeof(int[8]) , (size_t) nelms + 1)))
    return (-1);
  pos = socket->drone->pos;
  bzero(elms, sizeof(int[8]) * nelms + 1);
  bzero(buff, PIPE_BUF);
  dir_func[socket->drone->direction](elms, socket, pos, 0);
  display_infos(elms, buff, nelms, -1);
  socket->bwrite->push(socket->bwrite, buff, strlen(buff));
  return (0);
}
