#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebijuu <nidzik@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/24 14:54:12 by lebijuu           #+#    #+#              #
#    Updated: 2015/03/24 18:36:57 by lebijuu          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

#LIBFT
LFTPATH = libft/
LFTIPATH = -I $(LFTPATH)
LFT = -L $(LFTPATH) -lft

OBJPATH = obj
SRCPATH = .
INCLUDE = -I ./

CC = gcc

#FLAGS UBUNTU FDF
UFLAGS = -L/usr/lib/X11/ -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
#FLAGS MAC FDF
MFLAGS = -L/usr/X11/lib -lX11 -lXext -lmlx 

LIBS = $(LFT) $(UFLAGS) 
INCLUDES = $(INCLUDE) $(LFTPATH)

LFTALL = all

BASEFLAGS = -Wall -Wextra
CFLAGS = $(BASEFLAGS) -Werror -O2


SRCFILES = ft_array.c ft_coord2d.c ft_fdf.c get_next_line.c ft_check.c ft_coord3d.c \
				ft_line.c


SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)


RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
E = \033[39m

W = 0

all : l $(NAME)

$(NAME) : $(OBJECTS)
	@echo "$(Y)[COMPILING FDF] $(E) $(CC) -o $@ $(CFLAGS) obj.o $(LIBS)"
	@$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)
	@echo "$(R)[COMPILING FDF] $(E)"

$(OBJECTS) : $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) $(LIBS) -c $<
 
clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

l:
	@echo "$(Y)[COMPILING LIBFT] $(E) make -C $(LFTPATH) $(LFTALL)"
	@$(MAKE) -C $(LFTPATH) $(LFTALL)
	@echo "$(R)[COMPILING LIBFT DONE]$(E)"


re: fclean all