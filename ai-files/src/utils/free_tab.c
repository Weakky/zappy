/*
** ftab.c for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (!tab)
    return ;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
