SRCDIR	:=	srcs
OBJDIR	:=	objs
INCDIR	:=	includes
FILES	:=	\
			main.cpp\

SRCS	:=	$(FILES:%.cpp=$(SRCDIR)/%.cpp)
OBJS	:=	$(FILES:%.cpp=$(OBJDIR)/%.o)
NAME	:=	ft_shmup

CXX			:=	c++
CCOREFLAGS	=	-Wall -Wextra -Werror -std=gnu++0x -I$(INCDIR)
CFLAGS		=	$(CCOREFLAGS) -O3\
				# -D DEBUG\
				# -g -fsanitize=address -fsanitize=undefined\

LFLAGS		:=	-lncurses

RM			:=	rm -rf

all:			$(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^ $(LFLAGS)

.PHONY:	clean
clean:
	$(RM) $(OBJDIR)

.PHONY:	fclean
fclean:			clean
	$(RM) $(NAME)

.PHONY:	re
re:				fclean all
