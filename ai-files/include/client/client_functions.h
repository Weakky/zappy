/*
** client_functions.h for  in PSU_2016_myirc
** 
** Made by clément
** Login   <clement.deseine@epitech.eu>
** 
** Started on  Thu Jun  8 19:03:47 2017 clément
** Last update Thu Jun  8 19:04:31 2017 clément
*/

#ifndef PSU_2016_MYIRC_CLIENT_FUNCTIONS_H
#define PSU_2016_MYIRC_CLIENT_FUNCTIONS_H

#include	"client.h"

int	client_connect(t_client *);
int	client_write(t_client *);
int	client_read(t_client *);

void welcome(t_client *client);
bool check_ok(t_client *client, char *response, char *arg);
bool look(t_client *client, char *response, char *arg);
bool forward(t_client *client, char *response, char *arg);
bool left(t_client *client, char *response, char *arg);
bool right(t_client *client, char *response, char *arg);
bool inventory(t_client *client, char *response, char *arg);
bool connect_nbr(t_client *client, char *response, char *arg);
bool take_object(t_client *client, char *response, char *arg);
bool set_object(t_client *client, char *response, char *arg);
bool incantation(t_client *client, char *response, char *arg);
bool handle_broadcast(t_client *client, char *response, bool *keep_reading);
bool handle_incantation_second(t_client *client, char *response);
void parse_inventory(t_client *client, char *response);
e_object **parse_look(char *response);

#endif /* !PSU_2016_MYIRC_CLIENT_FUNCTIONS_H */
