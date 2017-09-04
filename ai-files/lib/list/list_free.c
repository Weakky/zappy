/*
** list_free.c for  in /home/desein_c/rendu/temp
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Mon Jun 20 14:24:40 2016 clement
** Last update Mon Jun 20 14:30:58 2016 clement
*/

#include	"list.h"

bool		list_free(t_list *list, void (*func)(void *))
{
  t_list_node	*temp;

  if (list == NULL)
    return (false);
  while (list->node != NULL)
    {
      temp = list->node;
      list->node = list->node->next;
      if (func)
        func(temp->data);
      free(temp);
    }
  free(list);
  return (true);
}
