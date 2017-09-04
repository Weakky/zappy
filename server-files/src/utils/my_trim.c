/*
** my_trim.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 13:56:47 2017 clément
** Last update Tue Jun 27 13:56:48 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>

int	my_trim(char *str)
{
  char	*start;
  char	*end;

  start = str;
  while (*start && isspace(*start))
    start++;
  end = start + strlen(start);
  while (end > start + 1 && isspace(*(end - 1)))
    end--;
  *end = '\0';
  if (start > str)
    memmove(str, start, (end - start) + 1);
  return (0);
}
