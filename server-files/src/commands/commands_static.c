/*
** commands_ai_static.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Wed Jun 28 17:27:12 2017 clément
** Last update Wed Jun 28 17:27:13 2017 clément
*/

const int	elms_needed[7][8] =
 {{1, 0, 1, 0, 0, 0, 0, 0},
  {2, 0, 1, 1, 1, 0, 0, 0},
  {2, 0, 2, 0, 1, 0, 2, 0},
  {4, 0, 1, 1, 2, 0, 1, 0},
  {4, 0, 1, 2, 1, 3, 0, 0},
  {6, 0, 1, 2, 3, 0, 1, 0},
  {6, 0, 2, 2, 2, 2, 2, 1}};

const char	*elm_names[] =
 {"player", "food", "linemate", "deraumere",
  "sibur", "mendiane", "phiras", "thystame"};