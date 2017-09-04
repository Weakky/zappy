/*
** error.c for  in PSU_2016_myirc
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Thu Jun  8 20:22:24 2017 clément
** Last update Thu Jun  8 20:22:38 2017 clément
*/

#include	<stdio.h>

int	print_error(char *message)
{
  fprintf(stderr, "./client: %s\n", message);
  return (-1);
}
