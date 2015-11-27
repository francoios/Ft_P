NAME		=	Compilation

NAMEBASE	=	$(shell basename $(NAME))

.SILENT:

all: $(NAME)
	make -C ./libft/
	make -C ./server/
	make -C ./client/
	echo "\033[38;5;44m✅  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):
	echo -en "\r\033[38;5;22m✅  MAKE   $(NAMEBASE)\033[0m\033[K"

server:
	printf "\r\033[38;5;11m⌛  SERVER  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C ./server/

client:
	printf "\r\033[38;5;11m⌛  CLIENT  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C ./client/

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C ./libft/ clean
	make -C ./server/ clean
	make -C ./client/ clean

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C ./libft/ fclean
	make -C ./server/ fclean
	make -C ./client/ fclean

re:			fclean all ./libft/libft.a

.PHONY:		fclean clean re client server
