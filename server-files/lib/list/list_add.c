/*
** list_add.c for  in /home/desein_c/rendu/list
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Tue Jun 21 13:31:38 2016 clement
** Last update Sun Feb 19 14:45:10 2017 clément
*/

#include	"list.h"

bool		list_insert(t_list *list, void *data)
{
  t_list_node	*new;

  if (list == NULL || (new = malloc(sizeof(t_list_node))) == NULL)
    return (false);
  new->data = data;
  if (list->first == NULL)
    {
      list->last = new;
      new->next = NULL;
    }
  else
    {
      list->first->prev = new;
      new->next = list->first;
    }
  new->prev = NULL;
  list->first = new;
  list->node = new;
  return (true);
}

bool		list_append(t_list *list, void *data)
{
  t_list_node	*new;

  if (list == NULL || (new = malloc(sizeof(t_list_node))) == NULL)
    return (false);
  new->data = data;
  if (list->first == NULL)
    {
      new->prev = NULL;
      list->first = new;
      list->node = new;
    }
  else
    {
      new->prev = list->last;
      list->last->next = new;
    }
  list->last = new;
  new->next = NULL;
  return (true);
}

static bool	link_node_condition(t_list *list, t_list_node *temp,
				       t_list_node *new)
{
  if (!temp)
    {
      new->next = NULL;
      new->prev = list->last;
      if (list->last)
	list->last->next = new;
      else
	{
	  list->first = new;
	  list->node = new;
	}
      list->last = new;
    }
  else
    {
      new->next = temp;
      new->prev = temp->prev;
      if (!temp->prev)
	list->first = new;
      else
	temp->prev->next = new;
      temp->prev = new;
    }
  return (true);
}

bool		list_insert_condition(t_list *list, void *data, void *param,
					  bool (*f)(void *, void *, void *))
{
  t_list_node	*new;
  t_list_node	*temp;

  if (list == NULL || (new = malloc(sizeof(t_list_node))) == NULL)
    return (false);
  temp = list->first;
  new->data = data;
  while (temp && !f(temp->data, data, param))
    temp = temp->next;
  link_node_condition(list, temp, new);
  return (true);
}
