/*
** ia_recipes_find_resources.c for find_resources in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:50:17 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:50:25 2017 Flavian DESVERNE
*/

#include "client.h"
#include "ia.h"

static t_required	*wanted_resources(t_client *client,
					  t_requisite requisite)
{
  int			i;
  int			to_take;
  t_required		*wanted_resources;
  t_required		cur_object;

  i = -1;
  if (!(wanted_resources = calloc(NB_RESOURCES, sizeof(t_required))))
    return (NULL);
  while (++i < NB_RESOURCES_NEEDED)
    {
      to_take = requisite.resources[i] - client->player->l_data.global_inv[i];
      cur_object.object = to_take > 0 ? (e_object)i : EMPTY;
      cur_object.nb_needed = to_take > 0 ? to_take : 0;
      wanted_resources[i] = cur_object;
    }
  return (wanted_resources);
}

void			ia_walk_towards_resource(t_client *c,
						 t_required *res,
						 int resource_index,
						 int amount_on_index)
{
  int			i;

  i = -1;
  while (++i < NB_RESOURCES_NEEDED && c->buffer->count < 8)
    if (res[i].object != EMPTY)
      {
	resource_index = ia_get_index_for_object(c, res[i].object);
	if (resource_index == 1)
	  {
	    amount_on_index = ia_get_amount_for_index(c, resource_index,
						      res[i].object);
	    while (res[i].nb_needed > 0 && amount_on_index > 0)
	      {
		send_command_with_arg(c, TAKE,
				      object_to_string[res[i].object]);
		res[i].nb_needed--;
		amount_on_index--;
	      }
	  }
	else if (resource_index > 1)
	  ia_move_to_tile(c, resource_index);
	else
	  send_command(c, rand() % 10 > 5 ? FORWARD : LEFT);
      }
}

bool			ia_find_resources_to_evolve(t_client *client,
						    t_requisite requisite)
{
  t_required		*wanted_res;

  wanted_res = wanted_resources(client, requisite);
  ia_walk_towards_resource(client, wanted_res, 0, 0);
  send_command(client, LOOK);
  send_command(client, INVENTORY);
  free(wanted_res);
  return (true);
}
