cmake_minimum_required(VERSION 3.7)
project(PSU_2016_zappy)

set(CMAKE_CXX_STANDARD 11)

include_directories(ai-files/include)
include_directories(ai-files/include/client)
include_directories(ai-files/include/circular_buffer)

set(SOURCE_FILES
        ai-files/include/circular_buffer/circular_buffer.h
        ai-files/include/circular_buffer/circular_buffer_functions.h
        ai-files/include/client/client.h
        ai-files/include/client/client_functions.h
        ai-files/include/client/player.h
        ai-files/include/argument.h
        ai-files/include/broadcast.h
        ai-files/include/error.h
        ai-files/include/ia.h
        ai-files/include/list.h
        ai-files/include/utils.h
        ai-files/lib/list/list_add.c
        ai-files/lib/list/list_create.c
        ai-files/lib/list/list_delete.c
        ai-files/lib/list/list_execute.c
        ai-files/lib/list/list_free.c
        ai-files/lib/list/list_pop.c
        ai-files/lib/list/list_sort.c
        ai-files/src/broadcast/broadcast.c
        ai-files/src/broadcast/broadcast_message_group.c
        ai-files/src/broadcast/broadcast_message_personal.c
        ai-files/src/broadcast/broadcast_message_survive.c
        ai-files/src/broadcast/broadcast_send_group.c
        ai-files/src/broadcast/broadcast_send_personal.c
        ai-files/src/broadcast/broadcast_send_survive.c
        ai-files/src/circular_buffer/circular_buffer.c
        ai-files/src/circular_buffer/circular_buffer_functions.c
        ai-files/src/client/client.c
        ai-files/src/client/client_connect.c
        ai-files/src/client/client_read.c
        ai-files/src/client/client_write.c
        ai-files/src/client/player.c
        ai-files/src/client/player_global_inventory.c
        ai-files/src/client/player_group.c
        ai-files/src/client/player_whitelist.c
        ai-files/src/client/requisites.c
        ai-files/src/commands/check_ok.c
        ai-files/src/commands/connect_nbr.c
        ai-files/src/commands/incantation.c
        ai-files/src/commands/inventory.c
        ai-files/src/commands/look.c
        ai-files/src/commands/parse_inventory.c
        ai-files/src/commands/parse_look.c
        ai-files/src/commands/take_set_object.c
        ai-files/src/commands/welcome.c
        ai-files/src/ia/ia_action.c
        ai-files/src/ia/ia_move.c
        ai-files/src/ia/ia_recipes.c
        ai-files/src/ia/ia_recipes_alone.c
        ai-files/src/ia/ia_recipes_find_objects.c
        ai-files/src/ia/ia_recipes_find_resources.c
        ai-files/src/ia/ia_recipes_group.c
        ai-files/src/ia/ia_recipes_group_need.c
        ai-files/src/ia/ia_send_command.c
        ai-files/src/ia/ia_survive.c
        ai-files/src/utils/free_tab.c
        ai-files/src/utils/my_split.c
        ai-files/src/utils/my_strchr.c
        ai-files/src/utils/my_strtok.c
        ai-files/src/error.c
        ai-files/src/get_arguments.c
        ai-files/src/get_arguments_port.c
        ai-files/src/broadcast/utils_message_group.c
        ai-files/src/ia/ia_prepare_tile_to_evolve.c
        ai-files/src/main.c)

add_executable(PSU_2016_zappy ${SOURCE_FILES})
target_link_libraries(PSU_2016_zappy m)