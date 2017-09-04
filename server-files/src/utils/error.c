/*
** error.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 13:57:00 2017 clément
** Last update Tue Jun 27 13:57:02 2017 clément
*/

#include	<stdio.h>

int	perr(char const *msg)
{
  fprintf(stderr, "\n./zappy_server: %s\n", msg);
  return (-1);
}
