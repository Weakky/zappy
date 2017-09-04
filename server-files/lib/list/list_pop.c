/*
** list_pop.c for  in /home/desein_c/rendu/list
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Tue Jun 21 13:31:55 2016 clement
** Last update Tue Jun 21 13:31:56 2016 clement
*/

#include	"list.h"

t_list_node	*list_pop_first(t_list *list)
{
  t_list_node	*res;

  if (list == NULL || list->first == NULL)
    return (false);
  if (list->last == list->first)
    list->last = list->first->next;
  if (list->node == list->first)
    list->node = list->first->next;
  res = list->first;
  list->first = list->first->next;
  if (list->first != NULL)
    list->first->prev = NULL;
  return (res);
}

t_list_node	*list_pop_last(t_list *list)
{
  t_list_node	*res;

  if (list == NULL || list->last == NULL)
    return (false);
  if (list->first == list->last)
    list->first = list->first->prev;
  if (list->node == list->last)
    list->node = list->node->prev;
  res = list->last;
  list->last = list->last->prev;
  if (list->last != NULL)
    list->last->next = NULL;
  return (res);
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

t_list_node	*list_pop_node(t_list *list, t_list_node *node)
{
  t_list_node	*prev;
  t_list_node	*next;
  t_list_node	*res;

  if (list == NULL)
    return (false);
  prev = list->node->prev;
  next = list->node->next;
  if (prev != NULL)
    prev->next = next;
  if (next != NULL)
    next->prev = prev;
  node_pointer_moving(list, &node);
  res = list->node;
  res->prev = NULL;
  res->next = NULL;
  list->node = node;
  return (res);
}
