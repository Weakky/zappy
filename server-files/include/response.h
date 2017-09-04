/*
** response.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Mon Jun 26 12:51:12 2017 clément
** Last update Mon Jun 26 12:51:13 2017 clément
*/

#ifndef PSU_2016_ZAPPY_RESPONSE_H
#define PSU_2016_ZAPPY_RESPONSE_H

#include	"socket.h"

int	response_graphic_msz(t_socket *);
int	response_graphic_bct(t_socket *, int, int);
int	response_graphic_tna(t_socket *, t_team *);
int	response_graphic_ppo(t_socket *, t_socket *);
int	response_graphic_plv(t_socket *, t_socket *);
int	response_graphic_pin(t_socket *, t_socket *);
int	response_graphic_sgt(t_socket *);
int	response_graphic_pnw(t_socket *, t_socket *);
int	response_graphic_pex(t_socket *, t_socket *);
int	response_graphic_pbc(t_socket *, t_socket *, char *);
int	response_graphic_pdr(t_socket *, t_socket *, e_objects);
int	response_graphic_pgt(t_socket *, t_socket *, e_objects);
int	response_graphic_pic(t_socket *, t_socket *, t_list *);
int	response_graphic_pie(t_socket *, t_socket *, bool);
int	response_graphic_pfk(t_socket *, t_socket *);
int	response_graphic_pdi(t_socket *, t_socket *);
int	response_graphic_enw(t_socket *, t_egg *);
int	response_graphic_eht(t_socket *, t_egg *);
int	response_graphic_ebo(t_socket *, t_egg *);
int	response_graphic_edi(t_socket *, t_egg *);
int	response_graphic_seg(t_socket *, t_server *);

#endif /* !PSU_2016_ZAPPY_RESPONSE_H */
