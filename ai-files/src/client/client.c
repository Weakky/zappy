/*
** client.c for client in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/client
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:34:21 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:41:49 2017 Flavian DESVERNE
*/

#include	<stdlib.h>
#include	<string.h>
#include	<limits.h>
#include	<sys/time.h>
#include	<stdio.h>
#include	"client.h"
#include	"client_functions.h"

long			gen_uuid()
{
  struct timeval	tv;
  struct timezone	tz;

  gettimeofday(&tv, &tz);
  return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

t_client		*init_client(char **av)
{
  const t_client	template = {-1, NULL, NULL, NULL, NULL,
				    { NOTHING, NULL, NULL }, gen_uuid(), true,
				    client_write, client_read};
  t_client		*new;
  t_argument		*arguments;
  t_player		*player;

  if (!(new = calloc(1, sizeof(t_client))))
    return (NULL);
  memcpy(new, &template, sizeof(t_client));
  if (!(new->buffer = init_circular_buffer(100, PIPE_BUF)))
    return (NULL);
  if (!(arguments = calloc(1, sizeof(t_argument))))
    return (NULL);
  if (get_arguments(arguments, av + 1) == -1)
    print_help(NULL, NULL);
  new->arg = arguments;
  if (!(player = init_player(new)))
    return (NULL);
  new->player = player;
  return (new);
}

void			delete_client(t_client *client)
{
  if (client)
    {
      if (client->buffer)
	delete_circular_buffer(client->buffer);
      if (client->arg)
	free(client->arg);
      if (client->player)
	delete_player(client->player);
      if (client->fs)
	fclose(client->fs);
      free(client);
    }
}
