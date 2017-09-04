/*
** ia_move.c for ia_move in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/ia
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:48:21 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:48:28 2017 Flavian DESVERNE
*/

#include <math.h>
#include "client.h"

static int		find_y(int index, int level)
{
  int			right_bound;
  int			vision_field;
  int			current_y;

  current_y = 1;
  vision_field = 1 + (level);
  while (current_y <= vision_field) {
    right_bound = (int) pow(current_y, 2);
    if (index <= right_bound) {
      return (current_y - 1);
    }
    current_y++;
  }
  return (0);
}

static int		find_x(int index, int y)
{
  int			bound;
  int			middle;

  bound = (int) pow(y + 1, 2);
  middle = y;
  while (bound > index) {
    bound--;
    middle--;
  }
  return (middle);
}

static e_command *pos_to_movements(int x, int y, int i, int abs_x)
{
  e_command		*commands;
  int			nb_commands;

  nb_commands = abs_x + abs(y);
  if (x != 0)
    nb_commands += 1;
  commands = calloc((size_t) nb_commands + 1, sizeof(e_command));
  while (++i < nb_commands)
    {
      while (y > 0)
	{
	  commands[(i++)] = FORWARD;
	  y--;
	}
      if (x != 0)
	commands[(i++)] = ((x > 0) ? (RIGHT) : (LEFT));
      while (abs_x > 0)
	{
	  commands[(i++)] = FORWARD;
	  abs_x--;
	}
    }
  commands[(i - 1)] = NOTHING;
  return (commands);
}

static e_command	*walk_towards_tile(t_client *client, int index)
{
  int			target_y;
  int			target_x;

  target_y = find_y(index, client->player->level);
  target_x = find_x(index, target_y);
  return (pos_to_movements(target_x, target_y, -1, abs(target_x)));
}

void			ia_move_to_tile(t_client *client, int index)
{
  e_command		*movements;
  int			i;

  i = 0;
  movements = walk_towards_tile(client, index);
  while (movements[i] != NOTHING && client->buffer->count < 8)
    send_command(client, movements[(i++)]);
  if (movements)
    free(movements);
}
