##
## Makefile for  in /home/desein_c/rendu/données
##
## Made by clement
## Login   <desein_c@epitech.net>
##
## Started on  Thu May 19 16:08:51 2016 clement
## Last update Wed Jun 28 13:40:39 2017 clément
##

NAME = ../zappy_server

SRC  = main.c \
	   circular_buffer/circular_buffer.c \
	   circular_buffer/circular_buffer_functions.c \
	   action/action_ai_action.c \
  	   action/action_ai_broadcast.c \
  	   action/action_ai_eject.c \
	   action/action_ai_elevation.c \
 	   action/action_ai_fork.c \
	   action/action_ai_look.c \
	   action/action_ai_move.c \
	   action/action_ai_personal.c \
	   commands/commands_setter.c \
   	   commands/commands_unknown.c \
   	   commands/commands_ai_broadcast.c \
   	   commands/commands_ai_broadcast_direction.c \
   	   commands/commands_default.c \
   	   commands/commands_ai_move.c \
   	   commands/commands_ai_eat.c \
       commands/commands_ai_personal.c \
       commands/commands_ai_look.c \
       commands/commands_ai_look_direction.c \
       commands/commands_ai_action.c \
       commands/commands_ai_elevation.c \
       commands/commands_ai_fork.c \
       commands/commands_graphic_map.c \
       commands/commands_graphic_time.c \
       commands/commands_graphic_player.c \
       commands/commands_static.c \
   	   response/response_graphic_map.c \
   	   response/response_graphic_player.c \
  	   response/response_graphic_action.c \
  	   response/response_graphic_incantation.c \
   	   response/response_graphic_egg.c \
   	   response/response_graphic_die.c \
   	   response/response_graphic_time.c \
       server/server.c \
	   server/server_socks.c \
  	   server/server_list.c \
  	   server/server_map.c \
	   server/server_wait.c \
  	   server/server_update_time.c \
	   socket/client_socket.c \
   	   socket/client_socket_execute.c \
	   socket/client_socket_read.c \
	   socket/client_socket_write.c \
	   socket/delete_socket.c \
	   socket/server_socket.c \
	   drone/drone.c \
  	   drone/drone_egg.c \
  	   events/events_map.c \
   	   events/events_action.c \
	   events/events_dispatch.c \
	   events/events_move.c \
	   events/events_elevation.c \
	   events/events_egg.c \
  	   events/events_new_monitor.c \
  	   events/events_player.c \
	   get_arguments.c \
	   get_arguments_map.c \
	   get_arguments_team.c \
	   utils/my_split.c \
	   utils/my_strchr.c \
	   utils/my_trim.c \
	   utils/error.c

SRCDIR = ./src/
LIBDIR = ./lib/

INC = -I./include -I./include/circular_buffer -I./include/server -I./include/socket -I./include/drone

OBJDIR = .obj/

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC = gcc

CFLAGS += -g -W -Wall -Wextra -Werror $(INC)
LDFLAGS += -L$(LIBDIR)
LDLIBS += -llist -lm

RM = rm -f
ECHO = printf "%-70s%s\n"

MAKE = make -s -C

all : lib $(NAME)

lib:
	@$(MAKE) $(LIBDIR)

$(OBJDIR)%.o:	$(SRCDIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) $< "[COMPILED]"

$(NAME) :	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@$(ECHO) $(NAME) "[COMPILED]"

clean :
	@$(MAKE) $(LIBDIR) clean
	-@$(RM) -rf $(OBJDIR)
	@$(ECHO) ".obj/" "[REMOVED]"
	-@$(RM) */*~ *~
	@$(ECHO) "*~ #*#" "[REMOVED]"
	-@$(RM) */\#*# \#*#

fclean :	clean
	@$(MAKE) $(LIBDIR) fclean
	-@$(RM) $(NAME)
	@$(ECHO) $(NAME) "[REMOVED]"

re : 	fclean all

.PHONY : lib all clean fclean re $(OBJDIR)%.o debug
