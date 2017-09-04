/*
** my_strchr.c for  in PSU_2016_myirc
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Sun May 21 23:32:45 2017 clément
** Last update Sun May 21 23:32:46 2017 clément
*/

#include	<stdlib.h>

char	my_strchr(char *src, char c)
{
  int	i;

  if (src == NULL)
    return (-1);
  i = 0;
  while (src[i] != '\0')
    {
      if (src[i] == c)
	return (c);
      i++;
    }
  return (0);
}
