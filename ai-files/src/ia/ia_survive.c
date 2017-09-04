/*
** ia_survive.c for survive in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:52:11 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:52:21 2017 Flavian DESVERNE
*/

#include "client.h"
#include "ia.h"

void	refresh_view(t_client *client)
{
  send_command(client, LOOK);
  send_command(client, INVENTORY);
}

void	ia_survive(t_client *client)
{
  int	index_with_food;
  int	nb_food;

  if (client->player->nb_food >= NB_MAX_FOOD)
    {
      client->player->state = RECIPES;
      return ;
    }
  if ((index_with_food = ia_get_index_for_object(client, FOOD)) > 0)
    {
      if (index_with_food > 1)
	ia_move_to_tile(client, index_with_food);
      else
	{
	  nb_food = ia_get_amount_for_index(client, index_with_food, FOOD);
	  while (nb_food > 0)
	    {
	      send_command_with_arg(client, TAKE, "food");
	      nb_food--;
	    }
	}
    }
  else
    send_command(client, FORWARD);
  refresh_view(client);
}
