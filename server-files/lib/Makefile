##
## Makefile for  in /home/desein_c/rendu/données/files
## 
## Made by clement
## Login   <desein_c@epitech.net>
## 
## Started on  Mon Jun 20 11:15:48 2016 clement
## Last update Mon May 22 12:26:34 2017 clément
##

NAME = liblist.a

SRC = list_add.c \
	  list_create.c \
	  list_delete.c \
	  list_execute.c \
	  list_free.c \
	  list_pop.c \
	  list_sort.c

SRCDIR	= list/
OBJDIR	= .obj/

RM	= rm -f
ECHO	= printf "%-70s%s\n"

CFLAGS	= -W -Wall -Wextra -Werror -I ../include

OBJ	= $(SRC:%.c=$(OBJDIR)%.o)

all: $(NAME)

$(OBJDIR)%.o:       $(SRCDIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) $< "[COMPILED]"

$(NAME):	$(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(ECHO) $(NAME) "[COMPILED]"

clean:
	-@$(RM) -r $(OBJ)
	-@$(RM) */*~ *~
	-@$(RM) */\#*# \#*#
	@$(ECHO) $(NAME) "[CLEANED]"

fclean: clean
	-@$(RM) $(NAME)
	@$(ECHO) $(NAME) "[REMOVED]"

re: fclean all
