/*
** ia_recipes_find_objects.c for find_objects in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:49:54 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:49:58 2017 Flavian DESVERNE
*/

#include "client.h"

int			ia_get_index_for_object(t_client *client,
						e_object search)
{
  int			i;
  int			j;

  i = 0;
  if (!client->player->objects)
    return (0);
  while (client->player->objects[i])
    {
      j = 0;
      while (client->player->objects[i][j] != EMPTY)
	{
	  if (client->player->objects[i][j] == search)
	    return (i + 1);
	  j++;
	}
      i++;
    }
  return (0);
}

int			ia_get_amount_for_index(t_client *client,
						int index,
						e_object search)
{
  const e_object	*objects;
  int			i;
  int			count;

  objects = client->player->objects[index - 1];
  i = 0;
  count = 0;
  while (objects[i] != EMPTY)
    {
      if (objects[i] == search)
	count++;
      i++;
    }
  return (count);
}
