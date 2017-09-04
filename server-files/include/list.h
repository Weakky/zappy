/*
** list.h for  in /home/desein_c/rendu/temp
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Mon Jun 20 13:35:20 2016 clement
** Last update Sun Jun 11 18:14:10 2017 clément
*/

#ifndef		LIST_H_
# define	LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct		s_list_node
{
  void			*data;
  struct s_list_node	*next;
  struct s_list_node	*prev;
}			t_list_node;

typedef struct		s_list
{
  t_list_node		*node;
  t_list_node		*first;
  t_list_node		*last;
}			t_list;

t_list		*list_create();
t_list_node 	*list_pop_first(t_list *list);
t_list_node	*list_pop_last(t_list *list);
t_list_node	*list_pop_node(t_list *list, t_list_node *node);
bool		list_insert(t_list *list, void *data);
bool		list_append(t_list *list, void *data);
bool		list_free(t_list *list, void (*f)(void *));
bool		list_delete_first(t_list *list,  void (*f)(void *));
bool		list_delete_last(t_list *list,  void (*f)(void *));
bool		list_delete_node(t_list *list, void (*f)(void *), t_list_node *node);
bool		list_execute(t_list *list, void *arg1, void *arg2,
			     int (*f)(void *data, void *arg1, void *arg2));
bool            list_execute_reverse(t_list *list, void *arg1, void *arg2,
				     int (*f)(void *data, void *arg1, void *arg2));
bool		list_insert_condition(t_list *list, void *data, void *param,
			   bool (*f)(void *, void *, void *));
bool		list_sort(t_list *list, void *arg1, void * arg2,
                      bool (*f)(void *, void *, void *, void *));
#endif /* !LIST_H_ */
