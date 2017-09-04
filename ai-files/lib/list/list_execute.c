
/*
** list_execute.c for  in /home/desein_c/rendu/list
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Tue Jun 21 13:39:09 2016 clement
** Last update Fri Feb 17 17:35:36 2017 clément
*/

#include	"list.h"

bool		list_execute(t_list *list, void *arg1, void *arg2,
			     int (*f)(void *data, void *arg1, void *arg2))
{
  t_list_node	*back;

  if (list == NULL)
    return (false);
  back = list->node;
  list->node = list->first;
  while (list->node != NULL)
    {
      f(list->node->data, arg1, arg2);
      list->node = list->node->next;
    }
  list->node = back;
  return (true);
}

bool		list_execute_reverse(t_list *list, void *arg1, void *arg2,
			     int (*f)(void *data, void *arg1, void *arg2))
{
  t_list_node   *back;

  if (list == NULL)
    return (false);
  back = list->node;
  list->node = list->last;
  while (list->node != NULL)
    {
      f(list->node->data, arg1, arg2);
      list->node = list->node->prev;
    }
  list->node = back;
  return (true);
}
