/*
** circular_buffer_functions.h for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Fri Jun  9 13:06:13 2017 clément
** Last update Fri Jun  9 13:07:18 2017 clément
*/

#ifndef PSU_2016_ZAPPY_CIRCULAR_BUFFER_FUNCTIONS_H
#define PSU_2016_ZAPPY_CIRCULAR_BUFFER_FUNCTIONS_H

#include	"circular_buffer.h"

int	circular_buffer_push(t_circular_buffer *, void const *, const size_t);
int	circular_buffer_pop(t_circular_buffer *, void *);

#endif /* !PSU_2016_ZAPPY_CIRCULAR_BUFFER_FUNCTIONS_H */
