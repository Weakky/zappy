/*
** circular_buffer.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Thu Jun  8 19:10:21 2017 clément
** Last update Sun Jun 11 18:27:11 2017 clément
*/

#include	<stdio.h>
#include	<string.h>
#include	"circular_buffer.h"
#include	"circular_buffer_functions.h"

t_circular_buffer		*init_circular_buffer(size_t const capacity,
						      size_t const elm_size)
{
  t_circular_buffer		*buffer;
  const t_circular_buffer	template = {NULL, NULL, NULL, NULL,
					    capacity, 0, elm_size,
					    circular_buffer_push,
					    circular_buffer_pop};

  if (!(buffer = calloc(sizeof(t_circular_buffer), 1)))
    return (NULL);
  memcpy(buffer, &template, sizeof(t_circular_buffer));
  buffer->count = 0;
  buffer->capacity = capacity;
  buffer->elm_size = elm_size;
  if (!(buffer->buffer = calloc(elm_size, capacity)))
    return (NULL);
  bzero(buffer->buffer, elm_size * capacity);
  buffer->buffer_end = buffer->buffer + elm_size * capacity;
  buffer->head = buffer->buffer;
  buffer->tail = buffer->buffer;
  return (buffer);
}

void				delete_circular_buffer(t_circular_buffer
							   *circular_buffer)
{
  if (circular_buffer)
    {
      free(circular_buffer->buffer);
      free(circular_buffer);
    }
}
