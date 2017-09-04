/*
** get_arguments_map.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 14:06:11 2017 clément
** Last update Tue Jun 27 14:06:12 2017 clément
*/

#include	<string.h>
#include	<stdlib.h>
#include	"utils.h"
#include	"argument.h"

int		get_arguments_socket(t_argument *argument, char **arg)
{
  const char	*flag_names[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};
  int		i;

  i = -1;
  if (!arg || !(*arg))
    return (perr("option requires an argument -- 'p'"));
  while (++i < 6)
    if (!strcmp(*arg, flag_names[i]))
      return (perr("option requires an argument -- 'p'"));
  i = -1;
  while ((*arg)[++i])
    if ((*arg)[i] > '9' || (*arg)[i] < '0')
      return (perr("-p option only accepts valid ports"));
  argument->port = atoi(*arg);
  if (!argument->port)
    argument->port = rand() % 60000;
  return (0);
}

int		get_arguments_width(t_argument *argument, char **arg)
{
  const char	*flag_names[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};
  int		i;

  i = -1;
  if (!arg || !(*arg))
    return (perr("option requires an argument -- 'x'"));
  while (++i < 6)
    if (!strcmp(*arg, flag_names[i]))
      return (perr("option requires an argument -- 'x'"));
  argument->width = atoi(*arg);
  if (argument->width < 10 || argument->width > 30)
    return (perr("-x option only accepts integer values between 10 and 30"));
  return (0);
}

int		get_arguments_height(t_argument *argument, char **arg)
{
  const char	*flag_names[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};
  int		i;

  i = -1;
  if (!arg || !(*arg))
    return (perr("option requires an argument -- 'y'"));
  while (++i < 6)
    if (!strcmp(*arg, flag_names[i]))
      return (perr("option requires an argument -- 'y'"));
  argument->height = atoi(*arg);
  if (argument->height < 10 || argument->height > 30)
    return (perr("-y option only accepts integer values between 10 and 30"));
  return (0);
}
