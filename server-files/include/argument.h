/*
** argument.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Mon Jun 26 12:50:41 2017 clément
** Last update Mon Jun 26 12:50:43 2017 clément
*/

#ifndef PSU_2016_ZAPPY_ZAPPY_H
#define PSU_2016_ZAPPY_ZAPPY_H

#include	<time.h>
#include	<stdbool.h>

typedef struct	s_team
{
  char		*name;
  int		nmember;
}		t_team;

typedef struct	s_argument
{
  int		port;
  int		width;
  int		height;
  t_team	*teams;
  int		nteam;
  int		nclients;
  double	frequency;
  bool		help;
}		t_argument;

typedef struct	s_arg_cmd
{
  const char	*name;
  int		(*const cmd)(t_argument *, char **);
}		t_arg_cmd;

int	get_arguments_socket(t_argument *, char **);
int	get_arguments_width(t_argument *, char **);
int	get_arguments_height(t_argument *, char **);
int	get_arguments_team_names(t_argument *, char **);
int	get_arguments_frequency(t_argument *, char **);
int	get_arguments_nb_client(t_argument *, char **);
int	get_arguments(t_argument *, char **);

#endif /* !PSU_2016_ZAPPY_ZAPPY_H */
