/*
** broadcast.c for broadcast in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/broadcast
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:28:03 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:28:04 2017 Flavian DESVERNE
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utils.h"
#include "client.h"
#include "broadcast.h"

static bool	(*const message_func[11])(t_client *, char **, char) =
 {
  broadcast_message_ping,
  broadcast_message_pong,
  broadcast_message_make_group,
  broadcast_message_lvl_up,
  broadcast_message_ask_inventory,
  broadcast_message_set_object,
  broadcast_message_join_me,
  broadcast_message_i_am_here,
  broadcast_message_evolve,
  broadcast_message_whitelist,
  broadcast_message_go_to_survive
 };

static bool	parse_message(t_client *client, char *message,
			      char const direction,
			      bool *keep_reading)
{
  char		*instruction;
  char		*index_str;
  int		index;
  int 		i;
  char		**response;
  bool		output;

  index_str = strtok(message, ",");
  instruction = strtok(NULL, "");
  if (!index_str || !instruction)
    return (false);
  i = -1;
  while (index_str[++i])
    if (!isdigit(index_str[i]))
      return (false);
  index = atoi(index_str);
  if (index < 0 || index > 10)
    return (false);
  if (!(response = my_split(instruction, ",")))
    return (false);
  output = message_func[index](client, response, direction);
  if (index == GO_BACK_TO_WHITELIST && output)
    *keep_reading = false;
  return (true);
}

bool	handle_broadcast(t_client *client, char *response, bool *keep_reading)
{
  char	direction;
  char	*message;

  if (!strncmp(response, "message", 6) && strlen(response) >= 11)
    {
      direction = (char) atoi(response + 7);
      message = response + 11;
      parse_message(client, message, direction, keep_reading);
      return (true);
    }
  return (false);
}
