/*
** list_delete.c for  in /home/desein_c/rendu/list
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Tue Jun 21 13:31:47 2016 clement
** Last update Tue Jun 21 13:31:48 2016 clement
*/

#include	"list.h"

bool		list_delete_first(t_list *list,  void (*f)(void *))
{
  t_list_node	*temp;

  if (list == NULL || list->first == NULL)
    return (false);
  if (list->last == list->first)
    list->last = list->first->next;
  if (list->node == list->first)
    list->node = list->first->next;
  temp = list->first;
  list->first = list->first->next;
  f(temp->data);
  free(temp);
  if (list->first != NULL)
    list->first->prev = NULL;
  return (true);
}

bool		list_delete_last(t_list *list,  void (*f)(void *))
{
  t_list_node	*temp;

  if (list == NULL || list->last == NULL)
    return (false);
  if (list->first == list->last)
    list->first = list->first->prev;
  if (list->node == list->last)
    list->node = list->node->prev;
  temp = list->last;
  list->last = list->last->prev;
  f(temp->data);
  free(temp);
  if (list->last != NULL)
    list->last->next = NULL;
  return (true);
}

static void	node_pointer_moving(t_list *list, t_list_node **node)
{
  if (list->first == list->node)
    {
      if (*node != NULL && *node == list->first)
	*node = (*node)->next;
      list->first = list->first->next;
    }
  if (list->last == list->node)
    {
      if (*node != NULL && *node == list->last)
	*node = (*node)->prev;
      list->last = list->last->prev;
    }
}

bool		list_delete_node(t_list *list, void (*f)(void *), t_list_node *node)
{
  t_list_node	*prev;
  t_list_node	*next;

  if (list == NULL)
    return (false);
  prev = list->node->prev;
  next = list->node->next;
  if (prev != NULL)
    prev->next = next;
  if (next != NULL)
    next->prev = prev;
  node_pointer_moving(list, &node);
  f(list->node->data);
  free(list->node);
  list->node = node;
  return (true);
}
