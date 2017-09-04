/*
** circular_buffer_functions.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Thu Jun  8 19:21:06 2017 clément
** Last update Fri Jun  9 13:26:39 2017 clément
*/

#include	<string.h>
#include	"circular_buffer.h"

int	circular_buffer_push(t_circular_buffer *buffer, void const *ptr)
{
  memcpy(buffer->head, ptr, buffer->elm_size);
  buffer->head += buffer->elm_size;
  if (buffer->head == buffer->buffer_end)
    buffer->head = buffer->buffer;
  buffer->count = MIN(buffer->count + 1, buffer->capacity);
  return (0);
}

int	circular_buffer_pop(t_circular_buffer *buffer, void *ptr)
{
  if (!buffer->count)
    return (-1);
  memcpy(ptr, buffer->tail, buffer->elm_size);
  buffer->tail += buffer->elm_size;
  if (buffer->tail == buffer->buffer_end)
    buffer->tail = buffer->buffer;
  buffer->count = MAX(buffer->count - 1, 0);
  return (0);
}
