# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 17:34:06 by dnakano           #+#    #+#              #
#    Updated: 2021/07/07 02:14:10 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:=	main.cpp test_util.cpp test_vector.cpp \
				test_map.cpp test_stack.cpp \
				test_vector_bool.cpp Hoge.cpp
OBJS		:=	$(SRCS:%.cpp=%.o)
HEADERS		:=	vector.hpp map.hpp stack.hpp
HEADERDIR	:=	..
NAME		:=	test.out
OUTDIR		:=	.

CXX			:=	clang++
CPPFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I$(HEADERDIR)

.PHONY:		all
all:		test

$(NAME):	$(OBJS) $(addprefix $(HEADERDIR)/,$(HEADERS))
			$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

.PHONY:		test
test:		$(NAME)
			$(OUTDIR)/$(NAME)

.PHONY:		clean
clean:
			rm -f $(OBJS)

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)

.PHONY:		re
re:			fclean all
