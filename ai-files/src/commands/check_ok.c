/*
** check_ok.c for check_ok in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:42:41 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:42:45 2017 Flavian DESVERNE
*/

#include <string.h>
#include "client.h"

bool	check_ok(t_client __attribute__((unused)) *client,
		 char *response, char __attribute__((unused)) *arg)
{
  return (!strcmp(response, "ok"));
}
