/*
** socket_functions.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 13:16:57 2017 clément
** Last update Fri Jun  9 13:19:47 2017 clément
*/

#ifndef PSU_2016_ZAPPY_SOCKET_FUNCTIONS_H
#define PSU_2016_ZAPPY_SOCKET_FUNCTIONS_H

#include	"socket.h"

int	client_socket_read(t_socket *);
int	client_socket_write(t_socket *);
int	client_socket_execute(t_socket *);
int	ai_socket_execute(t_socket *);

#endif /* !PSU_2016_ZAPPY_SOCKET_FUNCTIONS_H */
