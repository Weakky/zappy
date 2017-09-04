/*
** main.c for  in PSU_2016_myirc
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"broadcast.h"
#include 	"client_functions.h"
#include	"ia.h"

int		main(int ac, char **av)
{
  t_client	*client;

  (void)ac;
  srand((unsigned int) time(NULL));
  if ((client = init_client(av)) == NULL)
    return (EXIT_FAILURE);
  printf("My team is %s\n", client->arg->name);
  if (client_connect(client) == 0)
    {
      welcome(client);
      broadcast_send_ping(client);
      while (client->running)
	  ia_action(client);
    }
  delete_client(client);
  return (0);
}
