/*
** action_ai_personal.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 10:25:53 2017 clément
** Last update Tue Jun 27 10:26:00 2017 clément
*/

#include	<string.h>
#include	<stdio.h>
#include	"socket.h"

int	action_ai_inventory(t_socket *socket)
{
  char	buff[PIPE_BUF];
  int	(*inv)[8];

  inv = &(socket->drone->inventory);
  sprintf(buff, "[ food %d, linemate %d, deraumere %d, sibur %d, "
	   "mendiane %d, phiras %d, thystame %d ]",
	  (*inv)[FOOD], (*inv)[LINEMATE], (*inv)[DERAUMERE],
	  (*inv)[SIBUR], (*inv)[MENDIANE], (*inv)[PHIRAS], (*inv)[THYSTAME]);
  socket->bwrite->push(socket->bwrite, buff, strlen(buff));
  return (0);
}
