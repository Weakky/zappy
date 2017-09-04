/*
** commands_ai_broadcast_direction.c for  in PSU_2016_zappy
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Tue Jun 27 11:10:01 2017 clément
** Last update Tue Jun 27 11:10:02 2017 clément
*/

#include	<string.h>
#include	<math.h>
#include	"drone.h"
#include	"socket.h"

static int	define_postions(t_argument *argument, t_position dest,
				t_position (*pos)[4])
{
  if (dest.x > argument->width / 2)
    {
      (*pos)[1].x -= argument->width;
      (*pos)[3].x -= argument->width;
    }
  else
    {
      (*pos)[1].x += argument->width;
      (*pos)[3].x += argument->width;
    }
  if (dest.x > argument->height / 2)
    {
      (*pos)[2].y -= argument->height;
      (*pos)[3].y -= argument->height;
    }
  else
    {
      (*pos)[2].y += argument->height;
      (*pos)[3].y += argument->height;
    }
  return (0);
}

static int	define_dists(t_position *pos, t_position org,
			     t_dist (*dists)[4])
{
  int		i;

  i = -1;
  while (++i < 4)
    {
      (*dists)[i].diff_x = org.x - pos[i].x;
      (*dists)[i].diff_y = org.y - pos[i].y;
      (*dists)[i].dist = sqrt(pow((double)((*dists)[i].diff_x), 2)
			      + pow((double)((*dists)[i].diff_y), 2));
    }
  return (0);
}

static int	determine_angle_num(t_drone *drone, t_dist dist)
{
  int		res;

  if (!dist.diff_y && !dist.diff_x)
    return (0);
  if (!dist.diff_x)
    res = ((dist.diff_y > 0) ? (5) : (1));
  else if (!dist.diff_y)
    res = ((dist.diff_x > 0) ? (7) : (3));
  else if (dist.diff_y < 0)
    res = ((dist.diff_x > 0) ? (8) : (2));
  else
    res = ((dist.diff_x > 0) ? (6) : (4));
  res = res + 2 * drone->direction;
  if (res > 8)
    res = res % 8;
  return (res);
}

int		commands_ai_find_directon(t_socket *socket, t_socket *dest,
					  t_argument *argument)
{
  int		i;
  int		shorter_dist;
  t_position	pos[4];
  t_dist	dists[4];

  i = -1;
  while (++i < 4)
    memcpy(&(pos[i]), &(dest->drone->pos), sizeof(t_position));
  define_postions(argument, dest->drone->pos, &pos);
  define_dists(pos, socket->drone->pos, &dists);
  i = 0;
  shorter_dist = 0;
  while (++i < 4)
    {
      if (dists[i].dist < dists[shorter_dist].dist)
	shorter_dist = i;
    }
  return (determine_angle_num(dest->drone, dists[shorter_dist]));
}
