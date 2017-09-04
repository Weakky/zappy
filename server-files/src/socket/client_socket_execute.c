/*
** client_socket_execute.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:24:45 2017 clément
** Last update Fri Jun  9 14:27:15 2017 clément
*/

#include	<string.h>
#include	<limits.h>
#include	"command.h"
#include	"utils.h"
#include	"socket.h"
#include	"socket_functions.h"

static int	free_split_arg(char **split_arg)
{
  int		i;

  if (!split_arg)
    return (-1);
  i = -1;
  while (split_arg[++i])
    {
      free(split_arg[i]);
    }
  free(split_arg);
  return (0);
}

int		execute_cmd(t_socket *socket, char *args)
{
  char		**split_arg;
  int		i;
  int		res;

  i = -1;
  res = 0;
  if (!(split_arg = my_split(args, " \t")))
    return (-1);
  if (!(*split_arg))
    {
      free_split_arg(split_arg);
      return (-1);
    }
  while (++i < (int) socket->cmds_size)
    if (!(strcmp(*split_arg, socket->cmds[i].name)))
      {
	res = socket->cmds[i].func(socket, strchr(args, ' '));
	free_split_arg(split_arg);
	return (res);
      }
  if (socket->default_cmd)
    res = socket->default_cmd(socket, *split_arg);
  free_split_arg(split_arg);
  return (res);
}

int		client_socket_execute(t_socket *socket)
{
  char		buff[PIPE_BUF];

  if (socket->bread->pop(socket->bread, buff) == -1)
    return (-1);
  execute_cmd(socket, buff);
  return (0);
}

int		ai_socket_execute(t_socket *socket)
{
  char		buff[PIPE_BUF];

  if (commands_ai_have_to_eat(socket))
    commands_ai_eat(socket);
  if (socket->to_delete || !socket->drone->can_act(socket->drone))
    return (-1);
  if (socket->drone->action.action)
    {
      socket->drone->action.action(socket);
      socket->drone->action.action = NULL;
      socket->drone->action.arg_ptr = NULL;
      socket->drone->action.arg_int = 0;
    }
  if (socket->bread->pop(socket->bread, buff) == 0)
    execute_cmd(socket, buff);
  return (0);
}