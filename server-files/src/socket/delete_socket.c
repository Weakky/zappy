/*
** socket.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 14:50:39 2017 clément
** Last update Sun Jun 11 18:28:43 2017 clément
*/

#include	<unistd.h>
#include	"socket.h"

void		delete_socket(void *data)
{
  t_socket	*socket;

  if (data)
    {
      socket = data;
      close(socket->sockfd);
      delete_circular_buffer(socket->bwrite);
      delete_circular_buffer(socket->bread);
      if (socket->drone)
	delete_drone(socket->drone);
      free(socket);
    }
}
