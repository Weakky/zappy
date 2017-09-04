/*
** get_arguments.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 14:06:04 2017 clément
** Last update Tue Jun 27 14:06:05 2017 clément
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"argument.h"

static int		init_default_team(t_argument *argument)
{
  const t_team		template[] = {{"Team1", 0}, {"Team2", 0},
				      {"Team3", 0}, {"Team4", 0}};

  if (!(argument->teams = calloc(sizeof(t_team), 4)))
    return (-1);
  memcpy(argument->teams, template, sizeof(t_team) * 4);
  argument->nteam = 4;
  return (0);
}

static int		get_arguments_help(t_argument *argument,
					   char __attribute__((unused)) **arg)
{
  argument->help = true;
  return (0);
}

int			get_arguments(t_argument *argument, char **arg)
{
  int			i;
  int			j;
  const t_argument	init_arg = {4242, 10, 10, NULL, 0, 3, 100, false};
  const t_arg_cmd	arg_cmds[7] = {{"-p", get_arguments_socket},
				       {"-x", get_arguments_width},
				       {"-y", get_arguments_height},
				       {"-n", get_arguments_team_names},
				       {"-c", get_arguments_nb_client},
				       {"-f", get_arguments_frequency},
				       {"--help", get_arguments_help}};

  i = -1;
  memcpy(argument, &init_arg, sizeof(t_argument));
  while (arg[++i])
    {
      j = -1;
      while (++j < 7)
	if (!strcmp(arg[i], arg_cmds[j].name))
	  if (arg_cmds[j].cmd(argument, &(arg[i + 1])) == -1)
	    return (-1);
    }
  if (!argument->teams && init_default_team(argument) == -1)
    return (-1);
  return (0);
}
