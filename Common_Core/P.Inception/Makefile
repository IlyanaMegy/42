LOGIN = ilymegy
COMPOSE = srcs/docker-compose.yml
VOLUMES_PATH = /home/$(LOGIN)/data
DOMAIN = 127.0.0.1 ilymegy.42.fr
LOOKDOMAIN = $(shell grep "${DOMAIN}" /etc/hosts)

export VOLUMES_PATH 

all: srcs/.env hosts build up

update-env:
	sudo apt-get update && sudo apt-get upgrade -y
	sudo apt-get install docker-compose-plugin

list:
	docker ps -a

list-networks:
	docker network ls

list-volumes:
	docker volume ls

up:
	@echo "Starting the containers..."
	docker-compose -f $(COMPOSE) up
	@echo "Containers are running."

build:
	@echo "Building volumes..."
	$(MAKE) create-volumes

create-volumes:
	sudo mkdir -p $(VOLUMES_PATH)/mariadb $(VOLUMES_PATH)/wordpress
	docker-compose -f $(COMPOSE) build

hosts:
	@if ! grep -q "${DOMAIN}" /etc/hosts; then \
		echo "Updating /etc/hosts..."; \
		sudo cp ./srcs/requirements/tools/hosts /etc/hosts; \
	fi

srcs/.env:
	@echo "Missing .env file in srcs folder" && exit 1

logs:
	docker-compose -f $(COMPOSE) logs -f

status:
	docker-compose -f $(COMPOSE) ps

down:
	docker-compose -f $(COMPOSE) down -v
	docker image prune -a -f

clean: down
	docker system prune --all --force --volumes
	sudo rm -rf $(VOLUMES_PATH)/wordpress/* $(VOLUMES_PATH)/mariadb/*
	sudo systemctl restart docker

fclean: clean

re: fclean all
