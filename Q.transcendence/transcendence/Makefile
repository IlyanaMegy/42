# # ============================================================================== #
# #                                  COLORS                                        #
# # ============================================================================== #
# # Reset
# RESET		= \033[0m
# # Styles
# BOLD		= \033[1m
# UNDERLINE	= \033[4m
# # Regular Colors
# RED			= \033[0;31m
# GREEN		= \033[0;32m
# YELLOW		= \033[0;33m
# BLUE		= \033[0;34m
# PURPLE		= \033[0;35m
# CYAN		= \033[0;36m
# # Bold Colors
# BRED		= \033[1;31m
# BGREEN		= \033[1;32m
# BYELLOW		= \033[1;33m
# BBLUE		= \033[1;34m
# BPURPLE		= \033[1;35m
# BCYAN		= \033[1;36m

# # ============================================================================== #
# #                                VARIABLES                                       #
# # ============================================================================== #
# NAME			= ft_transcendence
# DEV_COMPOSE		= docker-compose.yml
# PROD_COMPOSE	= docker-compose.prod.yml # Assure-toi que ce fichier existe

# # ============================================================================== #
# #                                  TARGETS                                       #
# # ============================================================================== #
# .PHONY: all build-dev up down build-prod prod stop clean fclean re

# all: up

# # --- Development ---
# up:
# 	@echo "$(BPURPLE)🚀 Starting development environment for $(BOLD)$(NAME)$(RESET)$(BPURPLE)...$(RESET)"
# 	@docker-compose -f $(DEV_COMPOSE) up --build
# 	@echo "$(BGREEN)✅ Development environment is up and running!$(RESET)"

# down:
# 	@echo "$(BYELLOW)🛑 Stopping development containers...$(RESET)"
# 	@docker-compose -f $(DEV_COMPOSE) down
# 	@echo "$(BRED)⏹️ Development environment stopped.$(RESET)"

# # --- Production ---
# prod:
# 	@echo "$(BBLUE)🚀 Launching production environment for $(BOLD)$(NAME)$(RESET)$(BBLUE)...$(RESET)"
# 	@docker-compose -f $(PROD_COMPOSE) up --build -d
# 	@echo "$(BGREEN)✅ Production environment is live!$(RESET)"

# stop:
# 	@echo "$(BYELLOW)🛑 Stopping production containers...$(RESET)"
# 	@docker-compose -f $(PROD_COMPOSE) down
# 	@echo "$(BRED)⏹️ Production environment stopped.$(RESET)"

# # --- Utils ---
# clean:
# 	@echo "$(BRED)🧹 Cleaning up docker...$(RESET)"
# 	@docker system prune -af
# 	@docker volume prune -f
# 	@echo "$(GREEN)✨ Cleanup complete!$(RESET)"

# fclean:
# 	@echo "$(BRED)🔥🔥🔥 FULL CLEAN: Removing all containers, volumes, and images...$(RESET)"
# 	@docker-compose -f $(DEV_COMPOSE) down -v --rmi all --remove-orphans
# 	@docker-compose -f $(PROD_COMPOSE) down -v --rmi all --remove-orphans
# 	@docker system prune -a -f
# 	@echo "$(BGREEN)✅ System fully cleaned!$(RESET)"

# re: fclean all
