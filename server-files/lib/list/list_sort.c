/*
** list_sort.c for  in /home/desein_c/rendu/données/temp
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Sun Feb 19 13:34:19 2017 clément
** Last update Mon Jun 26 12:56:43 2017 clément
*/

#include	"list.h"

bool		list_sort(t_list *list, void *arg1, void * arg2,
			  bool (*f)(void *, void *, void *, void *))
{
  t_list_node	*node;
  t_list_node	*cond;
  void	*back;

  node = list->first;
  while (node)
    {
      cond = node->next;
      while (cond)
	{
	  if (!f(node->data, cond->data, arg1, arg2))
	    {
	      back = node->data;
	      node->data = cond->data;
	      cond->data = back;
	    }
	  cond = cond->next;
	}
      node = node->next;
    }
  return (true);
}
