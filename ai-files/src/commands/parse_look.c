/*
** parse_look.c for parse_look in /home/desver_f/rendu/TEK2/PSU_2016_zappy/ai-files/src/commands
**
** Made by Flavian DESVERNE
** Login   <flavian.desverne@epitech.eu>
**
** Started on  Sun Jul  2 21:44:30 2017 Flavian DESVERNE
** Last update Sun Jul  2 21:44:31 2017 Flavian DESVERNE
*/

#include <string.h>
#include "client.h"
#include "utils.h"

static const t_object objects[10] =
 {
 { "linemate", LINEMATE },
 { "deraumere", DERAUMERE },
 { "sibur", SIBUR },
 { "mendiane", MENDIANE },
 { "phiras", PHIRAS },
 { "thystame", THYSTAME },
 { "food", FOOD },
 { "player", PLAYER },
 { "other", OTHER },
 { "empty", EMPTY },
};

e_object	parse_object(char *object)
{
  int		i;

  i = 0;
  while (i < OTHER)
    {
      if (strcasecmp(objects[i].name, object) == 0)
	return (objects[i].object);
      i++;
    }
  return (EMPTY);
}

e_object	**parse_look_to_objects(char ***objects, int nb_cases)
{
  int		i;
  int		p;
  e_object	**tab;

  i = 0;
  if (!(tab = malloc(sizeof(e_object *) * (nb_cases + 1))))
    return (NULL);
  while (objects[i])
    {
      nb_cases = 0;
      while (objects[i][nb_cases])
	nb_cases++;
      if (!(tab[i] = malloc(sizeof(e_object) * (nb_cases + 1))))
	return (NULL);
      p = 0;
      while (objects[i][p])
	{
	  tab[i][p] = parse_object(objects[i][p]);
	  p++;
	}
      tab[i][p] = EMPTY;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

char		**parse_look_by_case(char *cases)
{
  int		i;
  char		**res;
  char		*str;
  int		nb_items;

  i = 0;
  if (cases == NULL)
    return (NULL);
  if (cases[0] == ' ')
    cases = &cases[1];
  for (nb_items = 0; cases[i]; i++)
    if (cases[i] == ' ')
      nb_items++;
  i = 0;
  if (!(res = malloc(sizeof(char *) * (nb_items + 3))))
    return (NULL);
  while (nb_items >= i)
    {
      str = my_strtok(cases, ' ', i);
      res[i] = str;
      i++;
    }
  res[i] = NULL;
  return (res);
}

char		**parse_case(char *origin, int nb_cases)
{
  int		i;
  char		*save;
  char		**tab_sav;

  if (!(tab_sav = malloc(sizeof(char *) * (nb_cases + 2))))
    return (NULL);
  i = -1;
  while (++i <= nb_cases)
    {
      save = my_strtok(origin, ',', i);
      if (save[0] != 0)
	tab_sav[i] = save;
      else
	tab_sav[i] = "empty";
    }
  tab_sav[i] = NULL;
  return (tab_sav);
}

e_object	**parse_look(char *response)
{
  char		***tiles;
  char		**tab_sav;
  int		i;
  int		nb_cases;

  response[strlen(response) - 2] = 0;
  response = &response[1];
  i = 0;
  for (nb_cases = 0; response[i]; i++)
    if (response[i] == ',')
      nb_cases++;
  if (!(tiles = malloc(sizeof(char **) * (nb_cases + 2))))
    return (NULL);
  tab_sav = parse_case(response, nb_cases);
  i = -1;
  while (++i <= nb_cases)
    tiles[i] = parse_look_by_case(tab_sav[i]);
  tiles[i] = NULL;
  return (parse_look_to_objects(tiles, i));
}
