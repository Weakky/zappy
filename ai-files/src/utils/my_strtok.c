/*
** tok.c for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#include <stdlib.h>
#include <string.h>

char	*my_strtok(char *str, char c, int start)
{
  int	i;
  char	*res;
  int	check;
  int	p;

  res = malloc(sizeof(char) * (strlen(str) + 1));
  i = 0;
  check = 0;
  while (str[i] && check != start)
    {
      if (str[i] == c)
	check++;
      i++;
    }
  p = 0;
  while (str[i] && str[i] != c)
    {
      res[p] = str[i];
      i++;
      p++;
    }
  res[p] = 0;
  return (res);
}
