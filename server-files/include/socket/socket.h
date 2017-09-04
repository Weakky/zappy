/*
** socket.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 13:19:57 2017 clément
** Last update Fri Jun  9 13:24:14 2017 clément
*/

#ifndef PSU_2016_ZAPPY_SOCKET_H
#define PSU_2016_ZAPPY_SOCKET_H

#include	"drone.h"
#include	"command.h"
#include	"server.h"
#include	"circular_buffer.h"

typedef enum		e_type
{
  SERVER = 0,
  AI,
  GRAPHIC,
  UNKNOWN
}			e_type;

typedef struct		s_socket
{
  t_server		*server;
  t_circular_buffer	*bwrite;
  t_circular_buffer	*bread;
  t_drone		*drone;
  int			sockfd;
  bool			to_delete;
  t_command		*cmds;
  int			(*default_cmd)(struct s_socket *, char *);
  size_t		cmds_size;
  e_type		type;
  int			(*const read)(struct s_socket *);
  int			(*const write)(struct s_socket *);
  int			(*execute)(struct s_socket *);
}			t_socket;

t_socket	*init_server_socket(const int, t_server *);
t_socket	*init_client_socket(t_server *server, t_socket *);
void		delete_socket(void *);

#endif /* !PSU_2016_ZAPPY_SOCKET_H */
