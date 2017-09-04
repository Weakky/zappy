/*
** my_split.c for  in PSU_2016_myirc
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Sun May 21 23:32:34 2017 clément
** Last update Sun May 21 23:32:35 2017 clément
*/

#include	<stdlib.h>
#include	"utils.h"

static int	another_split(char *src, char *split)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      if (my_strchr(split, src[i]) != src[i])
	return (0);
      i++;
    }
  return (-1);
}

static int	word_split(char *src, char *split)
{
  int		i;
  int		res;

  i = 0;
  res = 0;
  while (src[i] != '\0')
    {
      if (i > 0 && my_strchr(split, src[i]) == src[i])
	if (my_strchr(split, src[i - 1]) != src[i - 1])
	  if (another_split(&src[i], split) == 0)
	    res++;
      i++;
    }
  if (res == 0)
    return (0);
  return (res + 1);
}

static int	len_split(char *src, char *split)
{
  int		i;

  i = 0;
  while (src[i] != '\0' && my_strchr(split, src[i]) != src[i])
    i++;
  return (i);
}

static char	*add_split(char *src, char *split, int len)
{
  int		i;
  char		*res;

  i = 0;
  if ((res = malloc(sizeof (char) * (len + 1))) == NULL)
    return (NULL);
  while (src[i] != '\0' && my_strchr(split, src[i]) != src[i])
    {
      res[i] = src[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char		**my_split(char *src, char *split)
{
  char		**res;
  int		nb_word;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (src == NULL || split == NULL)
    return (NULL);
  nb_word = word_split(src, split);
  if ((res = malloc(sizeof (char *) * (nb_word + 2))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      while (src[i] != '\0' && my_strchr(split, src[i]) == src[i])
	i++;
      if (src[i] != '\0')
	res[j++] = add_split(&src[i], split, len_split(&src[i], split));
      while (src[i] != '\0' && my_strchr(split, src[i]) != src[i])
	i++;
    }
  res[j] = NULL;
  return (res);
}
