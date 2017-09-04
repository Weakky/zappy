/*
** broadcast_send_group.c for send_group in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:29:47 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:32:51 2017 Flavian DESVERNE
*/

#include <string.h>
#include <limits.h>
#include "broadcast.h"
#include "ia.h"

void	broadcast_send_ask_inventory(t_client *client)
{
  char	buff[PIPE_BUF];
  char	inventory[PIPE_BUF];
  char	temp[PIPE_BUF];
  int	i;

  if (client->player->level > 1)
    {
      i = -1;
      bzero(inventory, PIPE_BUF);
      while (++i < NB_RESOURCES_NEEDED)
	{
	  snprintf(temp, PIPE_BUF, ",%d", client->player->inventory[i]);
	  strncat(inventory, temp, PIPE_BUF);
	}
      sprintf(buff, "%d,%s,%li%s", ASK_INVENTORY,
	      client->arg->name, client->uid, inventory);
      send_command_with_arg(client, BROADCAST, buff);
    }
}

void	broadcast_send_join_me(t_client *client)
{
  char	buff[PIPE_BUF];
  char	temp[PIPE_BUF];
  char	friends[PIPE_BUF];
  int	i;

  i = -1;
  bzero(friends, PIPE_BUF);
  while (++i < client->player->l_data.nb_frds)
    {
      snprintf(temp, PIPE_BUF, ",%lu", client->player->l_data.friends[i]);
      strcat(friends, temp);
    }
  sprintf(buff, "%d,%s%s", JOIN_ME, client->arg->name, friends);
  send_command_with_arg(client, BROADCAST, buff);
}

void	broadcast_send_set_object(t_client *client,
				  t_required *needed_res,
				  t_player_inventory *tmp_inv,
				  long player_id)
{
  int	j;
  char	buff[PIPE_BUF];
  char	tmp_object[PIPE_BUF];
  char	objects[PIPE_BUF];

  j = -1;
  bzero(objects, PIPE_BUF);
  while (++j < NB_RESOURCES_NEEDED)
    {
      if (needed_res[j].nb_needed &&
	  tmp_inv->inventory[j] >= needed_res[j].nb_needed)
	{
	  while (needed_res[j].nb_needed > 0)
	    {
	      printf("NEED A %s\n", object_to_string[needed_res[j].object]);
	      snprintf(tmp_object, PIPE_BUF, ",%d", needed_res[j].object);
	      strcat(objects, tmp_object);
	      needed_res[j].nb_needed--;
	    }
	}
    }
  sprintf(buff, "%d,%lu%s", SET_OBJECT, player_id, objects);
  send_command_with_arg(client, BROADCAST, buff);
}

void	broadcast_send_i_am_here(t_client *client)
{
  char	buff[PIPE_BUF];

  sprintf(buff, "%d,%s,%lu", I_AM_HERE,
	  client->arg->name, client->player->leader_uid);
  send_command_with_arg(client, BROADCAST, buff);
}
