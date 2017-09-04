/*
** circular_buffer.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 13:07:29 2017 clément
** Last update Fri Jun  9 13:25:39 2017 clément
*/

#ifndef PSU_2016_ZAPPY_CIRCULAR_BUFFER_H
#define PSU_2016_ZAPPY_CIRCULAR_BUFFER_H

#include	<stdlib.h>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

typedef struct	s_circular_buffer
{
  void		*buffer;
  void		*buffer_end;
  void		*head;
  void		*tail;
  size_t	capacity;
  size_t	count;
  size_t	elm_size;
  int		(*const push)(struct s_circular_buffer *,
                           void const *, size_t const);
  int		(*const pop)(struct s_circular_buffer *, void *);
}		t_circular_buffer;

t_circular_buffer	*init_circular_buffer(size_t const, size_t const);
void			delete_circular_buffer(t_circular_buffer *);

#endif /* !PSU_2016_ZAPPY_CIRCULAR_BUFFER_H */
