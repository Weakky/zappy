/*
** requisites.c for requisites in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:37:08 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:39:49 2017 Flavian DESVERNE
*/

#include <string.h>
#include "client.h"

t_requisite			get_requisite_for_level(t_client *client)
{
  return (client->player->requisite[client->player->level - 1]);
}

t_requisite			*init_requisite()
{
  static const t_requisite	requisite[7] =
    {
      {1, {1, 0, 0, 0, 0, 0}},
      {2, {1, 1, 1, 0, 0, 0}},
      {2, {2, 0, 1, 0, 2, 0}},
      {4, {1, 1, 2, 0, 1, 0}},
      {4, {1, 2, 1, 3, 0, 0}},
      {6, {1, 2, 3, 0, 1, 0}},
      {6, {2, 2, 2, 2, 2, 1}},
    };
  t_requisite *new;

  if ((new = calloc(7, sizeof(t_requisite))) == NULL)
    return (NULL);
  memcpy(new, &requisite, sizeof(t_requisite) * 7);
  return (new);
}
