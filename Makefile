##
## Makefile for $ in PSU_2016_zappy
## 
## Made by clément
## Login   <clement.deseine@epitech.eu>
## 
## Started on  Mon May 22 12:35:25 2017 clément
## Last update Mon Jun 12 14:53:10 2017 clément
##

SERVER_DIR  = server-files
AI_DIR  = ai-files

MAKE = make -s -C

all: zappy_server zappy_ai

zappy_server:
	@$(MAKE) $(SERVER_DIR)

zappy_ai:
	@$(MAKE) $(AI_DIR)

clean:
	@$(MAKE) $(SERVER_DIR) clean
	@$(MAKE) $(AI_DIR) clean

fclean:
	@$(MAKE) $(SERVER_DIR) fclean
	@$(MAKE) $(AI_DIR) fclean

re: fclean all

.PHONY: all zappy_server zappy_ai clean fclean re
