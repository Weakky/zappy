/*
** ia_recipes_group_need.c for group_need in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:51:08 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:51:09 2017 Flavian DESVERNE
*/

#include "ia.h"
#include "client.h"
#include "broadcast.h"

t_required		*res_to_set(t_client *client, t_requisite requisite)
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
      to_take = requisite.resources[i] - client->player->inventory[i];
      cur_object.object = to_take > 0 ? (e_object)i : EMPTY;
      cur_object.nb_needed = to_take > 0 ? to_take : 0;
      wanted_resources[i] = cur_object;
    }
  return (wanted_resources);
}

void			ia_ask_for_needed_res(t_client *c, t_requisite req)
{
  t_required		*needed_res;
  t_player_inventory	*tmp_inv;
  int			i;

  needed_res = res_to_set(c, req);
  i = -1;
  while (++i < c->player->l_data.nb_frds)
    {
      if ((tmp_inv = inventory_by_id(c, c->player->l_data.friends[i])) != NULL)
	broadcast_send_set_object(c, needed_res, tmp_inv,
				  c->player->l_data.friends[i]);
    }
  free(needed_res);
}
