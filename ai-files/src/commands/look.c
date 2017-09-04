/*
** look.c for look in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:44:00 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:44:01 2017 Flavian DESVERNE
*/

#include "client.h"
#include "client_functions.h"

bool	look(t_client *client, char *response, char *arg)
{
  (void)arg;
  client->player->objects = parse_look(response);
  return (true);
}
