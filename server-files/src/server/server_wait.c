/*
** server_wait.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:17:42 2017 clément
** Last update Fri Jun  9 14:20:45 2017 clément
*/

#include	<sys/time.h>
#include	"server_functions.h"

int			server_wait(t_server *server)
{
  struct timeval	timeout;
  fd_set		readfd;
  fd_set		writefd;

  FD_ZERO(&readfd);
  FD_ZERO(&writefd);
  list_execute(server->socks, &readfd, &writefd, server_list_fd_set);
  timeout.tv_sec = 0;
  timeout.tv_usec = 10;
  select(server->nfds, &readfd, &writefd, NULL, &timeout);
  list_execute(server->socks, &readfd, &writefd, server_list_fd_isset);
  list_execute(server->eggs, NULL, NULL, server_list_check_eggs);
  list_execute(server->socks, NULL, NULL, server_list_delete_errors);
  list_execute(server->eggs, NULL, NULL, server_list_delete_eggs);
  server->update_time(server);
  return (0);
}
