/*
** ia_action.c for ia_action in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:47:25 2017 Flavian DESVERNE
** Last update Sun Jul  2 22:06:33 2017 Flavian DESVERNE
*/

#include <limits.h>
#include <string.h>
#include "broadcast.h"
#include "ia.h"

static void	define_roles(t_client *cl, int j,
			     long *leader_id, t_team_player *player)
{
  if (j == 0)
    *leader_id = player->id;
  if (j == 0 && *leader_id == cl->uid)
    cl->player->is_small_leader = true;
  if (j > 0 && (player->id == cl->uid))
    cl->player->leader_uid = *leader_id;
  if (*leader_id == cl->uid && cl->uid != player->id)
    {
      cl->player->l_data.friends[cl->player->l_data.nb_frds] = player->id;
      cl->player->l_data.nb_frds++;
    }
}

void		send_group_created(t_client *c, int i, char *msg)
{
  int		nb_players;

  nb_players = c->player->requisite[i].nb_players;
  c->player->drones[i].nb_ids -= nb_players;
  send_command_with_arg(c, BROADCAST, msg);
  printf("--> GROUP CREATED of %d players\n", nb_players);
}

static void	create_valid_group(t_client *c, int i, int j, long leader_id)
{
  char		msg[PIPE_BUF];
  char		temp[PIPE_BUF];
  t_team_player	*player;
  t_list_node	*node;

  while (++i < 7)
    {
      while (c->player->drones[i].nb_ids >= c->player->requisite[i].nb_players)
	{
	  j = -1;
	  leader_id = -1;
	  snprintf(msg, PIPE_BUF, "%d,%s,%d", MAKE_GROUP, c->arg->name, i + 1);
	  while (++j < c->player->requisite[i].nb_players)
	    {
	      if (!(node = list_pop_first(c->player->drones[i].team_players))
		  || !(player = (t_team_player *) node->data))
		return ;
	      define_roles(c, j, &leader_id, player);
	      snprintf(temp, PIPE_BUF, ",%li", player->id);
	      strncat(msg, temp, PIPE_BUF);
	    }
	  send_group_created(c, i, msg);
	}
    }
}

void	read_once(t_client *client)
{
  client->read(client);
}

void		ia_action(t_client *client)
{
  static void	(*const actions[4])(t_client *) =
    {ia_survive, ia_recipes, read_once, read_once};

  client->command.exec_cmd = NULL;
  client->command.arg = NULL;
  client->command.name = NOTHING;
  if (client->player->nb_food < NB_MIN_FOOD
      && client->player->state == RECIPES)
    {
      if (client->player->is_leader)
	broadcast_send_go_to_survive(client);
      client->player->state = SURVIVING;
    }
  if (client->player->is_leader)
    create_valid_group(client, -1, -1, -1);
  actions[client->player->state](client);
}
