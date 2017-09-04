/*
** list_create.c for  in /home/desein_c/rendu/list
** 
** Made by clement
** Login   <desein_c@epitech.net>
** 
** Started on  Tue Jun 21 13:31:28 2016 clement
** Last update Tue Jun 21 13:31:30 2016 clement
*/

#include	"list.h"

t_list		*list_create()
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  new->node = NULL;
  new->first = NULL;
  new->last = NULL;
  return (new);
}
