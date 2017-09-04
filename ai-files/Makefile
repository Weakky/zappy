##
## Makefile for  in /home/desein_c/rendu/données
##
## Made by clement
## Login   <desein_c@epitech.net>
##
## Started on  Thu May 19 16:08:51 2016 clement
## Last update Wed Jun 28 13:40:39 2017 clément
##

NAME = ../zappy_ai

SRC  =   broadcast/broadcast.c \
         broadcast/broadcast_message_group.c \
         broadcast/broadcast_message_personal.c \
         broadcast/broadcast_message_survive.c \
         broadcast/broadcast_send_group.c \
         broadcast/broadcast_send_personal.c \
         broadcast/broadcast_send_survive.c \
         circular_buffer/circular_buffer.c \
         circular_buffer/circular_buffer_functions.c \
         client/client.c \
         client/client_connect.c \
         client/client_read.c \
         client/client_write.c \
         client/player.c \
         client/player_global_inventory.c \
         client/player_group.c \
         client/player_whitelist.c \
         client/requisites.c \
         commands/check_ok.c \
         commands/connect_nbr.c \
         commands/incantation.c \
         commands/inventory.c \
         commands/look.c \
         commands/parse_inventory.c \
         commands/parse_look.c \
         commands/take_set_object.c \
         commands/welcome.c \
         ia/ia_action.c \
         ia/ia_move.c \
         ia/ia_recipes.c \
         ia/ia_recipes_alone.c \
         ia/ia_recipes_find_objects.c \
         ia/ia_recipes_find_resources.c \
         ia/ia_recipes_group.c \
         ia/ia_recipes_group_need.c \
         ia/ia_send_command.c \
         ia/ia_survive.c \
         utils/free_tab.c \
         utils/my_split.c \
         utils/my_strchr.c \
         utils/my_strtok.c \
         error.c \
         get_arguments.c \
         get_arguments_port.c \
         broadcast/utils_message_group.c \
         ia/ia_prepare_tile_to_evolve.c \
         main.c

SRCDIR = ./src/
LIBDIR = ./lib/

INC = -I./include -I./include/client -I./include/circular_buffer

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
