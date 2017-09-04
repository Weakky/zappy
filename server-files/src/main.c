/*
** main.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 14:06:24 2017 clément
** Last update Tue Jun 27 14:06:25 2017 clément
*/

#include	<stdio.h>
#include	"argument.h"
#include	"server.h"
#include	"event.h"

static int	set_all_to_delete(t_list *socks)
{
  t_list_node	*temp;
  t_socket	*data;

  temp = socks->first->next;
  while (temp)
    {
      data = (t_socket *) temp->data;
      data->to_delete = true;
      temp = temp->next;
    }
  return (0);
}

static bool	has_last_message(t_list *socks)
{
  t_list_node	*temp;
  t_socket	*data;

  temp = socks->first->next;
  while (temp)
    {
      data = (t_socket *) temp->data;
      if (data->bwrite->count)
	return (true);
      temp = temp->next;
    }
  return (false);
}

static int	print_usage()
{
  printf("\nUSAGE: ./zappy_server -p port -x width -y height -n "
	  "name1 name2 ... -c clientsNb -f freq\n\n"
	  "\tport      is the port number\n"
	  "\twidth     is the width of the world\n"
	  "\theight    is the height of the world\n"
	  "\tnameX     is the name of the team X\n"
	  "\tclientsNb is the number of "
	  "authorized clients per team\n"
	  "\tfreq      is the reciprocal of time "
	  "unit for execution of actions\n\n");
  return (0);
}

void		do_a_round(t_server *server)
{
  server->wait(server);
  if (server->winning_team)
    {
      event_dispatch(server, event_on_end_of_game, server, NULL);
      set_all_to_delete(server->socks);
    }
  else if (server->have_to_update(server))
    server->update(server);
}

int		main(int __attribute__((unused)) ac, char *av[])
{
  t_server	*server;
  t_argument	argument;

  srand(4242);
  if (get_arguments(&argument, av + 1) == -1 || argument.help)
    {
      print_usage();
      return (!(argument.help));
    }
  if (!(server = init_server(argument)))
    {
      fprintf(stderr, "./server: failed to create server\n");
      return (EXIT_FAILURE);
    }
  printf("Port : %d\n", argument.port);
  while (!(server->winning_team) || has_last_message(server->socks))
    do_a_round(server);
  delete_server(server);
  return (EXIT_SUCCESS);
}
