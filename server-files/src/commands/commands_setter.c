/*
** commands_setter.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:12:04 2017 clément
** Last update Tue Jun 27 11:12:05 2017 clément
*/

#include	<stdio.h>
#include	"socket.h"

int			commands_set_unknown(t_socket *socket)
{
  static t_command	cmd[UNKNOWN_NUM] =
    {{"GRAPHIC", commands_unknown_graphic}};

  socket->cmds = cmd;
  socket->cmds_size = UNKNOWN_NUM;
  socket->default_cmd = commands_unknown_ai;
  return (0);
}

int			commands_set_ai(t_socket *socket)
{
  static t_command	cmd[AI_NUM] =
    {{"Forward", commands_ai_forward},
     {"Left", commands_ai_left},
     {"Right", commands_ai_right},
     {"Inventory", commands_ai_inventory},
     {"Broadcast", commands_ai_broadcast},
     {"Look", commands_ai_look},
     {"Connect_nbr", commands_ai_connect_nbr},
     {"Eject", commands_ai_eject},
     {"Take", commands_ai_take},
     {"Set", commands_ai_set},
     {"Incantation", commands_ai_incantation},
     {"Fork", commands_ai_fork}};

  socket->cmds = cmd;
  socket->cmds_size = AI_NUM;
  socket->default_cmd = commands_ai_default;
  return (0);
}


int			commands_set_graphic(t_socket *socket)
{
  static t_command	cmd[GRAPHIC_NUM] =
    {{"msz", commands_graphic_msz},
     {"bct", commands_graphic_bct},
     {"mct", commands_graphic_mct},
     {"sgt", commands_graphic_sgt},
     {"sst", commands_graphic_sst},
     {"tna", commands_graphic_tna},
     {"ppo", commands_graphic_ppo},
     {"plv", commands_graphic_plv},
     {"pin", commands_graphic_pin}};

  socket->cmds = cmd;
  socket->cmds_size = GRAPHIC_NUM;
  socket->default_cmd = commands_graphic_default;
  return (0);
}
