/*
** get_arg_port for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "argument.h"

int		get_arguments_port(t_argument *argument, char **arg)
{
  const char	*flag_names[4] = {"-p", "-n", "-h", "--help"};
  int		i;

  i = -1;
  if (!arg || !(*arg))
    return (-1);
  while (++i < 4)
    if (!strcmp(*arg, flag_names[i]))
      return (-1);
  i = -1;
  while ((*arg)[++i])
    if ((*arg)[i] > '9' || (*arg)[i] < '0')
      return (-1);
  argument->port = (short) atoi(*arg);
  return (0);
}

int		get_arguments_team_name(t_argument *argument, char **arg)
{
  const char	*flag_names[4] = {"-p", "-n", "-h", "--help"};
  int		i;

  i = -1;
  if (!arg || !(arg[0]))
    return (-1);
  while (++i < 4) {
      if (!strcmp(arg[0], flag_names[i]))
	return (-1);
    }
  argument->name = arg[0];
  return (0);
}

int		get_arguments_machine_name(t_argument *argument, char **arg)
{
  const char	*flag_names[4] = {"-p", "-n", "-h", "--help"};
  int		i;

  i = -1;
  if (!arg || !(arg[0]))
    return (-1);
  while (++i < 4) {
      if (!strcmp(arg[0], flag_names[i]))
	return (-1);
    }
  argument->machine_name = arg[0];
  return (0);
}

int		print_help(t_argument __attribute__((unused)) *argument,
			      char __attribute__((unused)) **arg)
{
  printf("USAGE: ./zappy_ai -p port -n name -h machine\n"
	  "\tport is the port number\n"
	  "\tname is the name of the team \n"
	  "\tmachine is the name of the machine; localhost by default \n"
  );
  exit(EXIT_SUCCESS);
}
