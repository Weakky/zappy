/*
** take_set_object.c for take_set_object in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:44:50 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:44:51 2017 Flavian DESVERNE
*/

#include <stdio.h>
#include "client.h"
#include "client_functions.h"

bool	take_object(t_client *client, char *response, char *arg)
{
  if (check_ok(client, response, NULL))
    {
      if (parse_object(arg) != FOOD)
	{
	  printf("TAKE OBJECT: %s\n", arg);
	  send_command(client, INVENTORY);
	}
      return (true);
    }
  return (false);
}

bool	set_object(t_client *client, char *response, char *arg)
{
  if (check_ok(client, response, NULL))
    {
      if (parse_object(arg) != FOOD)
	printf("SET OBJECT %s\n", arg);
      return (true);
    }
  return (false);
}
