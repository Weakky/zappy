/*
** argument.h for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#ifndef PSU_2016_ZAPPY_ZAPPY_H
#define PSU_2016_ZAPPY_ZAPPY_H

#include <time.h>

typedef struct	s_argument
{
  short		port;
  char		*name;
  char		*machine_name;
}		t_argument;

typedef struct	s_arg_cmd
{
  const char	*name;
  int		(*const cmd)(t_argument *, char **);
}		t_arg_cmd;

int		get_arguments(t_argument *argument, char **arg);
int		get_arguments_team_name(t_argument *argument, char **arg);
int		get_arguments_port(t_argument *argument, char **arg);
int		get_arguments_machine_name(t_argument *argument, char **arg);
int		print_help(t_argument *argument, char **arg);

#endif /* PSU_2016_ZAPPY_ZAPPY_H */
