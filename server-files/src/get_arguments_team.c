/*
** get_arguments_team.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 14:06:17 2017 clément
** Last update Tue Jun 27 14:06:18 2017 clément
*/

#include	<string.h>
#include	<stdlib.h>
#include	"argument.h"
#include	"utils.h"

static int	define_teams(t_argument *argument, char **arg,
			       int i, int nteam)
{
  int		j;

  while (++i < nteam)
    {
      j = i;
      while (++j < nteam)
	if (!strcmp(arg[j], arg[i]))
	  {
	    free(argument->teams);
	    argument->teams = NULL;
	    return (-1);
	  }
      argument->teams[i].name = arg[i];
      argument->teams[i].nmember = 0;
    }
  argument->nteam = nteam;
  return (0);
}

int		get_arguments_team_names(t_argument *argument, char **arg)
{
  const char	*flag_names[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};
  int		i;
  int		nteam;
  bool		on_flag;

  nteam = -1;
  on_flag = false;
  if (!arg || !(*arg))
    return (perr("option requires an argument -- 'n'"));
  while (arg[++nteam] && !on_flag)
    {
      i = -1;
      while (++i < 6)
	if (!strcmp(arg[nteam], flag_names[i]))
	  on_flag = true;
    }
  if (on_flag)
    nteam -= 1;
  if (!nteam)
    return (perr("option requires an argument -- 'n'"));
  if (!(argument->teams = calloc(sizeof(t_team), (size_t) (nteam))))
    return (-1);
  i = -1;
  return (define_teams(argument, arg, i, nteam));
}

int		get_arguments_frequency(t_argument *argument, char **arg)
{
  const char	*flag_names[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};
  int		i;

  i = -1;
  if (!arg || !(*arg))
    return (perr("option requires an argument -- 'f'"));
  while (++i < 6)
    if (!strcmp(*arg, flag_names[i]))
      return (perr("option requires an argument -- 'f'"));
  argument->frequency = atoi(*arg);
  if (argument->frequency < 2 || argument->frequency > 10000)
    return (perr("-f option only accepts integer values between 2 and 10000"));

  return (0);
}

int		get_arguments_nb_client(t_argument *argument, char **arg)
{
  const char	*flag_names[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};
  int		i;

  i = -1;
  if (!arg || !(*arg))
    return (perr("option requires an argument -- 'c'"));
  while (++i < 6)
    if (!strcmp(*arg, flag_names[i]))
      return (perr("option requires an argument -- 'c'"));
  argument->nclients = atoi(*arg);
  if (argument->nclients < 0)
    return (perr("-c option only accepts int values greater or equal to 1"));
  return (0);
}
