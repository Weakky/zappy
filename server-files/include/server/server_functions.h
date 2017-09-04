/*
** server_functions.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 13:13:33 2017 clément
** Last update Fri Jun  9 13:13:59 2017 clément
*/

#ifndef PSU_2016_ZAPPY_SERVER_FUNCTIONS_H
#define PSU_2016_ZAPPY_SERVER_FUNCTIONS_H

#include	"server.h"

int	server_wait(t_server *);
int	server_delete_socket(t_server *, const int);
int	server_delete_egg(t_server *, const int);
int	server_update_time(t_server *);
int	server_list_fd_set(void *, void *, void *);
int	server_list_fd_isset(void *, void *, void *);
int	server_list_delete_errors(void *, void *, void *);
int	server_list_delete_eggs(void *, void *, void *);
int	server_list_check_eggs(void *, void *, void *);
int	server_generate_map(t_server *, t_argument);
int	server_generate_map(t_server *, t_argument);
bool	server_have_to_update(t_server *);
int	server_update(t_server *);

#endif /* !PSU_2016_ZAPPY_SERVER_FUNCTIONS_H */
