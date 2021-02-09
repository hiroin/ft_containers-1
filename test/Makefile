# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 17:34:06 by dnakano           #+#    #+#              #
#    Updated: 2021/02/10 07:57:34 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:=	main.cpp test_util.cpp test_vector.cpp Hoge.cpp
OBJS		:=	$(SRCS:%.cpp=%.o)
HEADERS		:=	vector.hpp
HEADERDIR	:=	..
NAME		:=	test.out
OUTDIR		:=	.

CXX			:=	clang++
CPPFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I$(HEADERDIR)

.PHONY:		all
all:		test

$(NAME):	$(OBJS) $(HEADERDIR)/$(HEADERS)
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
