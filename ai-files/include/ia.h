/*
** ia.h for  in PSU_2016_myirc
**
** Made by clément
** Login   <clement.deseine@epitech.eu>
**
** Started on  Thu Jun  8 20:22:47 2017 clément
** Last update Thu Jun  8 20:24:32 2017 clément
*/

#ifndef PSU_2016_ZAPPY_IA_H
#define PSU_2016_ZAPPY_IA_H

#define NB_MIN_FOOD (6)
#define NB_MAX_FOOD (40)

#define NB_RESOURCES (7)
#define NB_RESOURCES_NEEDED (6)

#include <stdbool.h>
#include "list.h"
#include "client.h"

void		ia_action(t_client *);
/* !MODE */
void		ia_survive(t_client *);
void		ia_recipes(t_client *);
/* !SUB */
void		ia_move_to_tile(t_client *, int);
void		ia_empty_tile_to_evolve(t_client *);
int		ia_get_index_for_object(t_client *, e_object);
int		ia_get_amount_for_index(t_client *, int, e_object);
bool		ia_find_resources_to_evolve(t_client *, t_requisite);
void		ia_recipes_alone(t_client *);
void		ia_recipes_group(t_client *, t_requisite);
void		ia_ask_for_needed_res(t_client *, t_requisite);

extern char	*object_to_string[NB_RESOURCES];

#endif /* PSU_2016_ZAPPY_IA_H */
