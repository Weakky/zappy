/*
** command.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Mon Jun 26 12:50:51 2017 clément
** Last update Mon Jun 26 12:50:52 2017 clément
*/

#ifndef PSU_2016_ZAPPY_COMMAND_H
#define PSU_2016_ZAPPY_COMMAND_H

#include	<stdbool.h>
#include	"server.h"
#include	"drone.h"

#define UNKNOWN_NUM (1)
#define GRAPHIC_NUM (9)
#define AI_NUM (12)

typedef struct	s_socket t_socket;

typedef struct	s_command
{
  char const	*name;
  int		(*const func)(t_socket *, char *);
}		t_command;

/* !SETTER */
int	commands_set_unknown(t_socket *);
int	commands_set_ai(t_socket *);
int	commands_set_graphic(t_socket *);
/* !COMMAND */
int	commands_unknown_ai(t_socket *, char *);
int	commands_ai_forward(t_socket *, char *);
int	commands_ai_left(t_socket *, char *);
int	commands_ai_right(t_socket *, char *);
int	commands_ai_inventory(t_socket *, char *);
int	commands_ai_broadcast(t_socket *, char *);
int	commands_ai_look(t_socket *, char *);
int	commands_ai_connect_nbr(t_socket *, char *);
int	commands_ai_eject(t_socket *, char *);
int	commands_ai_take(t_socket *, char *);
int	commands_ai_set(t_socket *, char *);
int	commands_ai_incantation(t_socket *, char *);
int	commands_ai_fork(t_socket *, char *);
int	commands_graphic_msz(t_socket *, char *);
int	commands_graphic_bct(t_socket *, char *);
int	commands_graphic_mct(t_socket *, char *);
int	commands_graphic_sgt(t_socket *, char *);
int	commands_graphic_sst(t_socket *, char *);
int	commands_graphic_tna(t_socket *, char *);
int	commands_graphic_ppo(t_socket *, char *);
int	commands_graphic_plv(t_socket *, char *);
int	commands_graphic_pin(t_socket *, char *);
/* !DEFAULT */
int	commands_unknown_graphic(t_socket *, char *);
int 	commands_ai_default(t_socket *, char *);
int	commands_graphic_default(t_socket *, char *);
/* !SUB */
bool	commands_ai_have_to_eat(t_socket *);
int	commands_ai_eat(t_socket *socket);
int	commands_ai_find_directon(t_socket *, t_socket *, t_argument *);
int	commands_ai_look_up(int (*)[8], t_socket *, t_position, int);
int	commands_ai_look_left(int (*)[8], t_socket *, t_position, int);
int	commands_ai_look_down(int (*)[8], t_socket *, t_position, int);
int	commands_ai_look_right(int (*)[8], t_socket *, t_position, int);
int	commands_ai_adjust_position(t_position *, int, int);
int	commands_ai_create_drone_by_egg(t_socket *, t_team *);
void	commands_ai_send_first_message(t_socket *);
/* !EXTERN */
extern const int	elms_needed[7][8];
extern const char	*elm_names[];

#endif /* !PSU_2016_ZAPPY_COMMAND_H */
