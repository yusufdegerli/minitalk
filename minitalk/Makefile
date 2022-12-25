# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 18:03:34 by ydegerli          #+#    #+#              #
#    Updated: 2022/12/24 18:03:36 by ydegerli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT				= client.c
SERVER				= server.c
CLIENT_BONUS		= client_bonus.c
SERVER_BONUS		= server_bonus.c

CL_OBJS				= $(CLIENT:.c=.o)
SR_OBJS				= $(SERVER:.c=.o)
CL_OBJS_BONUS		= $(CLIENT_BONUS:.c=.o)
SR_OBJS_BONUS		= $(SERVER_BONUS:.c=.o)

PRINTF				= cd ft_printf && make
LIB						=ft_printf/libftprintf.a

CC					= gcc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror -I include

CLIENT_NAME			= client
SERVER_NAME			= server
CLIENT_NAME_B		= client_bonus
SERVER_NAME_B		= server_bonus

all:				ft_printf $(SERVER_NAME) $(CLIENT_NAME)

ft_printf:
					@$(PRINTF)
$(SERVER_NAME): $(SR_OBJS)
				@$(CC) $(CFLAGS) $(SR_OBJS) $(LIB) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CL_OBJS)
				@$(CC) $(CFLAGS) $(CL_OBJS) $(LIB) -o $(CLIENT_NAME)

bonus: ft_printf $(SERVER_NAME_B) $(CLIENT_NAME_B)

$(SERVER_NAME_B):$(SR_OBJS_BONUS)
				@$(CC) $(CFLAGS) $(SR_OBJS_BONUS) $(LIB) -o $(SERVER_NAME_B)

$(CLIENT_NAME_B):$(CL_OBJS_BONUS)
				@$(CC) $(CFLAGS) $(CL_OBJS_BONUS) $(LIB) -o $(CLIENT_NAME_B)

clean:
				$(RM) $(CL_OBJS) $(SR_OBJS) $(CLIENT_NAME) $(SERVER_NAME) \
				 $(CL_OBJS_BONUS) $(SR_OBJS_BONUS) $(CLIENT_NAME_B) $(SERVER_NAME_B)
				@cd ft_printf && make clean
fclean:			clean
				@cd ft_printf && make fclean
re:				fclean all
.PHONY:			all ft_printf clean fclean re