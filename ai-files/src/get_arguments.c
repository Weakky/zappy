/*
** get_arg.c for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#include <memory.h>
#include "argument.h"

int			get_arguments(t_argument *argument, char **arg)
{
  int			i;
  int			j;
  const t_argument	init_arg = {0, NULL, "127.0.0.1"};
  const t_arg_cmd	arg_cmds[4] = {{"-p", get_arguments_port},
					{"-n", get_arguments_team_name},
					{"-h", get_arguments_machine_name},
					{"--help", print_help}};
  i = -1;
  memcpy(argument, &init_arg, sizeof(t_argument));
  while (arg[++i])
    {
      j = -1;
      while (++j < 4)
	if (!strcmp(arg[i], arg_cmds[j].name))
	  arg_cmds[j].cmd(argument, &(arg[i + 1]));
    }
  if (!argument->port || !argument->name || !argument->machine_name)
    return (-1);
  return (0);
}
