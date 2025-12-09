CC=gcc
CFLAGS= -Wall -Wextra -Werror
NAME=philo
OBJ= $(SRC:%.c=%.o)
SRC = 	main.c \
		args_handler/ft_set_args.c \
		args_handler/ft_get_av.c \
		args_handler/ft_get_ac.c \
		args_handler/ft_get_envp.c \
		args_handler/ft_check_args.c \
		args_handler/ft_check_av_only_allowed_char.c \
		args_handler/ft_is_argc.c \
		ctype/ft_isdigit.c \
		ctype/ft_isspace.c \
		ctype/ft_isop.c \
		linked_list/ft_lstadd_back.c \
		linked_list/ft_lstclear.c \
		linked_list/ft_lstdelone.c \
		linked_list/ft_lstnew.c \
		linked_list/ft_lstsize.c \
		circular_linked_list/ft_check_integrity_one_node.c \
		circular_linked_list/ft_check_integrity_two_node.c \
		circular_linked_list/ft_clst_size.c \
		circular_linked_list/ft_clstadd_back.c \
		circular_linked_list/ft_clstnew.c \
		arc_utils/ft_free_all_ref.c \
		arc_utils/ft_malloc.c \
		arc_utils/safe_quit_philo.c \
		utils/ft_get_data_addr.c \
		utils/ft_atoi.c \
		utils/ft_get_timestamp.c \
		utils/ft_is_pair.c \
		utils/ft_check_fork_state.c \
		string/ft_strdup_arc.c \
		string/ft_strlen.c \
		memory/ft_memcpy.c \
		memory/ft_memset.c \
		memory/ft_init_struct.c \
		parser/ft_parser.c \
		philo_handler/all_philo_dead_instant.c \
		philo_handler/ft_populate_philo.c \
		philo_handler/is_one_philo_has_died.c \
		philo_handler/ft_get_philo_clist_addr.c \
		philo_handler/ft_create_thread_philo.c \
		philo_handler/ft_join_thread_philo.c \
		philo_handler/ft_get_philo_by_index.c \
		philo_handler/ft_set_estimated_thinking_time.c \
		philo_handler/is_end_of_dinner.c \
		philo_handler/set_launch_timestamp.c \
		philo_handler/check_death_before_action.c \
		philo_handler/ft_take_fork_priority.c \
		philo_handler/drop_mutex_taken.c \
		philo_handler/alone_philo_routine.c \
		philo_handler/set_one_philo_is_death_to_true.c \
		philo_handler/set_timestamp.c \
		philo_printers/ft_eating.c \
		philo_printers/ft_is_died.c \
		philo_printers/ft_sleeping.c \
		philo_printers/ft_taking_fork.c \
		philo_printers/ft_release_fork.c \
		philo_printers/ft_thinking.c \
		philo_handler/ft_get_m_writer.c \
		philo_handler/ft_get_m_death.c \
		fork_handler/ft_create_forks.c \
		fork_handler/ft_destroy_forks.c \
		fork_handler/ft_get_mutex.c \
		fork_handler/ft_get_idleft_from_philo.c \
		fork_handler/ft_get_idright_from_philo.c \
		fork_handler/ft_get_left_fork.c \
		fork_handler/ft_get_right_fork.c \
		mutex_handler/ft_create_all_mutex.c \
		mutex_handler/ft_create_mutex_death.c \
		mutex_handler/ft_create_mutex_lock_check.c \
		mutex_handler/ft_create_mutex_printer.c \
		mutex_handler/ft_destroy_all_mutex.c \
		time_handler/ft_get_pace_die.c \
		time_handler/ft_get_pace_eat.c \
		time_handler/ft_get_pace_sleep.c \
		time_handler/ft_get_pace_est_think.c \
		time_handler/ft_add_timestamp.c
HEADER = 	./philo.h \
			./includes/args_handler.h \
			./includes/clist.h \
			./includes/ctype.h \
			./includes/garbadge.h \
			./includes/linked_list.h \
			./includes/memory.h \
			./includes/mutex_handler.h \
			./includes/string.h \
			./includes/structures.h \
			./includes/utils.h
GIT_TIMESTAMP= "AUTO-COMMIT timestamp : $(shell date) "

all : $(NAME)

$(OBJ) : $(HEADER) Makefile


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)  $(OBJ) -lpthread

%.o:%.c
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

push: fclean
	git add .
	git commit -m $(GIT_TIMESTAMP)
	git push origin master

.PHONY: all re fclean clear